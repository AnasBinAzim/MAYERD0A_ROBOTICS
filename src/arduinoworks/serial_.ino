void srl() {
  // Non-blocking Serial check
  while (Serial.available() > 0) { // Loop until all serial data is read
    int_it = Serial.read();        // Read a byte from the serial buffer
    obj = int_it - '0';            // Convert ASCII character to integer (assuming single digit)
  }
}
