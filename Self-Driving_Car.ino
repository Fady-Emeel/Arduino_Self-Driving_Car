#include <Servo.h>
Servo myservo;
int echopin=11 ;
int trigpin=12 ;
int Right_speed=3;
int Left_speed=5;
int left_m_1=7;
int left_m_2=8;
int right_m_1=9;
int right_m_2=10;
long duration;
long cm;


void setup() {
  Serial.begin (9600);
  pinMode (right_m_1,OUTPUT);
  pinMode (right_m_2,OUTPUT);
  pinMode (left_m_1,OUTPUT);
  pinMode (left_m_2,OUTPUT);
  pinMode (Right_speed,OUTPUT);
  pinMode (Left_speed,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  myservo.attach (6);

}

void loop() {
  myservo.write(90);
  
  if  (distance ()>40)
  {
    control (170,120);
    forword ();
  }
 
  else
  {
    STOP ();
    servoR();
    delay(750);
    if (distance ()>40)
    {
      forword ();
      control(190,0);
      delay (750);
    }
  
  else if (distance ()<40)
    {
      servoL();
      delay(750);
      if (distance ()>40)
      {
        forword ();
        control(0,170);
        delay(750);
  
      }
    }
  }

}
  

void control (int x,int y){
  analogWrite(Left_speed,x);
  analogWrite(Right_speed,y);

  
}
void forword (){
  
  digitalWrite(right_m_1,HIGH);
  digitalWrite(right_m_2,LOW);
  digitalWrite(left_m_1,HIGH);
  digitalWrite(left_m_2,LOW);
  
}
void STOP (){
  digitalWrite(right_m_1,LOW);
  digitalWrite(right_m_2,LOW);
  digitalWrite(left_m_1,LOW);
  digitalWrite(left_m_2,LOW);
}
int distance () {
  digitalWrite (
  trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite (trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite (trigpin,LOW);
  duration=pulseIn (echopin,HIGH);
  cm = (duration/2)*0.0343;
  Serial.print(cm);
  Serial.println ("cm");
  delay (50);
  return cm;
}
void backword (){
  digitalWrite(right_m_1,LOW);
  digitalWrite(right_m_2,HIGH);
  digitalWrite(left_m_1,LOW);
  digitalWrite(left_m_2,HIGH);
  
}
int servoR (){
  myservo.write(0);
  digitalWrite (trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite (trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite (trigpin,LOW);
  duration=pulseIn (echopin,HIGH);
  cm = (duration/2)*0.0343;
  Serial.print(cm);
  Serial.println ("cm");
  delay (250);
  return cm;
}
int servoL (){
  myservo.write(180);
  digitalWrite (trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite (trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite (trigpin,LOW);
  duration=pulseIn (echopin,HIGH);
  cm = (duration/2)*0.0343;
  Serial.print(cm);
  Serial.println ("cm");
  delay (250);
  return cm;
   }
