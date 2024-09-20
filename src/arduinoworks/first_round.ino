void first() {
  while(1) {  // Enter an infinite loop to continuously perform PID control and motor adjustments
    // Check if more than 3 milliseconds have passed since the last sensor reading
    if(millis() - s_timer > 3) 
      reading();  // Update sensor readings

    // Calculate the error as the difference between the desired distance and the left sensor's distance
    float error = desiredDistance - ld;  

    // Accumulate the error over time for the integral term in PID control
    integral += error;

    // Calculate the correction using the PID formula
    float correction = Kp * error + Ki * integral + Kd * (error - previousError);

    // Print the correction value for debugging purposes
    Serial.print(correction);
    Serial.print("  ");

    // Map the correction value to a servo angle for steering (-90 to 90 degrees)
    int steeringAngle = map(correction, 60, -60, 50, 50);  // Convert correction into a steering angle within the range
    steeringAngle = constrain(steeringAngle, 50, 150);  // Ensure the angle stays within the servo's physical limits

    // Write the calculated steering angle to the servo
    steering.write(steeringAngle);

    // Calculate the motor speed based on the correction (larger corrections slow down the motor)
    float baseSpeed = map(abs(correction), 0, 50, 180, 120);  // Map correction to base speed (adjustable)
    baseSpeed = constrain(baseSpeed, 120, 180);  // Constrain the speed between 120 and 180

    // Print the steering angle for debugging
    Serial.println(steeringAngle);

    // Run the motor at the calculated base speed
    run(baseSpeed);

    // Update the previous error for the next iteration
    previousError = error;
  }
}
