#include <Servo.h>
#define waterSensor 10
int pos = 0;


Servo myservo1;


void setup() {
   pinMode(waterSensor, INPUT); // water sensor input
   myservo1.attach(3);
}

void loop() {
  
   if(digitalRead(waterSensor) == HIGH)
   {    
      
         myservo1.write(90);      
   }
   else
   {
         myservo1.write(0);
   }
}
