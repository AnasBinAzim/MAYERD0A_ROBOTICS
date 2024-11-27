int button_read() {
  int cl = 0;  // Initialize click count
p:
  int t = 0;  // Timer variable

  // Check if the switch is pressed
  if (digitalRead(sw) == 0) {
    digitalWrite(buz, HIGH);  // Turn on the buzzer
    while (digitalRead(sw) == 0) {  // Wait while the switch is pressed
      delay(1);  // Delay to debounce
      t++;  // Increment timer
    }
    digitalWrite(buz, LOW);  // Turn off the buzzer

    // If the button was held for more than 15 ms
    if (t > 15) {
      t = 0;  // Reset timer
      cl++;  // Increment click count

      // Wait until the button is released
      while (digitalRead(sw) == HIGH) {
        delay(1);  // Delay to debounce
        t++;  // Increment timer
        if (t > 500) return cl;  // If held long enough, return the click count
      }
      goto p;  // Repeat the process
    }
  }
  return cl;  // Return the click count
}

}
