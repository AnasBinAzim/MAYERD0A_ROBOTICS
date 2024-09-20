int button_read() {
  int cl = 0;                 // Initialize counter for button presses
p:  
  int t = 0;                  // Initialize timer for button hold duration

  // Check if the switch is pressed
  if (digitalRead(sw) == 0) {
    digitalWrite(buz, HIGH);  // Activate buzzer to indicate button press
    while (digitalRead(sw) == 0) { // Wait while the button is pressed
      delay(1);                // Small delay to prevent busy waiting
      t++;                     // Increment timer for duration of press
    }
    digitalWrite(buz, LOW);   // Deactivate buzzer when button is released

    // If button was held long enough, register a press
    if (t > 15) {             
      t = 0;                  // Reset timer
      cl++;                   // Increment button press counter

      // Wait until the button is released
      while (digitalRead(sw) == HIGH) { 
        delay(1);              // Small delay to prevent busy waiting
        t++;                   // Increment timer for release duration
        if (t > 1000) return cl; // If held for too long, return count
      }
      goto p;                 // Go back to the start to check for additional presses
    }
  }
  return cl;                 // Return the count of button presses
}
