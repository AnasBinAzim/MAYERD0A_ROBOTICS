void first() {
  turn = 0;                    // Reset turn counter to zero
  timer = 0;                   // Reset timer to zero
  should_stop = 0;            // Initialize stop flag (boolean) to false
  stop_timer = 0;             // Reset stop timer to zero
  orientation_check = 0;      // Initialize orientation check to false
  // float temp_kp = Kp;      // Uncommented line to save original Kp value

  while (1) {                  // Start an infinite loop for continuous operation
    if (!orientation_check) {  // Check if orientation is not yet confirmed
      // Kp = 2;               // Uncommented line to set Kp for orientation adjustment

      while (!orientation_check) { // Loop until orientation is confirmed
        linecheck();           // Check for line detection
        reading();            // Read sensor values

        // Check if the right distance sensor detects an object and the front is clear
        if (rd > 200 && fd < 120) { 
          left = 0;           // Set left turn flag to false
          orientation_check = 1; // Confirm orientation
        } else if (ld > 200 && fd < 120) { // Check for left detection
          left = 1;           // Set left turn flag to true
          orientation_check = 1; // Confirm orientation
        }

        float error = (rd - ld); // Calculate error based on right and left distance
        integral += error;       // Accumulate error for the integral term

        // Calculate PID correction
        float correction = Kp * error + Ki * integral + Kd * (error - previousError);
        Serial.print(correction); // Print correction value for debugging
        Serial.print("  ");       // Print space for readability

        // Map correction to steering angle (-90 to 90 degrees)
        int steeringAngle = map(correction, 130, -130, 45, 155); // Map to servo angle range
        steeringAngle = constrain(steeringAngle, 45, 155); // Ensure angle is within limits

        steering.write(steeringAngle); // Set servo to the calculated steering angle

        // Update motor speed based on correction magnitude
        float baseSpeed = map(abs(correction), 0, 50, 200, 120); // Map speed based on correction
        baseSpeed = constrain(baseSpeed, 120, 200); // Ensure speed is within bounds
        Serial.println(steeringAngle); // Print steering angle for debugging

        run(baseSpeed);               // Set motor speed
        previousError = error;       // Store current error for next iteration
      }
    }

    // Kp = temp_kp;                 // Uncommented line to restore original Kp value

    if (left) {                    // Check if left turn flag is set
      while (1) {                  // Start infinite loop for left turning behavior
        reading();                 // Read sensor values
        linecheck();               // Check for line detection

        // Check if stopping condition is met and turn counter exceeds threshold
        if (!should_stop && turn >= 12) {
          if (!should_stop) {       // If not already in stop condition
            should_stop = 1;      // Set stop flag
            stop_timer = millis(); // Record the time when stopping started
          }
        } else if (should_stop && millis() - stop_timer > 700) { // Check if stop time has exceeded 700 ms
          steering.write(sinit);   // Return steering to initial position
          run(0);                  // Stop motor
          digitalWrite(buz, 0);    // Turn off buzzer
          break;                   // Exit the loop
        }

        float error = (30 - ld);  // Calculate error based on desired left distance
        integral += error;        // Accumulate error for the integral term

        // Calculate PID correction
        float correction = Kp * error + Ki * integral + Kd * (error - previousError);
        Serial.print(correction);  // Print correction value for debugging
        Serial.print("  ");        // Print space for readability

        // Map correction to steering angle
        int steeringAngle = map(correction, 130, -130, 45, 155); // Map to servo angle range
        steeringAngle = constrain(steeringAngle, 45, 155); // Ensure angle is within limits

        steering.write(steeringAngle); // Set servo to the calculated steering angle

        // Update motor speed based on correction magnitude
        float baseSpeed = map(abs(correction), 0, 50, 200, 120); // Map speed based on correction
        baseSpeed = constrain(baseSpeed, 120, 200); // Ensure speed is within bounds
        Serial.println(steeringAngle); // Print steering angle for debugging

        run(baseSpeed);               // Set motor speed
        previousError = error;       // Store current error for next iteration
      }
    } else if (!left) {            // If left flag is not set (i.e., going straight or right)
      while (1) {                  // Start infinite loop for right turning behavior
        reading();                 // Read sensor values
        linecheck();               // Check for line detection

        // Check if stopping condition is met and turn counter exceeds threshold
        if (!should_stop && turn >= 12) {
          if (!should_stop) {       // If not already in stop condition
            should_stop = 1;      // Set stop flag
            stop_timer = millis(); // Record the time when stopping started
          }
        } else if (should_stop && millis() - stop_timer > 700) { // Check if stop time has exceeded 700 ms
          steering.write(sinit);   // Return steering to initial position
          run(0);                  // Stop motor
          digitalWrite(buz, 0);    // Turn off buzzer
          break;                   // Exit the loop
        }

        float error = (30 - rd);  // Calculate error based on desired right distance
        integral += error;        // Accumulate error for the integral term

        // Calculate PID correction
        float correction = Kp * error + Ki * integral + Kd * (error - previousError);
        Serial.print(correction);  // Print correction value for debugging
        Serial.print("  ");        // Print space for readability

        // Map correction to steering angle
        int steeringAngle = map(correction, -130, 130, 45, 155); // Map to servo angle range
        steeringAngle = constrain(steeringAngle, 45, 155); // Ensure angle is within limits

        steering.write(steeringAngle); // Set servo to the calculated steering angle

        // Update motor speed based on correction magnitude
        float baseSpeed = map(abs(correction), 0, 50, 200, 120); // Map speed based on correction
        baseSpeed = constrain(baseSpeed, 120, 200); // Ensure speed is within bounds
        Serial.println(steeringAngle); // Print steering angle for debugging

        run(baseSpeed);               // Set motor speed
        previousError = error;       // Store current error for next iteration
      }
    }
  }
}

void linecheck() {
  srl();                        // Check for serial input (function definition not provided)

  unsigned long currentMillis = millis(); // Get current time in milliseconds

  // Check if line is detected and timer condition is met
  if (!line_dect && (currentMillis - timer) > 750) {
    line_dect = 1;              // Reset line detection status to true
    digitalWrite(buz, LOW);     // Turn off buzzer
  } else if (!line_dect) {
    return;                     // Exit if line not detected
  }

  // If front distance is less than 160 cm and object detected, increment turn counter
  if (fd <= 160 && obj >= 3) {
    turn++;                     // Increment turn counter
    digitalWrite(buz, HIGH);   // Activate buzzer
    line_dect = 0;             // Reset line detection status
    timer = currentMillis;      // Update timer to current time
  }
}

