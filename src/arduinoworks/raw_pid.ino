#include <Servo.h>  // Includes the Servo library for controlling servo motors
#include <NewPing.h>  // Includes the NewPing library for ultrasonic sensors

// Declare a Servo object named 'steering'
Servo steering;  

// Create NewPing objects for front, right, and left ultrasonic sensors with their trigger, echo pins and max distance
NewPing sf(11, 12, 300);  // Front sensor, trigger pin 11, echo pin 12, max distance 300 cm
NewPing sr(4, 8, 300);  // Right sensor, trigger pin 4, echo pin 8, max distance 300 cm
NewPing sl(9, 7, 300);  // Left sensor, trigger pin 9, echo pin 7, max distance 300 cm

// Define constants for pins and control variables
#define str 10  // Pin for controlling steering servo
#define mf 6  // Pin for motor forward control
#define mb 3  // Pin for motor backward control
#define buz A2  // Pin for buzzer
#define sw A5  // Pin for switch
#define reset_timer 1800  // Reset timer value in milliseconds
#define sinit 100  // Initial steering position
short int fd, ld, rd;  // Short integer variables for storing distances (front, left, right)

// PID control constants for adjusting steering
float Kp = 8;  // Proportional gain
float Ki = 0;  // Integral gain
float Kd = 1.5;  // Derivative gain

// Desired distance from the wall in cm for PID control
const int desiredDistance = 40;  // Set target distance to maintain from obstacles (in cm)

// Variables for PID control loop
float previousError = 0, integral = 0;  // Previous error and integral value for PID calculations
unsigned long s_timer = 0;  // Timer variable to keep track of time intervals

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate for debugging
  steering.attach(str);  // Attach servo motor to 'str' pin
  steering.write(sinit);  // Set servo to initial position (100 degrees)
  pinMode(mf, OUTPUT);  // Set motor forward pin as output
  pinMode(mb, OUTPUT);  // Set motor backward pin as output
  pinMode(buz, OUTPUT);  // Set buzzer pin as output
  pinMode(sw, INPUT_PULLUP);  // Set switch pin as input with pull-up resistor
}

void loop() {
  int r = button_read();  // Read the button state (assumed to be from a function called button_read)

  if(r == 1) {
    first();  // If button_read returns 1, execute the first() function
  }

  if(r == 2) {
    while(1) {  // If button_read returns 2, enter an infinite loop
      sonar_read();  // Read distance values from ultrasonic sensors (assumed function sonar_read)
      if(digitalRead(sw) == 0) break;  // If switch is pressed (read as LOW), break the loop
    }
  }
}

