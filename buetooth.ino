void setup() {
  
  Serial.begin(9600);
  pinMode(8,OUTPUT);

}
char data;
void loop() {
  if (Serial.available()>0)

    data = Serial.read();
    switch(data)
    {
      case 'a':digitalWrite(8,HIGH);
      break;
      case  'b':digitalWrite(8,LOW);
      break;
      default:break;
      }
      Serial.println(data);

}
