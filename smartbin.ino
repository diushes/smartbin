#include <Servo.h>
Servo myservo;
int servoPin = D4;
int angle = 0;

int trigger_pin = D6;
int echo_pin = D5;
int timing;
int distance; 
void setup() 
{
        myservo.attach(servoPin);
  
        Serial.begin (9600); 
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
}
void loop() 
{
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    timing = pulseIn (echo_pin, HIGH);
    distance = (timing * 0.034) / 2;

  if (distance <= 20)
        {
        Serial.println ("You are too close");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        delay (500);
    
    myservo.write(180);
      delay(1000);
    
        }
  else {
        Serial.println (" You are pretty far ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        delay (500); 
    
      myservo.write(0);
       } 
}
