bool line_done = 0;
unsigned long turn_millis = 0;
unsigned long risktimer = 0;
int rrc, lrc, frc;
int mode = 0;
unsigned long long int fs_timer, ss_timer;
int last_srl = 95;

float angle_diff() {
  float err = target_angle - angle;
  if (err > 180) {
    err -= 360;
  }
  else if (err < -180) {
    err += 360;
  }
  return err;
}


void nd() {
  turn = 0;
  timer = 0;
  should_stop = 0;
  stop_timer = 0;
  orientation_check = 0;
  orientation_timer = 0;
  obj = 0;
  is_obj = wait_timer = return_timer = 0;
  rrc = lrc = frc = 0;
  mode = 0;
  fs_timer = 0;
  ss_timer = 0;
  initial_angle = angle;
  target_angle = initial_angle;


  while (1) {
    linecheck();
    reading();
    if (ut) {
      run(0);
      steering.write(sinit);
      break;
    }
    if (!should_stop && turn >= 12) {
      if (!should_stop) {
        should_stop = 1;
        stop_timer = millis();
      }
    } else if (should_stop && millis() - stop_timer > 3000) {
      steering.write(sinit);
      run(0);
      digitalWrite(buz, 0);
      break;
    }
    if (millis() - mun_tmr >= 200 && tadd) {
      (left) ? target_angle += 90 : target_angle -= 90;
      if (target_angle < -180) {
        target_angle += 360;
      }
      else if (target_angle > 180) {
        target_angle -= 360;
      }
      tadd = 0;
    }
    float angle_error = angle_diff();

    if (abs(angle_error) < 20 ) {
      digitalWrite(led, 0);
      error = (rd - ld);
      integral += error;
      correction = Kp * error + Ki * integral + Kd * (error - previousError);
      steeringAngle = map(correction, 100, -100, sinit - 25, sinit + 25);
      steeringAngle = constrain(steeringAngle, sinit - 25, sinit + 25);
    } else {
      digitalWrite(led, 1);
      steeringAngle = map(angle_error, -90, 90, sinit - 50, sinit + 50);
      steeringAngle = constrain(steeringAngle, sinit - 50, sinit + 50);
    }


    if (objstr == 160) {

      steeringAngle = sinit;
    }
    else if (objstr == 162) {
      m1 = millis();
    }
    else if (objstr != sinit ) {
      steeringAngle = objstr;
    } else if (objstr == sinit) {
      steeringAngle = steeringAngle;
    }
    if (millis() - m1 < 0) {
      steeringAngle = 95;
    }
//    if (millis() - srlt_timer > 30) {
//      Serial.print("currentAngle: " );
//      Serial.print(angle);
//      Serial.print(" targetAngle: " );
//      Serial.print(target_angle);
//      Serial.print(" Angle diff: " );
//      Serial.println(angle_error);
//      srlt_timer = millis();
//
//    }
    //    if (((!f1 && rd < 15 ) || (!f1 && ld < 15 )) && steeringAngle >= 93 && steeringAngle <= 97) {
    //      if (rd < 15) {
    //        steering.write(130);
    //        go(10, -140);
    //      } else if (ld < 15) {
    //        steering.write(50);
    //        go(10, -140);
    //      }
    //
    //    }

    //    if(fd<10){
    //      if(f1){
    //        if(angle_error > 0){
    //          steering.write(50);
    //          go(25,-140);
    //        }else if(angle_error < 0){
    //          steering.write(140);
    //          go(25,-140);
    //        }
    //      }else{
    //        steering.write(sinit);
    //        go(10,140);
    //      }
    //    }
    steering.write(steeringAngle);
    float baseSpeed = map(abs(correction), 0, 60, 140, 140);
    baseSpeed = constrain(baseSpeed, 140, 140);
    run(baseSpeed);
    //    f1 = 0;
    previousError = error;
  }
}

void linecheck() {
  //  srl();

  unsigned long currentMillis = millis();

  if (!line_dect && (currentMillis - timer) > 4500) {
    line_dect = 1;
    digitalWrite(buz, LOW);
  } else if (!line_dect) {
    return;
  }

  if (fd <= 140 && obj > 0) {
    if (!orientation_check) {
      (obj == 1) ? left = 1 : left = 0;
    }
    orientation_check = 1;

    turn++;
    mun_tmr = millis();
    tadd = 1;
    digitalWrite(buz, HIGH);
    line_dect = 0;
    timer = currentMillis;
  }
}

void riskcount() {
  if (rd < 25) {
    rrc++;
    risktimer = millis();
  } else if (ld < 25) {
    lrc++;
    risktimer = millis();
  }
  if (fd < 25) {
    frc++;
  }
}
