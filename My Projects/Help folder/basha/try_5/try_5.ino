#include <Ultrasonic.h>

int motor_lA = 2;  //left motor
int motor_lB = 3;
int motor_enableA = 9;

int motor_rA =  4;  //right motor
int motor_rB = 5;
int motor_enableB = 10;

Ultrasonic ultrasonicFront(A4, A1); //(trig, echo)
Ultrasonic ultrasonicLeft(A3, A0);
//Ultrasonic ultrasonicRight(A5, A2);

int echo_right = A2;


long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;

void setup() {
  pinMode(motor_lA, OUTPUT);  //left motors forward
  pinMode(motor_lB, OUTPUT);  //left motors reverse
  pinMode(motor_enableA, OUTPUT);

  pinMode(motor_rA, OUTPUT);  //right motors forward
  pinMode(motor_rB, OUTPUT);  //rignt motors reverse
  pinMode(motor_enableB, OUTPUT);

  pinMode(echo_right, INPUT);

  analogWrite(motor_enableA, 73);
  analogWrite(motor_enableB, 75);

  Serial.begin(9600);
}

void loop() {
  Serial.println("***********************");

  distance_front = ultrasonicFront.read();
  if (distance_front > 200)
    distance_front = 0;
  distance_left = ultrasonicLeft.read();
  if (distance_left > 200)
    distance_left = 0;
  //    distance_right = ultrasonicLeft.read();
  //  if(distance_right > 200)
  //    distance_right = 0;

  if (digitalRead(echo_right) == 0)
    distance_right = 15;
  else  // = 1
    distance_right = 50;

  /*if (distance_front > 15) {
    forward();
    checkLeft();
    checkRight(false);
    }
    else {
    backward();
    if (distance_left < 10) {
      if (distance_right > 20) {
        right();
        delay(200);
      }
      else{
        backward();
        delay(100);
      }
      checkRight(true);
    }
    }*/






  printSerial();
  if (distance_front > 10) {
    if (distance_left > 20) {
      left();
    }
    else
      forward();
  }
  else {
    backward();
  }
}

void printSerial() {
  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);
}

void checkRight(bool reverse) {
  if (distance_right < 20) {
    left();
    if (reverse == true) {
      backward();
    }
  }
}

void checkLeft() {
  if (distance_left > 10 && distance_left < 20) {
    Serial.println("left1, 10<distance<20,  <<forward>>");
    forward();
  }
  if (distance_left >= 20) {
    Serial.println("left2, 20<=distance,  <<turn left>>");
    left();
    delay(200);
    forward();
  }
  if ((distance_left < 10) || (distance_left > 300)) {
    Serial.println("left3, 10<distance<0,  <<turn right>>");
    right();
    delay(100);
    forward();
  }
}

void forward()
{
  Serial.print(" forward");
  digitalWrite(motor_lA, 1);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 1);
  digitalWrite(motor_rB, 0);
  delay(300);
}

void backward()
{
  Serial.print(" forward");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 1);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 1);
  delay(300);
}


void right() {
  Serial.print(" right");
  digitalWrite(motor_lA, 1);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 1);
  delay(300);
}


void left() {
  Serial.print(" left");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 1);
  digitalWrite(motor_rA, 1);
  digitalWrite(motor_rB, 0);
  delay(300);
}



void Stop() {
  Serial.print(" stop");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 0);
  delay(200);
}
