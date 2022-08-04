#include <AFMotor.h>    // AFMotor kutubxonasini yuklab oling!!!
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

int trigPin = 9;
int echoPin = 10;
int trigPin1 = 4;
int echoPin1 = 3;
int davomiylik, sm, davomiylik1, sm1;
bool  jn = false;

void plusUltra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  davomiylik = pulseIn(echoPin, HIGH);
  sm = davomiylik / 58;


  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin1, LOW);
  davomiylik1 = pulseIn(echoPin1, HIGH);
  sm1 = davomiylik1 / 58;

  
  Serial.print("ultrasonic: ");
  Serial.println(sm);
  Serial.print("ultrasonic1: ");
  Serial.println(sm1);
}

void setup() {
  //Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  delay(5000);             // 5 Sekund kutib turish
  motor1.setSpeed(65);    // Tezlik 0 dan 255 gacha o'zgartirish mumkin
  motor1.run(RELEASE);
  motor2.setSpeed(80);    // Tezlik 2- Motor uchun
  motor2.run(RELEASE);
  Serial.begin(9600);
}

void loop() {
  plusUltra();
  //Serial.println(sm);
  if ((sm < 50)||(sm1 < 50)) { //Agar 50 sm masofada biror raqib ko'rinsa
    if (jn == false) {
      motor1.run(RELEASE);   //Oldinga yuri
      motor2.run(RELEASE);
      delay(500);
      Serial.println("Break");
      motor1.run(FORWARD);   //Oldinga yuri
      motor2.run(BACKWARD);
      delay(500);
      jn = true;
    }
    motor1.run(FORWARD);   //Oldinga yuri
    motor2.run(FORWARD);
    delay(500);
  } else {                 //Raqib ko'rinmasa
    motor1.run(BACKWARD);  //O'nga burilib raqibni qidir
    motor2.run(FORWARD);
    delay(10);
    jn = false;
  }
}
