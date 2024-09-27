#include <Servo.h>                // Include Servo library for controlling servo motors
#include <NewPing.h>             // Include NewPing library for ultrasonic distance sensing
#include <Arduino.h>             // Include Arduino core library

Servo steering;                  // Create a Servo object for steering control

// Initialize NewPing objects for ultrasonic sensors with specified trigger and echo pins
NewPing sf(11, 12, 300);        // Front sensor (trigger pin: 11, echo pin: 12, max distance: 300 cm)
NewPing sr(4, 8, 300);          // Right sensor (trigger pin: 4, echo pin: 8, max distance: 300 cm)
NewPing sl(9, 7, 300);          // Left sensor (trigger pin: 9, echo pin: 7, max distance: 300 cm)
NewPing s_r(2, 2, 300);          // Right sensor (trigger pin: 4, echo pin: 8, max distance: 300 cm)
NewPing s_l(5, 5, 300);          // Left sensor (trigger pin: 9, echo pin: 7, max distance: 300 cm)

// Define pin constants
#define str 10                   // Steering control pin
#define mf 3                    // Motor forward pin
#define mb 6                   // Motor backward pin
#define buz A2                  // Buzzer pin
#define sw A5                   // Switch pin
#define led 13
#define reset_timer 1800       // Timer reset value (in milliseconds)
#define sinit 100              // Initial position for steering

short int fd, ld, rd,Rd,Ld;           // Variables to hold distance readings from front, left, and right sensors

// PID constants for control algorithm
float Kp = 3;                 // Proportional gain
float Ki = 0;                   // Integral gain
float Kd = 0;                   // Derivative gain

// Desired distance from the wall
const int desiredDistance = 30;  // Target distance in centimeters

// Variables for PID control
float previousError = 0;        // Store previous error for PID calculations
float integral = 0;             // Integral component for PID control
unsigned long s_timer = 0;      // Timer for sampling or control timing
char int_it;                    // Character variable, purpose unclear from context
int obj;                        // Variable for object detection, purpose unclear
bool line_dect = 1;             // Line detection status (1 for true)
unsigned long timer = 0;        // General timer variable
int turn = 0;                   // Variable to determine turn direction
bool should_stop = 0;           // Flag to indicate if stopping is needed
unsigned long stop_timer = 0;   // Timer for stop functionality
unsigned long srl_timer = 0;
bool orientation_check = 0;
bool millis_count = 0;
unsigned long orientation_timer = 0;
bool left =0;
int is_obj = 0;
unsigned long wait_timer = 0;
int return_timer = 0;
int objstr = 100;
int laststr = 0;

void setup() {
  Serial.begin(9600);           // Initialize serial communication at 9600 baud rate
  steering.attach(str);         // Attach the servo control to the defined pin
  steering.write(sinit);        // Set the servo to the initial position
  pinMode(mf, OUTPUT);          // Set motor forward pin as output
  pinMode(mb, OUTPUT);          // Set motor backward pin as output
  pinMode(buz, OUTPUT);         // Set buzzer pin as output
  pinMode(led, OUTPUT);         // Set buzzer pin as output
  pinMode(sw, INPUT_PULLUP);    // Set switch pin as input with pull-up resistor
}

void loop() {
//  srl();
  int r = button_read();         // Read the button state using a custom function
  if(r == 1) {                   // If button state indicates first action
    first();                     // Call the first function
  }
  else if(r == 2) {                   // If button state indicates second action
    while(1) {                  // Enter an infinite loop
      sonar_read();              // Read distance from sonar sensors
      if(digitalRead(sw) == 0)   // Check if switch is pressed
        break;                   // Exit the loop if switch is pressed
    }
  }
}
