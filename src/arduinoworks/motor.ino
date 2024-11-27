void run(int speed) {

  if (speed == 0) {
    digitalWrite(mf, 0);      // Turn off the forward motor
    digitalWrite(mb, 0);      // Turn off the backward motor
  }
  // Check if speed is negative (reverse condition)
  else if (speed < 0) {
    digitalWrite(mf, 1); // Set forward motor speed (using absolute value)
    digitalWrite(mb, 0);        // Turn off backward motor
  }
  // Check if speed is positive (forward condition)
  else if (speed > 0) {
    digitalWrite(mf, 0);        // Turn off forward motor
    digitalWrite(mb, 1); // Set backward motor speed (using absolute value)
  }

  ledcWrite(15, int(abs(speed)));
}
