#include <Ultrasonic.h>

int motor_lA = 2;  //left motor
int motor_lB = 3;
int motor_enableA = 9;

int motor_rA =  4;  //right motor
int motor_rB = 5;
int motor_enableB = 10;

//int trigger_front = A0;
//int echo_front = A1;
//
//int trigger_left = A2;
//int echo_left = A3;
//
//int trigger_right = A4;
//int echo_right = A5;

Ultrasonic ultrasonicFront(A4, A1); //(trig, echo)
Ultrasonic ultrasonicLeft(A3, A0);
//int trigger_front = A4;
//int echo_front = A1;
//
//int trigger_left = A3;
//int echo_left = A0;

//int trigger_right = A5;
int echo_right = A2;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor_lA, OUTPUT);  //left motors forward
  pinMode(motor_lB, OUTPUT);  //left motors reverse
  pinMode(motor_enableA, OUTPUT);

  pinMode(motor_rA, OUTPUT);  //right motors forward
  pinMode(motor_rB, OUTPUT);  //rignt motors reverse
  pinMode(motor_enableB, OUTPUT);

//  pinMode(trigger_front, OUTPUT);
//  pinMode(echo_front, INPUT);
//
//  pinMode(trigger_left, OUTPUT);
//  pinMode(echo_left, INPUT);

  //  pinMode(trigger_right,OUTPUT);
  pinMode(echo_right, INPUT);

  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 80);

}

void loop() {
  Serial.println("***********************");
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;

  //Calculating distance

//  digitalWrite(trigger_front, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigger_front, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigger_front, LOW);
//  duration_front = pulseIn(echo_front, HIGH);
//  distance_front = duration_front * 0.034 / 2;
  distance_front = ultrasonicFront.read();

//  digitalWrite(trigger_left, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigger_left, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigger_left, LOW);
//  duration_left = pulseIn(echo_left, HIGH);
//  distance_left = duration_left * 0.034 / 2;
  distance_left = ultrasonicLeft.read();

  //  if(digitalRead(echo_left) == 0)
  //    distance_left = 15;
  //  else
  //    distance_left = 50;


  //  digitalWrite(trigger_right, LOW);
  //  delayMicroseconds(2);
  //  digitalWrite(trigger_right, HIGH);
  //  delayMicroseconds(10);
  //  digitalWrite(trigger_right, LOW);
  //  duration_right = pulseIn(echo_right, HIGH);
  if (digitalRead(echo_right) == 0)
    distance_right = 15;
  else
    distance_right = 50;

  //  distance_right= digitalRead(echo_right);//duration_right*0.034/2;

  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);
//  delay(50);


  if (distance_front > 20) {
    //if (distance_front >10){

    forward();

    if (distance_left > 10 && distance_left < 20) {
      Serial.println("left1, 10<distance<20");
      forward();
    }
    if (distance_right < 20){
      left();
    }
    if (distance_left >= 20) {    // 3om comment
      Serial.println("left2, 20<=distance");
      //        Stop();
      left();
      delay(100);
      forward();
    }
    if ((distance_left < 10) || (distance_left > 300)) {
      Serial.println("left3, 10<distance<0");
      //       Stop();
      right();
      delay(100);
//      do{
      forward();
//      }while(distance_front > 15);
    }
  }
  else{
    backward();
  }

  if ((((distance_front < 20) || (distance_front > 300)) && distance_right > 20)) {
    Stop();
//    delay(1000);
    right();
    delay(100);

  }
  if((distance_left < 10)&&(distance_front < 10)&&(distance_right < 20)){
    Stop();
    backward();
//    delay(500);
  }

  if (((distance_front < 20) || (distance_front > 400)) && distance_right < 20) {
    backward();
//    delay(200);
//    Stop();
//    delay(1000);
    right();
    delay(100);

  }


//  if (distance_front > 300) {
//    Stop();
////    delay(1000);
//    right();
//    delay(100);
//
//  }
}

void forward()
{
  Serial.println("forward");
  digitalWrite(motor_lA, 1);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 1);
  digitalWrite(motor_rB, 0);
  delay(300);
}

void backward()
{
  Serial.println("forward");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 1);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 1);
  delay(300);
}


void right() {
  Serial.println("right");
  digitalWrite(motor_lA, 1);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 1);
  delay(100);
}


void left() {
  Serial.println("left");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 1);
  digitalWrite(motor_rA, 1);
  digitalWrite(motor_rB, 0);
  delay(100);
}



void Stop() {
  Serial.println("stop");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 0);
  delay(200);
}
