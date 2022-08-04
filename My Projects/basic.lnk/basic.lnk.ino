int led = 12;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(12, 10028);
  //delay(3000);
  digitalWrite(12, LOW);
  delay(300);
}
