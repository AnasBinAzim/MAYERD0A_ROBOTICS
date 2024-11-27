int button_read() {
  int cl = 0;                 
p:  
  int t = 0;                  

  if (digitalRead(sw) == 0) {
    digitalWrite(buz, HIGH);
    while (digitalRead(sw) == 0) {
      delay(1);
      t++;
    }
    digitalWrite(buz, LOW);

    if (t > 15) {
      t = 0;
      cl++;

      while (digitalRead(sw) == HIGH) {
        delay(1);
        t++;
        if (t > 500) return cl;
      }
      goto p;
    }
  }
  return cl;
}
