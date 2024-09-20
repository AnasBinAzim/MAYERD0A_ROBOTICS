void first() {
  turn = 0;                    // Reset turn counter
  timer = 0;                   // Reset timer
  should_stop = 0;            // bool to indicate if stopping is needed
  stop_timer = 0;             // Reset stop timer

  while (1) {                  // Infinite loop for continuous operation
    reading();                 // Read sensor values or state
    linecheck();              // Check for line detection

    // Check if stopping condition is met and turn counter exceeds threshold
    if(!should_stop && turn >= 12) {
      if(!should_stop) {       // If not already in stop condition
        should_stop = 1;      // Set stop flag
        stop_timer = millis(); // Record the time when stopping started
      }
    } else if(should_stop && millis() - stop_timer > 3000) {
      steering.write(sinit);   // Return steering to initial position
      run(0);                  // Stop motor
      digitalWrite(buz, 0);    // Turn off buzzer
      break;                   // Exit the loop
    }

    float error = (30 - ld);  // Calculate error based on desired distance
    integral += error;        // Accumulate error for the integral term

    // Calculate PID correction
    float correction = Kp * error + Ki * integral + Kd * (error - previousError);
    Serial.print(correction);  // Print correction value for debugging
    Serial.print("  ");

    // Map correction to servo angle (-90 to 90 degrees for steering)
    int steeringAngle = map(correction, 130, -130, 45, 155); // Adjust range for responsiveness
    steeringAngle = constrain(steeringAngle, 45, 155);      // Constrain angle within servo limits

    steering.write(steeringAngle); // Set steering angle based on correction

    // Update motor speed based on the correction
    float baseSpeed = map(abs(correction), 0, 50, 200, 120); // Adjust base speed based on correction magnitude
    baseSpeed = constrain(baseSpeed, 120, 200);             // Ensure speed is within bounds
    Serial.println(steeringAngle); // Print steering angle for debugging

    run(baseSpeed);               // Set motor speed
    previousError = error;       // Store current error for next iteration
  }
}

void linecheck() {
  srl();                        // Check serial input (function definition not provided)

  unsigned long currentMillis = millis(); // Get current time in milliseconds

  // Check if line is detected and timer condition is met
  if (!line_dect && (currentMillis - timer) > 700) {
    line_dect = 1;              // Reset line detection status
    digitalWrite(buz, LOW);     // Turn off buzzer
  } else if (!line_dect) {
    return;                     // Exit if line not detected
  }

  // If front distance is less than 160 cm and object detected, increment turn counter
  if (fd <= 160 && obj >= 3) {
    turn++;                     // Increment turn counter
    digitalWrite(buz, HIGH);   // Activate buzzer
    line_dect = 0;             // Set line detection to false
    timer = currentMillis;      // Update timer to current time
  }
}
