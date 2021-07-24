#include<Servo.h>

int ir = 7;
int buzz = 8; 

Servo se;

void setup() {
  pinMode(ir,INPUT);
  pinMode(buzz,OUTPUT);
 
  se.attach(9);
  se.write(20);
  
  Serial.begin(9600);
  
  digitalWrite(buzz,LOW);  
  // put your setup code here, to run once:
}

void loop() {

  if(digitalRead(ir) == HIGH)
  {
    while(digitalRead(ir) == HIGH)
    {
      Serial.println("ir is high");
      
     /* digitalWrite(buzz,HIGH);
      delay(1000);
      digitalWrite(buzz,LOW);
      delay(2000);
      digitalWrite(buzz,HIGH);
      delay(3000);
      digitalWrite(buzz,LOW);*/


       //if(Serial.available() > 0)
       //{
          Serial.println("Inside available");

          //RcvdVal = Serial.read();
        
          //if(RcvdVal == '5')
          //{
            se.write(90);
          //}
       }
    }
     delay(3000);
  
  se.write(0);
  }
