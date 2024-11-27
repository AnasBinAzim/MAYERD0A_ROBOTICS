
void calcPos() {
  // Calculate the position of the robot based on encoder readings
  if (millis() - lastPosTmr > 30) {  // Check if 30 ms have passed since the last position update
    long encDiff = encoderCount - lastEnc;  // Calculate the difference in encoder counts
    float linear = encDiff / 25.0;  // Convert encoder difference to linear distance
    float dx = linear * cos(angle);  // Calculate change in x-position
    float dy = linear * sin(angle);  // Calculate change in y-position

    x_pos += dx;  // Update x-position
    y_pos += dy;  // Update y-position

    lastEnc = encoderCount;  // Update last encoder count
    lastPosTmr = millis();  // Update the last position timer

    // Print the current position over serial
    Serial.print("$");
    Serial.print(int(x_pos));
    Serial.print(",");
    Serial.println(int(y_pos));
  }
}
