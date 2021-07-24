String in, out;
int total = 0;

void setup() {
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void show() {
  Serial.print(total);
    Serial.println(" people in room.");
}
void loop() 
{
   if(total > 0)
  {
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }
  if ((digitalRead(7) == HIGH) && (digitalRead(8) == LOW)) 
  {
    while (digitalRead(8) == LOW) 
    {
    }
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Person entered there are ");
    
    total++;
    show();
    
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  } 
  else if ((digitalRead(8) == HIGH) && (digitalRead(7) == LOW)) 
  {
    while (digitalRead(7) == LOW) 
    {
    }
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Person exited there are ");
    
    total--;
    show();
    
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
