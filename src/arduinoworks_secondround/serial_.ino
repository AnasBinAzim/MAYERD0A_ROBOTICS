void srl() {
  // Non-blocking Serial check
  
//  if(millis()-srl_timer >15){
//      Serial.write("a");
//      srl_timer = millis();
//  }
  while (Serial.available() > 0) { // Loop until all serial data is read
    int_it = Serial.read();        // Read a byte from the serial buffer
    if(int_it >= 80){
      int_it -= 80;
      objstr = int_it * 3;
      objstr += 40; 
      obj = 4;
      if(orientation_check && left)
        obj = 0;
    }
    else if (int_it >= 40){
      int_it -= 40;
      objstr = int_it * 3;
      objstr += 40; 
      obj = 3;
      if(orientation_check && !left)
        obj = 0;
    }
    else
    {
//    Serial.println(obj);
      objstr = int_it * 3;
      objstr += 40; 
      obj = 0;
    }
//    Serial.println(objstr);            // Convert ASCII character to integer (assuming single digit)
  }  
}
