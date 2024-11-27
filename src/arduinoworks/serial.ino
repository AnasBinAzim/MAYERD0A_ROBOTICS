void srl() {
  while (Serial.available() > 0) { // Loop until all serial data is read
    int_it = Serial.read();  // Read the incoming byte from Serial
    new_srl = int_it;  // Store the read byte into new_srl
    if (new_srl == 121) {  // If the received byte is 121
      objstr = 160;  // Set objstr to 160
    }
    else if (new_srl == 122) {  // If the received byte is 122
      ut = 1;  // Set ut flag to 1
      digitalWrite(buz, 1);  // Turn on the buzzer
    }
    else if (new_srl == 123) {  // If the received byte is 123
      obj = 1;  // Set obj to 1
    } else if (new_srl == 124) {  // If the received byte is 124
      obj = 2;  // Set obj to 2
    }
    else if(new_srl == 125){  // If the received byte is 125
      objstr = 162;  // Set objstr to 162
    }
    else if (new_srl >= 80) {  // If the received byte is greater or equal to 80
      new_srl -= 80;  // Subtract 80 from new_srl
      if (new_srl == 20) {  // If new_srl is 20
        objstr = sinit;  // Set objstr to sinit
      } else {
        objstr = steering_table[new_srl];  // Set objstr based on steering_table value
        objstr = constrain(objstr, sinit  - max_possible_str, sinit + max_possible_str);  // Constrain objstr within limits
      }
    }
    else if (new_srl >= 40) {  // If the received byte is greater or equal to 40
      new_srl -= 40;  // Subtract 40 from new_srl
      if (new_srl == 20) {  // If new_srl is 20
        objstr = sinit;  // Set objstr to sinit
      } else {
        objstr = steering_table[new_srl];  // Set objstr based on steering_table value
        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);  // Constrain objstr within limits
      }
    }
    else {  // For all other values of new_srl
      if (new_srl ==  20) {  // If new_srl is 20
        objstr = sinit;  // Set objstr to sinit
      } else {
        objstr = steering_table[new_srl];  // Set objstr based on steering_table value
        objstr = constrain(objstr, sinit - max_possible_str, sinit + max_possible_str);  // Constrain objstr within limits
      }
      obj = 0;  // Set obj to 0
    }
  }
}

void srl2() {
  while (Serial2.available()) { // Loop while there is data available in Serial2
    angle = (Serial2.read() * 1.5) - 180;  // Read byte from Serial2, scale and adjust angle
  }
}
