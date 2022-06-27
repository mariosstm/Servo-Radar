#include <Servo.h>
Servo myservo;  
const int trigPin = 9;
const int echoPin = 10;

float duration, distance, p;
int pos = 0;    

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.attach(11);
 
}
void loop() 
{
  if(Serial.available()>0)
  {
    for (pos = 0; pos <= 180; pos += 10) 
      { 
        myservo.write(pos); 
        Serial.println(pos); 
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
          
            duration = pulseIn(echoPin, HIGH);
            distance = (duration*.0343)/2;
            p=distance*1000;
            Serial.println(p);
            delay(500);                      
      }
    for (pos = 180; pos >= 0; pos -= 10) 
      { 
        myservo.write(pos);
        Serial.println(pos);  
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
          
            duration = pulseIn(echoPin, HIGH);
            distance = (duration*.0343)/2;
            p=distance*1000;
            Serial.println(p);
            delay(500);
      } 
  }
    
}
