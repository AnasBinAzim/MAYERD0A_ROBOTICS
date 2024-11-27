void reading() {
  if (millis() - sonar_timer >= 15) {
    fd = getDistS(fp);            // Read distance from front sensor in centimeters
    ld = getDistS(lp);            // Read distance from left sensor in centimeters
    rd = getDistS(rp);            // Read distance from right sensor in centimeters
    sonar_timer = millis();
  }
}

void sonar_read() {
  // Call the reading function to update distances
  reading();
  Serial.print(ld);            // Print left distance for debugging
  Serial.print("   ");
  Serial.print(fd);            // Print front distance for debugging
  Serial.print("   ");
  Serial.print(rd);            // Print right distance for debugging
  Serial.println("   ");        // Print a newline for better readability
  delay(500);                  // Wait for half a second before next printing
}
int getDistS(int te) {
  pinMode(te, OUTPUT);

  digitalWrite(te, LOW);
  delayMicroseconds(2);
  digitalWrite(te, HIGH);
  delayMicroseconds(10);
  digitalWrite(te, LOW);

  pinMode(te, INPUT);

  long dur = pulseIn(te, HIGH, 300 * 60);
  int dst = dur / 58.8;
  if (dst <= 1) dst = 300;
  return (dst);
}
