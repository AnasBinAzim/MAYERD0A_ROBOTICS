void run(int speed) {
  // Check if speed is 0 (stop condition)
  if (speed == 0) {
    digitalWrite(mf, 0);      // Turn off the forward motor
    digitalWrite(mb, 0);      // Turn off the backward motor
  } 
  // Check if speed is negative (reverse condition)
  else if (speed < 0) {
    analogWrite(mf, abs(speed)); // Set forward motor speed (using absolute value)
    analogWrite(mb, 0);        // Turn off backward motor
  } 
  // Check if speed is positive (forward condition)
  else if (speed > 0) {
    analogWrite(mf, 0);        // Turn off forward motor
    analogWrite(mb, abs(speed)); // Set backward motor speed (using absolute value)
  }
}
