#include <ESP32Servo.h>  // Library for controlling servos on the ESP32
#include <Arduino.h>  // Main Arduino library

// Definitions
#define str 32  // Pin for steering servo
#define mf 27  // Pin for motor forward
#define mb 26  // Pin for motor backward
#define ms 14  // Pin for motor speed control
#define buz 13  // Pin for buzzer
#define sw 4  // Pin for switch input
#define ENCODER_PIN_A 34  // Pin for encoder A channel
#define ENCODER_PIN_B 35  // Pin for encoder B channel
#define fp 25  // Pin for forward proximity sensor
#define rp 23  // Pin for right proximity sensor
#define lp 33  // Pin for left proximity sensor
#define reset_timer 1800  // Timer reset value
#define sinit 95  // Initial steering position
#define led 15  // Pin for LED

// Variables for timers and control flags
unsigned long mun_tmr = 0;
bool tadd = 0;
bool srll = 0;
bool ut = 0;
bool f1 = 0, f2 = 0;
float x_pos = 0, y_pos = 0;
unsigned long lastPosTmr;
volatile long lastEnc = 0;

// Servo and Motor Control
Servo steering;  // Servo object for steering control

float total_angle = 0, initial_angle = 0, last_angle = 0, angle = 0, current_should_angle = 0, target_angle = 0;

// Encoder-related Variables
volatile long encoderCount = 0;  // Counter for encoder pulses
volatile long lastencoderCount = 0;
volatile int lastStateA;

// PID Control Parameters
float Kp = 3;  // Proportional gain
float Ki = 0;  // Integral gain
float Kd = 0.2;  // Derivative gain
float previousError = 0;  // Previous error for PID calculation
float integral = 0;  // Integral term for PID
int steeringAngle;  // Calculated steering angle
float correction;  // Correction value from PID
float error;  // Error value for PID control

// Timers and Delays
unsigned long s_timer = 0;
unsigned long timer = 0;
unsigned long stop_timer = 0;
unsigned long srl_timer = 0;
unsigned long orientation_timer = 0;
unsigned long wait_timer = 0;
unsigned long sonar_timer = 0;
unsigned long srlt_timer = 0;

// Line and Object Detection
int obj;
bool line_dect = 1;  // Line detection flag
bool should_stop = 0;  // Flag to indicate stopping
bool orientation_check = 0;
bool millis_count = 0;
bool left = 0;
int is_obj = 0;
int objstr = 100;
int laststr = 0;
int turn = 0;
int new_srl = 0;
int steering_table[42];  // Array to store steering values

// Flags and States
bool gpass = 0;
bool rpass = 0;
unsigned long m1;

short int fd, ld, rd;  // Distance measurements from sensors
char int_it;

int return_timer = 0;
int max_possible_str = 35;

TaskHandle_t handleSensor;  // Task handle for dual-core processing

// Interrupt Service Routine for Encoder
void IRAM_ATTR handleEncoderA() {
  int stateA = digitalRead(ENCODER_PIN_A);  // Read the current state of encoder pin A
  int stateB = digitalRead(ENCODER_PIN_B);  // Read the current state of encoder pin B

  // Update encoder count based on the states of encoder pins A and B
  if (stateA != lastStateA) {
    if (stateA == HIGH) {
      if (stateB == LOW) {
        encoderCount++;
      } else {
        encoderCount--;
      }
    } else {
      if (stateB == HIGH) {
        encoderCount++;
      } else {
        encoderCount--;
      }
    }
  }
  lastStateA = stateA;  // Update last state of pin A
}

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate
  Serial2.begin(115200);  // Initialize Serial2 for additional communication
  ledcSetup(15, 1000, 8);  // Setup LED control channel
  ledcAttachPin(14, 15);  // Attach motor speed pin to channel
  ledcWrite(15, 255);  // Set initial motor speed

  steering.attach(str, 500, 2500);  // Attach steering servo to pin and set pulse width range
  steering.write(sinit);  // Set steering to initial position

  xTaskCreatePinnedToCore(dualcore, "secondJob", 4096, NULL, 1, &handleSensor, 0);  // Create a task on the second core

  lastStateA = digitalRead(ENCODER_PIN_A);  // Read the initial state of encoder pin A

  // Initialize steering table values
  steering_table[20] = 95;
  double pt = 7.0 / 4.0;
  double tnc = 0;
  double vla;
  for (int i = 19; i >= 0; i--) {
    tnc += 1;
    vla = tnc * pt;
    if (vla - floor(vla) > 0.5)
      vla = floor(vla) + 1;
    steering_table[i] = steering_table[20] - vla;
  }
  tnc = 0;
  for (int i = 21; i <= 40; i++) {
    tnc += 1;
    vla = tnc * pt;
    if (vla - floor(vla) > 0.5)
      vla = floor(vla) + 1;
    steering_table[i] = steering_table[20] + vla;
  }

  // Set pin modes for encoder, motor, and other components
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(mf, OUTPUT);
  pinMode(mb, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  Serial2.flush();  // Clear Serial2 buffer
}

void loop() {
  int r = button_read();  // Read button state
  if (r == 1) {
    nd();  // Call nd function if button state is 1
  } else if (r == 2) {
    while (1) {
      sonar_read();  // Continuously read sonar sensor
      if (digitalRead(sw) == 0)  // Exit loop if switch is pressed
        break;
    }
  } else if (r == 3) {
    go(100, 160);  // Call go function with distance and speed parameters
  }
}

void dualcore(void * param) {
  // Task to be run on the second core
  while (true) {
    delay(2);  // Delay to prevent high CPU usage
    srl();  // Call srl function
    srl2();  // Call srl2 function
  }
}

void go(int dis, int spd) {
  int turo = dis * 25;  // Calculate target encoder count based on distance
  encoderCount = 0;  // Reset encoder count
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), handleEncoderA, CHANGE);  // Attach interrupt for encoder

  while (abs(encoderCount) < turo) {
    run(spd);  // Run motor at specified speed
  }
  run(-150);  // Reverse motor briefly to stop
  delay(50);  // Short delay
  run(0);  // Stop motor
  detachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A));  // Detach encoder interrupt
}  // End of go function


