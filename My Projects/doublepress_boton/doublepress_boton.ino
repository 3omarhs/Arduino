const int button  = 4;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
  int j = 1, val = 0;
void setup() {
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
      button == LOW;
}

void loop() {


  val = digitalRead(button);
  Serial.println(val);

  digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, LOW);
  if (val == 1) {
    if (j == 1) {
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      val = 0;
      j = 2;
      delay(300);
      button == LOW;
        Serial.println(j);
    }
    else digitalWrite(9, LOW);
  }
  else digitalWrite(9, LOW);
  if (val == 1) {
    if (j == 2) {
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      val = 0;
      j = 3;
      delay(300);
      button == LOW;
        Serial.println(j);
    }
  }
  else digitalWrite(9, LOW);
  if (val == 1) {
    if (j == 3) {
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      val = 0;
      j = 4;
      delay(300);
      button == LOW;
        Serial.println(j);
    }
  }
  else digitalWrite(9, LOW);
  if (val == 1) {
    if (j == 4) {
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      val = 1;
      delay(300);
      button == LOW;
        Serial.println(j);
    }
  }
  else digitalWrite(9, LOW);
}
