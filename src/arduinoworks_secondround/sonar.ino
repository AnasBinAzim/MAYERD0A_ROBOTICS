void reading() {
  fd = sf.ping_cm();            // Read distance from front sensor in centimeters
  ld = sl.ping_cm();            // Read distance from left sensor in centimeters
  rd = sr.ping_cm();            // Read distance from right sensor in centimeters
//  Ld = s_l.ping_cm();            // Read distance from left sensor in centimeters
//  Rd = s_r.ping_cm();            // Read distance from right sensor in centimeters 

  // Check if left distance is zero (indicating no reading), set to 300 cm
  if (ld == 0) {
    ld = 300;                   // Default distance if no reading is detected
  } else ld = ld;               // No change if reading is valid
//  if (Ld == 0) {
//    Ld = 300;                   // Default distance if no reading is detected
//  } else Ld = Ld;               // No change if reading is valid
//  if (Rd == 0) {
//    Rd = 300;                   // Default distance if no reading is detected
//  } else Rd = Rd;               // No change if reading is valid


  // Check if right distance is zero (indicating no reading), set to 300 cm
  if (rd == 0) {
    rd = 300;                   // Default distance if no reading is detected
  } else rd = rd;               // No change if reading is valid

  // Check if front distance is zero (indicating no reading), set to 300 cm
  if (fd == 0) {
    fd = 300;                   // Default distance if no reading is detected
  } else fd = fd;               // No change if reading is valid
//  rd = min(rd,Rd);
//  ld = max(ld,Ld);
}
void sonar_read() {
  reading();                    // Call the reading function to update distances
  Serial.print(ld);            // Print left distance for debugging
  Serial.print("   ");
  Serial.print(Ld);            // Print left distance for debugging
  Serial.print("   ");
  Serial.print(fd);            // Print front distance for debugging
  Serial.print("   ");
  Serial.print(Rd);            // Print left distance for debugging
  Serial.print("   ");
  Serial.print(rd);            // Print right distance for debugging
  Serial.println("   ");        // Print a newline for better readability
//  delay(500);                  // Wait for half a second before next printing
}
