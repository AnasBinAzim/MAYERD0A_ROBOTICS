//void srl() {
//  // Non-blocking Serial check
//
//  //  if(millis()-srl_timer >15){
//  //      Serial.write("a");
//  //      srl_timer = millis();
//  //  }
////  if(srll){
////    Serial.write("a");
////    srll = 0;
////  }else if(!srll){
////    Serial.write("b");
////  }
//  while (Serial.available() > 0) { // Loop until all serial data is read
//    int_it = Serial.read();
//    new_srl = int_it;
//    if (new_srl == 121) {
//      objstr = 160;
//    }
//    else if(new_srl == 122){
//      ut = 1;
//      digitalWrite(buz,1);
//    }
//    else if (new_srl >= 80) {
//      new_srl -= 80;
//      if (new_srl == 20) {
//        objstr = sinit;
//      } else {
//        objstr = steering_table[new_srl];
//        objstr = constrain(objstr, sinit  - max_possible_str, sinit + max_possible_str);
//      }
//      obj = 2;
//    }
//    else if (new_srl >= 40) {
//      new_srl -= 40;
//      if (new_srl == 20) {
//        objstr = sinit;
//      } else {
//        objstr = steering_table[new_srl];
//        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);
//      }
//      obj = 1;
//    }
//    else
//    {
//
//      if (new_srl ==  20) {
//        objstr = sinit;
//      } else {
//        objstr = steering_table[new_srl];;
//        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);
//      }
//      obj = 0;
//    }
//
//
//    // Convert ASCII character to integer (assuming single digit)
//  }
//}

void srl() {
  // Non-blocking Serial check

  //  if(millis()-srl_timer >15){
  //      Serial.write("a");
  //      srl_timer = millis();
  //  }
  //  if(srll){
  //    Serial.write("a");
  //    srll = 0;
  //  }else if(!srll){
  //    Serial.write("b");
  //  }
  while (Serial.available() > 0) { // Loop until all serial data is read
    int_it = Serial.read();
    new_srl = int_it;
    if (new_srl == 121) {
      objstr = 160;
    }
    else if (new_srl == 122) {
      ut = 1;
      digitalWrite(buz, 1);
    }
    else if (new_srl == 123) {
      obj = 1;
    } else if (new_srl == 124) {
      obj = 2;
    }
    else if(new_srl == 125){
      objstr = 162;
    }
    else if (new_srl >= 80) {
      new_srl -= 80;
      if (new_srl == 20) {
        objstr = sinit;
      } else {
        objstr = steering_table[new_srl];
        objstr = constrain(objstr, sinit  - max_possible_str, sinit + max_possible_str);
      }
      //      obj = 2;
    }
    else if (new_srl >= 40) {
      new_srl -= 40;
      if (new_srl == 20) {
        objstr = sinit;
      } else {
        objstr = steering_table[new_srl];
        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);
      }
      //      obj = 1;
    }
    else {
      if (new_srl ==  20) {
        objstr = sinit;
      } else {
        objstr = steering_table[new_srl];;
        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);
      }
      obj = 0;
    }
    // Convert ASCII character to integer (assuming single digit)
  }
}

void srl2() {
  while (Serial2.available()) {
    angle = (Serial2.read() * 1.5) - 180;
    //    Serial.println(angle);
    // put your main code here, to run repeatedly:
  }
}
