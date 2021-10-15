#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int pinfb=7;
int pinlr=9;
int pinud_arm=5;
int pinlr_arm=6;
void setup() 
{
  mstop();
  /*pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);*/
  pinMode(pinfb,INPUT);
  pinMode(pinlr,INPUT);
  Serial.begin(9600);
}
void mstop(){
  motor.run(RELEASE);
}
void left(){
  motor1.setspeed(200);
  motor2.setspeed(200);
  motor1.run.(FORWARD);
  motor2.run(BACKWARD);
}
void right(){
  motor1.setspeed(200);
  motor2.setspeed(200);
  motor1.run.(BACKWARD);
  motor2.run(FORWARD);
}
void forward(){
  motor1.setspeed(200);
  motor2.setspeed(200);
  motor1.run.(FORWARD);
  motor2.run(FORWARD);
}
void backward(){
  motor1.setspeed(200);
  motor2.setspeed(200);
  motor1.run.(BACKWARD);
  motor2.run(BACKWARD);
 }
void f()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}

void b()
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}

void l()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
}

void r()
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
}

void reset()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
}

void loop() 
{
  int pwmfb,pwmlr;
  pwmfb = pulseIn(pinfb,HIGH);
  pwmlr = pulseIn(pinlr,HIGH);
  if(pwmfb>1800)
  {
    forward();
//    printf("Forward");
    delay(100);
    mstop();
  }
  if(pwmfb<1250)
  {
    backward();
//    printf("Backard");
    delay(100);
    mstop();
  }
  if(pwmlr>1800)
  {
    left();
//    printf("Left");
    delay(100);
    mstop();
  }
  if(pwmlr<1250)
  {
    right();
//    printf("Right");
    delay(100);
    mstop();
  }
  Serial.print("F/B : ");
  Serial.print(pwmfb);
  Serial.print("   L/R : ");
  Serial.print(pwmlr);
  Serial.print("\n");
}
