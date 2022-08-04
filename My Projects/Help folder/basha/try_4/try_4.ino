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

  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 80);

  Serial.begin(9600);
}

void loop() {
  Serial.println("***********************");

  distance_front = ultrasonicFront.read();
  distance_left = ultrasonicLeft.read();
  //  distance_right = ultrasonicLeft.read();
  if (digitalRead(echo_right) == 0)
    distance_right = 15;
  else  // = 1
    distance_right = 50;

  printSerial();
  if (distance_front > 10) {
    forward();
    checkLeft();
    checkRight(false);
  }
  else {
    backward();
    if (distance_left < 5) {
      if (distance_right > 10) {
        right();
        delay(200);
      }
      else{
        backward();
        delay(100);
      }
      checkRight(true);
    }
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
  if (distance_right < 10) {
    left();
    if (reverse == true) {
      backward();
    }
  }
}

void checkLeft() {
  if (distance_left > 5 && distance_left < 10) {
    Serial.println("left1, 5<distance<10,  <<forward>>");
    forward();
  }
  if (distance_left >= 10) {
    Serial.println("left2, 10<=distance,  <<turn left>>");
    left();
    delay(200);
    forward();
  }
  if ((distance_left < 5) || (distance_left > 300)) {
    Serial.println("left3, 5<distance<0,  <<turn right>>");
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
  delay(100);
}


void left() {
  Serial.print(" left");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 1);
  digitalWrite(motor_rA, 1);
  digitalWrite(motor_rB, 0);
  delay(100);
}



void Stop() {
  Serial.print(" stop");
  digitalWrite(motor_lA, 0);
  digitalWrite(motor_lB, 0);
  digitalWrite(motor_rA, 0);
  digitalWrite(motor_rB, 0);
  delay(200);
}
