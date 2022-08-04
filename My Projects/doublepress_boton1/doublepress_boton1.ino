const int button  = 4;
int j = 1, val = 0;

///
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
///

void setup() {
  pinMode(button, INPUT);
  button == LOW;

  ///
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  ///

}

void loop() {


  val = digitalRead(button);

  digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, LOW);
  if (val == 1) {
    if (j == 1) {

      ///
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(300);
      Serial.println(j);
      ///
      
      button == LOW;
      val = 0;
      val = digitalRead(button);
      if (val == 0) {
        j = 2;
      }
    }
  }
  if (val == 1) {
    if (j == 2) {

      ///
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(300);
      Serial.println(j);
      ///
      
      val = 0;
      button == LOW;
      val = digitalRead(button);
      if (val == 0) {
        j = 3;
      }
    }
  }
  if (val == 1) {
    if (j == 3) {

      ///
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      delay(300);
      Serial.println(j);
      ///
      
      button == LOW;
      val = 0;
      val = digitalRead(button);
      if (val == 0) {
        j = 4;
      }
    }
  }
  if (val == 1) {
    if (j == 4) {

      ///
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      delay(300);
      Serial.println(j);
      ///
      
      button == LOW;
      val = 0;
      val = digitalRead(button);
      if (val == 0) {
        j = 1;
      }
    }
  }
}
