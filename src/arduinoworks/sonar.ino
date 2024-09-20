void reading() {
  // Read the distance from the front sensor in cm
  fd = sf.ping_cm();  

  // Read the distance from the left sensor in cm
  ld = sl.ping_cm();  

  // Read the distance from the right sensor in cm
  rd = sr.ping_cm();  

  // If left sensor reads 0 (out of range), set the distance to 300 cm (max distance)
  if (ld == 0) {
    ld = 300;
  } else ld = ld;  // Otherwise, keep the read value

  // If right sensor reads 0 (out of range), set the distance to 300 cm
  if (rd == 0) {
    rd = 300;
  } else rd = rd;  // Otherwise, keep the read value

  // If front sensor reads 0 (out of range), set the distance to 300 cm
  if (fd == 0) {
    fd = 300;
  } else fd = fd;  // Otherwise, keep the read value

  // Record the current time in milliseconds for timing purposes
  s_timer = millis();
}

void sonar_read() {
  reading();  // Call the reading() function to get sensor distances

  // Print the left, front, and right distances to the serial monitor
  Serial.print(ld);  
  Serial.print("   ");  // Print spaces for readability
  Serial.print(fd);
  Serial.print("   ");
  Serial.print(rd);
  Serial.println("   ");  // End the line

  // Wait for 500 milliseconds before the next reading
  delay(500);
}
