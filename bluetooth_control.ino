#include <LiquidCrystal.h>
#include <Servo.h>
#define relay 6

const int rs = A5, en = A4, d4 = A3, d5 = A2, d6 = A1, d7 = A0;
int ir_gate = 6;
int buz = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo se;

int room2 = 8;
int flag = 0;
int receivedData;

void setup() 
{
  pinMode(buz,OUTPUT);
  pinMode(room2, OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(ir_gate, INPUT);

  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(room2,LOW);
  digitalWrite(relay,HIGH);

  lcd.begin(16, 2);
  lcd.clear();

  se.attach(10);
  se.write(0);
  delay(100);
  se.detach();

  Serial.begin(9600);
  }
void loop() 
{
  if(digitalRead(ir_gate) == HIGH)
  {
    lcd.setCursor(0,0);
    lcd.print("Chutiya wait");
    
   // digitalWrite(buz,HIGH);   
    delay(100);
  }

  else
  {
    digitalWrite(buz,LOW);
    
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Cum here =>");
    
    delay(100);
  }

  if(Serial.available()>0)
  {
    receivedData = Serial.read();
    flag = 1;
  }
  if(flag == 1)
  {
    switch(receivedData)
    {
      case '0':
                digitalWrite(LED_BUILTIN, LOW);
                digitalWrite(relay, LOW);
                
                Serial.println("LED Turned OFF");
                break;

      case '1':
              digitalWrite(LED_BUILTIN, HIGH);
              digitalWrite(relay, HIGH);
              break;
      
      case '2':
              digitalWrite(room2, HIGH);
              digitalWrite(relay, HIGH);
              break;

      case '3':
               digitalWrite(room2, LOW);
               digitalWrite(relay, LOW);
               break;

      case '4':
              se.attach(10);
              se.write(90);
              delay(100);
              se.detach();           
              break;


      case '5':
              se.attach(10);
              se.write(0);
              delay(100);
              se.detach();
              
              break;

       default:
              break;
    }
    
    flag = 0;
    receivedData = 12;
  }
}
