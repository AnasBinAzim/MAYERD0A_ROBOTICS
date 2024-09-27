bool line_done = 0;
unsigned long turn_millis = 0;
unsigned long risktimer = 0;
int rrc ,lrc,frc ;
void first() {
  turn = 0;         // Reset turn counter
  timer = 0;        // Reset timer
  should_stop = 0;  // bool to indicate if stopping is needed
  stop_timer = 0;   // Reset stop timer
  orientation_check = 0;
  orientation_timer = 0;
  obj = 0;
  is_obj = wait_timer = return_timer = 0;
  rrc = lrc = frc = 0;
  while (1) {
    linecheck();
    reading();
    if(left){
      digitalWrite(led,1);
    }
//     Serial.println(left);
//    riskcount();
    if (!should_stop && turn >= 12) {
      if (!should_stop) {
        should_stop = 1;
        stop_timer = millis();
      }
    } else if (should_stop && millis() - stop_timer > 3000) {
      steering.write(sinit);  // Return steering to initial position
      run(0);                 // Stop motor
      digitalWrite(buz, 0);   // Turn off buzzer
      break;                  // Exit the loop
    }
    float error = (rd - ld);  // Calculate error based on desired distance
    integral += error;        // Accumulate error for the integral term

    // Calculate PID correction
    float correction = Kp * error + Ki * integral + Kd * (error - previousError);
    //    Serial.print(correction);  // Print correction value for debugging
    //    Serial.print("  ");

    // Map correction to servo angle (-90 to 90 degrees for steering)
    int steeringAngle = map(correction, 90, -90, 70, 130); 
//    delay(100);// Adjust range for responsiveness
//    Serial.println(is_obj);
//    Serial.print("yes");
//    Serial.println(wait_timer);
    if (objstr != 100) {
      steeringAngle = objstr;
//      if(objstr > 100)
//         laststr = 1;
//      else 
//        laststr = 2;
// 
//      is_obj = 1;
//      wait_timer = millis();
    }
//     if (objstr == 100) {
//      
//      if(is_obj==1 && millis() - wait_timer <= 100){
//        steeringAngle = objstr;
//      }
//      else if(is_obj==1 && millis()-wait_timer > 100){
//        wait_timer = 0;
//        return_timer = millis();
//        is_obj = 2;}        
//     
//      else if(is_obj==2 && millis()-return_timer <= 1200){
//        if(laststr == 1)
//          steeringAngle = 55;
//         else
//         steeringAngle = 145;                
//      }
//      else if(is_obj==2 && millis()-return_timer > 350){
//        is_obj = 0;
//        wait_timer = 0;
//        return_timer = 0;
//      }
      else if(rrc || lrc){
        
        if(rrc>3) {
          while(millis()-risktimer <= 200){
          steeringAngle = 160;
          }
        }
        else if(lrc > 3) {
          while(millis() - risktimer <=200){
            steeringAngle = 40;
          }
        }
        lrc = rrc = 0;
      }
      else if (objstr == 100){
        steeringAngle = steeringAngle;
      }
////    }
    
    steeringAngle = constrain(steeringAngle, 55, 145);  // Constrain angle within servo limits
//    riskcount();
//    if(lrc || rrc){
//      if(rrc>2){
//        while(rd<10){
//          steering.write(140);
//          run(50);
//        }
//      }else if(lrc>2){
//        while(ld<10){
//          steering.write(60);
//          run(50);
//        }
//      }
//      lrc = rrc = 0;
//    }else if(frc>2){
//      if(left){
//        while(fd<20){
//          if(laststr > 100){
//            steering.write(60);
//          run(50);
//          }else if(laststr < 100){
//            steering.write(140);
//          run(50);
//          }
//          
//        }
//      }else if(!left){
//        while(fd<20){
//          if(laststr > 100){
//            steering.write(140);
//          run(50);
//          }else if(laststr < 100){
//            steering.write(60);
//          run(50);
//          }
//          
//        }
//      }
//      frc = 0;
//    }
    steering.write(steeringAngle);  // Set steering angle based on correction

    // Update motor speed based on the correction
    float baseSpeed = map(abs(correction), 0, 60, 50, 50);  // Adjust base speed based on correction magnitude
    if (objstr != 100) {
      baseSpeed = 50;
    } else if (objstr = 100) baseSpeed = baseSpeed;
    baseSpeed = constrain(baseSpeed, 50, 50);  // Ensure speed is within bounds

    run(baseSpeed);         // Set motor speed
    previousError = error;  // Store current error for next iteration
  }
}

void linecheck() {
  srl();  // Check serial input (function definition not provided)

  unsigned long currentMillis = millis();  // Get current time in milliseconds

  // Check if line is detected and timer condition is met
  if (!line_dect && (currentMillis - timer) > 1500) {
    line_dect = 1;           // Reset line detection status
    digitalWrite(buz, LOW);  // Turn off buzzer
  } else if (!line_dect) {
    return;  // Exit if line not detected
  }

  // If front distance is less than 160 cm and object detected, increment turn counter
  if (fd <= 160 && obj >= 3) {
    if (!orientation_check) {
      (obj == 3) ? left = 1 : left = 0;
      orientation_check = 1;
    }
    turn++;
    digitalWrite(buz, HIGH);  // Activate buzzer
    line_dect = 0;            // Set line detection to false
    timer = currentMillis;    // Update timer to current time
  }
}
void riskcount(){
  if(rd < 25){
    rrc++;
    risktimer = millis();
  }else if(ld<25){
    lrc++;
    risktimer = millis();
  }
  if(fd<25){
    frc++;
  }
}
