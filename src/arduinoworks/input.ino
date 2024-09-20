int button_read() {
  int cl = 0;  // Initialize 'cl' (click count) to 0
p:  
  int t = 0;  // Initialize 't' (time counter) to 0

  // Check if the switch is pressed (switch reads LOW when pressed)
  if (digitalRead(sw) == 0) {
    digitalWrite(buz, HIGH);  // Turn on the buzzer when the switch is pressed

    // Stay in this loop while the switch is pressed
    while (digitalRead(sw) == 0) {
      delay(1);  // Wait for 1 millisecond
      t++;  // Increment the time counter for how long the switch is held down
    }
    
    digitalWrite(buz, LOW);  // Turn off the buzzer when the switch is released

    // If the button was pressed for more than 15 milliseconds
    if (t > 15) {
      t = 0;  // Reset the time counter
      cl++;  // Increment the click count

      // Wait until the switch is pressed again (switch reads HIGH when released)
      while (digitalRead(sw) == HIGH) {
        delay(1);  // Wait for 1 millisecond
        t++;  // Increment the time counter to measure how long the switch is unpressed

        // If the switch has been unpressed for more than 1000 milliseconds (1 second)
        if (t > 1000) {
          return cl;  // Return the current click count
        }
      }

      // If the switch is pressed again before 1000 milliseconds, jump back to label 'p'
      goto p;  
    }
  }

  // Return the final click count if no further actions occur
  return cl;
}
