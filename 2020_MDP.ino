#include<Servo.h>
#define TRIG 2
#define ECHO 3

Servo servo;
boolean isNear = false;

void setup()
{
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  servo.attach(9);
  servo.write(90);
  Serial.begin(9600);
}
void loop(){

  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG,LOW);

  long distance = pulseIn(ECHO,HIGH)/58;
  Serial.println(distance);
  if(distance < 20){
    if(!isNear){
      isNear = true;
      servo.write(0);
    }
  }else{
    if(isNear){
      isNear = false;
      servo.write(90);
      delay(1000);
    }
  }
  delay(100);
  
}
