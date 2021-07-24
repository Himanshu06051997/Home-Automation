//int IR1 = 7, IR2 = 8;
//int count = 0;

void setup() {
  // put your setup code here, to run once:

    //pinMode(IR1, INPUT);
    //pinMode(IR2, INPUT);

    Serial.begin(9600);
    digitalWrite(LED_BUILTIN, LOW);

}

void loop(void) {
  // put your main code here, to run repeatedly:

   Serial.println("Hello");
  /*if(digitalRead(IR1) == HIGH)
  {
    while(digitalRead(IR2)==LOW)
    {
      if(digitalRead(IR2) == HIGH)
      ++count;
        Serial.println(count);
        break;
    }*/
  }



