#include<AFMotor.h>
#include<servo.h>

AF_DCMotor motor1(1);//Creating objects and initializing them to motor driver channel
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo gripper;
gripper.attach(10);
int servo_position = 0;

int pinfb = 2;
int pinlr = 13;
int pinud_arm = 9;
int pinlr_arm = 10;
int arm_speed;
int pwmud_arm;
int pwmlr_arm;
int servo_position = 0 ;

void setup()
{
  mstop();
  /*pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);*/
  pinMode(pinfb, INPUT);
  pinMode(pinlr, INPUT);
  pinMode(pinud_arm, INPUT);
  pinMode(pinlr_arm, INPUT);
  Serial.begin(9600);
}
void grip() {
  for (int count = 0; count <= 180; count++)
  {
    gripper.write(count);
  }
}
void ungrip() {
  for (int count = 180; count >= 0; count--)
  {
    gripper.write(count);
  }
}
void left_rotate() {
  motor4.setSpeed(20);
  motor4.run(FORWARD);
}
void right_rotate() {
  motor4.setSpeed(20);
  motor4.run(BACKWARD);
}
void up() {
  motor3.setSpeed(120);
  motor3.run(FORWARD);
}
void down() {
  motor3.setSpeed(120);
  motor3.run(BACKWARD);
}
void mstop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void left() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
void right() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}
void forward() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void backward() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void up_alt() {
  arm_speed = map(pwmud_arm, 1500, 1800, 0, 255);
  motor3.setSpeed(arm_speed);
  motor3.run(FORWARD);
}
void down_alt() {
  arm_speed = map(pwmud_arm, 1000, 1250, 0, 255);
  motor3.setSpeed(arm_speed);
  motor3.run(BACKWARD);
}
void loop()
{
  int pwmfb, pwmlr, pwm_grip;
  pwmfb = pulseIn(pinfb, HIGH);
  pwmlr = pulseIn(pinlr, HIGH);
  pwmud_arm = pulseIn(pinud_arm, HIGH);
  pwmlr_arm = pulseIn(pinlr_arm, HIGH);
  pwm_grip = pulseIn(pin_grip, HIGH);
  if (pwmfb > 0)
  {
    if (pwmfb > 1800)
    {
      forward();
      //    printf("Forward");
      delay(100);
      //mstop();
    }
    if (pwmfb < 1250)
    {
      backward();
      //    printf("Backard");
      delay(100);
      //mstop();
    }
    else mstop();
  }
  if (pwmlr > 0)
  {
    if (pwmlr > 1800)
    {
      left();
      //    printf("Left");
      delay(100);
      //mstop();
    }
    if (pwmlr < 1250)
    {
      right();
      //    printf("Right");
      delay(100);
      mstop();
    }
    else mstop();
  }
  if (pwmud_arm > 0)
  {
    if (pwmud_arm > 1500)
    {
      up();
      //      printf("Up");
      delay(100);
      //motor3.run(RELEASE);
    }
    if (pwmud_arm < 1250)
    {
      down();
      delay(100);
      //motor3.run(RELEASE);
    }
    else motor3.run(RELEASE);
  }
  /*  if (pwmud_arm >= 1250 || pwmud_arm = < 1500)
    {
      motor3.run(RELEASE);
    }*/
  if (pwmlr_arm > 0)
  {
    if (pwmlr_arm > 1500)
    {
      left_rotate();
      delay(100);
    }
    if (pwmlr_arm < 1250)
    {
      right_rotate();
      delay(100);
    }
    else motor4.run(RELEASE);
  }
  if (pwm_grip > 0)
  {
    if (pwm_grip > )
    {
      grip();
      delay(100);
    }
    if (pwm_grip < )
    {
      ungrip()
      delay();
    }
  }
  Serial.print("F/B : ");
  Serial.print(pwmfb);
  Serial.print("   L/R : ");
  Serial.print(pwmlr);
  Serial.print("\n");
}
/*
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
  }*/
