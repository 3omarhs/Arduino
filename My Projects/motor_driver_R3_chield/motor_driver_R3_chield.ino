#include<AFMotor.h>

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void forword() { // turn it on going forward
  Motor1.setSpeed(160);
  Motor1.run(FORWARD);
  Motor2.setSpeed(160);
  Motor2.run(FORWARD);
}

void backword() { // the other way
  Motor1.setSpeed(120);
  Motor1.run(BACKWARD);
  Motor2.setSpeed(120);
  Motor2.run(BACKWARD);
}

void turnRight() { // the other right
  Motor1.setSpeed(220);
  Motor1.run(FORWARD);
  Motor2.setSpeed(220);
  Motor2.run(BACKWARD);
}

void turnLeft() { // turn it on going left
  Motor1.setSpeed(140);
  Motor1.run(BACKWARD);
  Motor2.setSpeed(140);
  Motor2.run(FORWARD);
}

void stop() { // stopped
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.setSpeed(0);
  Motor2.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("forward");
//  forword();
//  delay(1000);
//  stop();
//  delay(500);
//  Serial.println("right");
//  turnRight();
//  delay(1000);
//  stop();
//  delay(500);
  Serial.println("left");
  turnLeft();
  delay(1000);
  stop();
  delay(500);
}
