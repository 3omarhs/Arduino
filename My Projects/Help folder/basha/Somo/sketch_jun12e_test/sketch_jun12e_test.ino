#include <AFMotor.h>    // AFMotor kutubxonasini yuklab oling!!!
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

int trigPin = 9;
int echoPin = 10;
int davomiylik, sm;
bool  jn = false;

int led1 = 2; //red
int led2 = 3;
int led3 = A2;
int IR_SensorL = A0;
int IR_SensorR = A1;

void plusUltra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  davomiylik = pulseIn(echoPin, HIGH);
  sm = davomiylik / 58;


  Serial.print("ultrasonic: ");
  Serial.println(sm);
}

void setup() {
  //Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(IR_SensorL, INPUT);
  pinMode(IR_SensorR, INPUT);

  //  delay(5000);             // 5 Sekund kutib turish
  motor1.setSpeed(135);    // Tezlik 0 dan 255 gacha o'zgartirish mumkin
  motor1.run(RELEASE);
  motor2.setSpeed(150);    // Tezlik 2- Motor uchun
  motor2.run(RELEASE);
  Serial.begin(9600);
  digitalWrite(led1, HIGH);
  delay(2000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(2000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
}

void loop() {
  while ((digitalRead(IR_SensorL) == 1) && (digitalRead(IR_SensorR) == 1)) {
//    plusUltra();
////    readGroundLine();
//    //Serial.println(sm);
//    while (sm > 50) {
//      //Agar 50 sm masofada biror raqib ko'rinsa
//      digitalWrite(led1, LOW);
//      digitalWrite(led2, HIGH);
//      motor1.run(BACKWARD);  //O'nga burilib raqibni qidir
//      motor2.run(FORWARD);
//      delay(10);
//      jn = false;
//      plusUltra();
//    }
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, LOW);
//    if (jn == false) {
//      motor1.run(RELEASE);   //Oldinga yuri
//      motor2.run(RELEASE);
//      delay(350);
//      Serial.println("Break");
      motor1.run(FORWARD);   //Oldinga yuri
      motor2.run(BACKWARD);
//      delay(350);
//      jn = true;
//    }
//    motor1.run(FORWARD);   //Oldinga yuri
//    motor2.run(FORWARD);
//    delay(500);
  }
  motor1.run(RELEASE);   //Oldinga yuri
      motor2.run(RELEASE);
//  readGroundLine();
}

void readGroundLine() {
  if ((digitalRead(IR_SensorL) == 0) && (digitalRead(IR_SensorR) == 0)) {
    motor1.run(RELEASE);//right
    motor2.run(RELEASE);//left
    delay(350);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(500);
  }
  else if (digitalRead(IR_SensorL) == 0) {
    motor1.run(RELEASE);//right
    motor2.run(RELEASE);//left
    delay(350);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    delay(700);
  }
  else if (digitalRead(IR_SensorR) == 0) {
    motor1.run(RELEASE);//right
    motor2.run(RELEASE);//left
    delay(350);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    delay(700);
  }
}
