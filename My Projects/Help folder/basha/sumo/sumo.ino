#include <NewPing.h>
#define MIN 0
#define MAX 45


int trigPin1 = 8;  //
int echoPin1 = 9;
int dist1 = 0;

int trigPin2 = 10;  //
int echoPin2 = 11;
int dist2 = 0;

int distance = 80;

NewPing sonar1(trigPin1, echoPin1, distance);
NewPing sonar2(trigPin2, echoPin2, distance);

void oldinga() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
}
void chapga() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  analogWrite(5, 255);
  delay(5000);

}
int Tic = 0;

void loop() {
  dist1 = sonar1.ping_cm();
  dist2 = sonar2.ping_cm();

if (dist1 > MIN && dist1 < MAX || dist2 > MIN && dist2 < MAX) {
 
   oldinga();
    delay(300);
  } else {
   chapga();
     delay(100);
  
  }


  //Serial.print(dist1),  Serial.print(" ");
  //Serial.print(dist2),  Serial.println(" ");
 
  delay(1);
}
