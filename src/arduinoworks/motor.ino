void run(int speed) {
  // If speed is 0, stop the motor by setting both forward and backward pins to LOW
  if (speed == 0) {
    digitalWrite(mf, 0);  // Turn off forward motor
    digitalWrite(mb, 0);  // Turn off backward motor
  } 
  // If speed is negative, run the motor in reverse
  else if (speed < 0) {
    analogWrite(mf, abs(speed));  // Set the forward motor to a PWM value equivalent to the speed's absolute value
    analogWrite(mb, 0);  // Ensure the backward motor is off
  } 
  // If speed is positive, run the motor forward
  else if (speed > 0) {
    analogWrite(mf, 0);  // Ensure the forward motor is off
    analogWrite(mb, abs(speed));  // Set the backward motor to a PWM value equivalent to the speed's absolute value
  }
}
