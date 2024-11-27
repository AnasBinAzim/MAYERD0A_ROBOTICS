#include <ESP32Servo.h>
#include <Arduino.h>
// Definitions
#define str 32
#define mf 27
#define mb 26
#define ms 14
#define buz 13
#define sw 4
#define ENCODER_PIN_A 34
#define ENCODER_PIN_B 35
#define fp 25
#define rp 23
#define lp 33
#define reset_timer 1800
#define sinit 95
#define led 15
unsigned long mun_tmr = 0;
bool tadd = 0;
bool srll = 0;
bool ut = 0;
bool f1 = 0, f2 = 0;
float x_pos = 0, y_pos = 0;
unsigned long lastPosTmr;
volatile long lastEnc = 0;

// Servo and Motor Control
Servo steering;

float total_angle = 0, initial_angle = 0, last_angle = 0, angle = 0, current_should_angle = 0, target_angle = 0;;
// Encoder-related Variables
volatile long encoderCount = 0;
volatile long lastencoderCount = 0;
volatile int lastStateA;

// PID Control Parameters
float Kp = 3;
float Ki = 0;
float Kd = 0.2;
float previousError = 0;
float integral = 0;
int steeringAngle;
float correction;
float error;

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
bool line_dect = 1;
bool should_stop = 0;
bool orientation_check = 0;
bool millis_count = 0;
bool left = 0;
int is_obj = 0;
int objstr = 100;
int laststr = 0;
int turn = 0;
int new_srl = 0;
int steering_table[42];
// Flags and States
bool gpass = 0;
bool rpass = 0;
unsigned long m1;

short int fd, ld, rd;
char int_it;

int return_timer = 0;

int max_possible_str = 35;

TaskHandle_t handleSensor;

// Interrupt Service Routine for Encoder
void IRAM_ATTR handleEncoderA() {
  int stateA = digitalRead(ENCODER_PIN_A);
  int stateB = digitalRead(ENCODER_PIN_B);

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
  lastStateA = stateA;
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  ledcSetup(15, 1000, 8);
  ledcAttachPin(14, 15);
  ledcWrite(15, 255);
  //  ESP32PWM::allocateTimer(5);
  //  ESP32PWM::allocateTimer(6);
  //  ESP32PWM::allocateTimer(7);
  //  ESP32PWM::allocateTimer(8);
  //  steering.setPeriodHertz(50);
  steering.attach(str, 500, 2500);
  steering.write(sinit);
  xTaskCreatePinnedToCore(dualcore, "secondJob", 4096, NULL, 1, &handleSensor, 0);
  lastStateA = digitalRead(ENCODER_PIN_A);
  steering_table[20]  = 95;
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
  tnc  = 0;
  for (int i = 21; i <= 40; i++) {
    tnc += 1;
    vla = tnc * pt;
    if (vla - floor(vla) > 0.5)
      vla = floor(vla) + 1;
    steering_table[i] = steering_table[20] + vla;
  }
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(mf, OUTPUT);
  pinMode(mb, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial2.flush();
}

void loop() {
  int r = button_read();
  if (r == 1) {
    nd();
  } else if (r == 2) {
    while (1) {
      sonar_read();
      if (digitalRead(sw) == 0)
        break;
    }
  } else if (r == 3) {
    go(100, 160);
  }
}
void dualcore(void * param) {
  //  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), handleEncoderA, CHANGE);
  while (true) {
    delay(2);
    srl();
    srl2();
  }
}

void go(int dis, int spd) {
  int turo = dis * 25;
  encoderCount = 0;
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), handleEncoderA, CHANGE);
  
  while (abs(encoderCount) < turo) {
    run(spd);

  }
  run(-150);
  delay(50);
  run(0);
  detachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A));
}
