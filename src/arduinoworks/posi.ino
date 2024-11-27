void calcPos(){
  if(millis() - lastPosTmr > 30){
    long encDiff = encoderCount - lastEnc;
    float linear = encDiff / 25.0;
    float dx = linear * cos(angle);
    float dy = linear * sin(angle);

    x_pos += dx;
    y_pos += dy;

    lastEnc = encoderCount;
    lastPosTmr = millis();
    Serial.print("$");
    Serial.print(int(x_pos));
    Serial.print(",");
    Serial.println(int(y_pos));
  }
}
