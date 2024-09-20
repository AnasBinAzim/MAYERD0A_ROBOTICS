#include <Servo.h>
#include <NewPing.h>

Servo steering;
NewPing sf(11, 12, 300);
NewPing sr(4, 8, 300);
NewPing sl(9, 7, 300);

#define str 10
#define mf 6
#define mb 3
#define buz A2
#define sw A5
#define reset_timer 1800
#define sinit 100
short int fd,ld,rd;
// PID constants
float Kp = 8;  // Proportional gain
float Ki = 0;  // Integral gain
float Kd = 1.5;  // Derivative gain
// Desired distance from the wall
const int desiredDistance = 40;  // cm
// Variables for PID control
float previousError = 0, integral = 0;
unsigned long s_timer = 0;


void setup() {
  Serial.begin(9600);
  steering.attach(str);
  steering.write(sinit);
  pinMode(mf, OUTPUT); // motor forward pin as output
  pinMode(mb, OUTPUT); // motor backward pin as output
  pinMode(buz, OUTPUT); // motor forward pin as output
  pinMode(sw, INPUT_PULLUP); // switch pin as input
}

void loop() {
  int r = button_read();
  if(r == 1){
    first();
  }
  if(r == 2){
    while(1){
    sonar_read();
    if(digitalRead(sw) == 0)break;
    }

  }

}
