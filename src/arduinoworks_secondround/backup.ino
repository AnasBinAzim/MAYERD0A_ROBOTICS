//bool line_done = 0;
//unsigned long turn_millis = 0;
//void first() {
//  turn = 0;         // Reset turn counter
//  timer = 0;        // Reset timer
//  should_stop = 0;  // bool to indicate if stopping is needed
//  stop_timer = 0;   // Reset stop timer
//  orientation_check = 0;
//  orientation_timer = 0;
//  obj = 0;
//
//  while (1) {
//    while (!orientation_check) {
//      linecheck();
//      reading();
//      if (!should_stop && turn >= 12) {
//        if (!should_stop) {      
//          should_stop = 1;        
//          stop_timer = millis(); 
//        }
//      } else if (should_stop && millis() - stop_timer > 700) {
//        steering.write(sinit);  // Return steering to initial position
//        run(0);                 // Stop motor
//        digitalWrite(buz, 0);   // Turn off buzzer
//        break;                  // Exit the loop
//      }
//      float error = (rd - ld);  // Calculate error based on desired distance
//      integral += error;        // Accumulate error for the integral term
//
//      // Calculate PID correction
//      float correction = Kp * error + Ki * integral + Kd * (error - previousError);
//      //    Serial.print(correction);  // Print correction value for debugging
//      //    Serial.print("  ");
//
//      // Map correction to servo angle (-90 to 90 degrees for steering)
//      int steeringAngle = map(correction, 60, -60, 55, 145);  // Adjust range for responsiveness
//      if (objstr != 100) steeringAngle = objstr;
//      else if (objstr = 100) steeringAngle = steeringAngle;
//      steeringAngle = constrain(steeringAngle, 55, 145);  // Constrain angle within servo limits
//
//      steering.write(steeringAngle);  // Set steering angle based on correction
//
//      // Update motor speed based on the correction
//      float baseSpeed = map(abs(correction), 0, 50, 80, 80);  // Adjust base speed based on correction magnitude
//      if (objstr != 100) {
//        baseSpeed = 50;
//      } else if (objstr = 100) baseSpeed = baseSpeed;
//      baseSpeed = constrain(baseSpeed, 80, 80);  // Ensure speed is within bounds
//
//      run(baseSpeed);         // Set motor speed
//      previousError = error;  // Store current error for next iteration
//    }
//    if (left) {
//      while (1) {
//      
//        linecheck();
//        reading();
//        if (!should_stop && turn >= 12) {
//          if (!should_stop) {       // If not already in stop condition
//            should_stop = 1;        // Set stop flag
//            stop_timer = millis();  // Record the time when stopping started
//          }
//        } else if (should_stop && millis() - stop_timer > 700) {
//          steering.write(sinit);  // Return steering to initial position
//          run(0);                 // Stop motor
//          digitalWrite(buz, 0);   // Turn off buzzer
//          break;                  // Exit the loop
//        }
//        if (fd > 60) {
//          float error = (45 - rd);  // Calculate error based on desired distance
//          integral += error;        // Accumulate error for the integral term
//
//          // Calculate PID correction
//          float correction = Kp * error + Ki * integral + Kd * (error - previousError);
//          //    Serial.print(correction);  // Print correction value for debugging
//          //    Serial.print("  ");
//
//          // Map correction to servo angle (-90 to 90 degrees for steering)
//          int steeringAngle = map(correction, -120, 120, 55, 145);  // Adjust range for responsiveness
//          if (objstr != 100) steeringAngle = objstr;
//          else if (objstr = 100) steeringAngle = steeringAngle;
//          steeringAngle = constrain(steeringAngle, 55, 145);  // Constrain angle within servo limits
//
//          steering.write(steeringAngle);  // Set steering angle based on correction
//
//          // Update motor speed based on the correction
//          float baseSpeed = map(abs(correction), 0, 50, 80, 80);  // Adjust base speed based on correction magnitude
//          if (objstr != 100) {
//            baseSpeed = 50;
//          } else if (objstr = 100) baseSpeed = baseSpeed;
//          baseSpeed = constrain(baseSpeed, 80, 80);  // Ensure speed is within bounds
//                                                     //    Serial.println(steeringAngle);                            // Print steering angle for debugging
//
//          run(baseSpeed);         // Set motor speed
//          previousError = error;  // Store current error for next iteration
//        } else if (fd < 60 && line_done && objstr == 100) {
//          turn_millis = millis();
//          while ((millis() - turn_millis < 1000)&& objstr == 100 || line_done) {
//            steering.write(140);
//            run(50);
//            if ((millis() - turn_millis > 970) || objstr != 100) {
//              line_done = 0;
//            }
//          }
//        }
//      }
//    } else if (!left) {
//      while (1) {
//        linecheck();
//        reading();
//        if (!should_stop && turn >= 12) {
//          if (!should_stop) {       // If not already in stop condition
//            should_stop = 1;        // Set stop flag
//            stop_timer = millis();  // Record the time when stopping started
//          }
//        } else if (should_stop && millis() - stop_timer > 700) {
//          steering.write(sinit);  // Return steering to initial position
//          run(0);                 // Stop motor
//          digitalWrite(buz, 0);   // Turn off buzzer
//          break;                  // Exit the loop
//        }
//        if (fd > 60) {
//          float error = (45 - ld);  // Calculate error based on desired distance
//          integral += error;        // Accumulate error for the integral term
//
//          // Calculate PID correction
//          float correction = Kp * error + Ki * integral + Kd * (error - previousError);
//          //    Serial.print(correction);  // Print correction value for debugging
//          //    Serial.print("  ");
//
//          // Map correction to servo angle (-90 to 90 degrees for steering)
//          int steeringAngle = map(correction, 120, -120, 55, 145);  // Adjust range for responsiveness
//          if (objstr != 100) steeringAngle = objstr;
//          else if (objstr = 100) steeringAngle = steeringAngle;
//          steeringAngle = constrain(steeringAngle, 55, 145);  // Constrain angle within servo limits
//
//          steering.write(steeringAngle);  // Set steering angle based on correction
//
//          // Update motor speed based on the correction
//          float baseSpeed = map(abs(correction), 0, 50, 80, 80);  // Adjust base speed based on correction magnitude
//          if (objstr != 100) {
//            baseSpeed = 50;
//          } else if (objstr = 100) baseSpeed = baseSpeed;
//          baseSpeed = constrain(baseSpeed, 80, 80);  // Ensure speed is within bounds
//          // Serial.println(steeringAngle);                            // Print steering angle for debugging
//
//          run(baseSpeed);         // Set motor speed
//          previousError = error;  // Store current error for next iteration
//        } else if (fd < 60 && line_done && objstr == 100) {
//          turn_millis = millis();
//          while ((millis() - turn_millis < 1000)&& objstr ==100 || line_done) {
//            steering.write(60);
//            run(50);
//            if ((millis() - turn_millis > 970) || objstr != 100) {
//              line_done = 0;
//            }
//          }
//        }
//      }
//    }
//  }
//}
//
//void linecheck() {
//  srl();  // Check serial input (function definition not provided)
//
//  unsigned long currentMillis = millis();  // Get current time in milliseconds
//
//  // Check if line is detected and timer condition is met
//  if (!line_dect && (currentMillis - timer) > 1500) {
//    line_dect = 1;           // Reset line detection status
//    digitalWrite(buz, LOW);  // Turn off buzzer
//  } else if (!line_dect) {
//    return;  // Exit if line not detected
//  }
//
//  // If front distance is less than 160 cm and object detected, increment turn counter
//  if (fd <= 160 && obj >= 3) {
//    if (!orientation_check) {
//      (obj == 3) ? left = 1 : left = 0;
//      orientation_check = 1;
//    }
//    turn++;
//    if (!line_done) {
//      line_done = 1;  // Increment turn counter
//    }
//    digitalWrite(buz, HIGH);  // Activate buzzer
//    line_dect = 0;            // Set line detection to false
//    timer = currentMillis;    // Update timer to current time
//  }
//}
