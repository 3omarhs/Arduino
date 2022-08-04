const int buttonPin1 = 2;
const int buttonPin2 = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  if(digitalRead(buttonPin1) == HIGH){
    digitalWrite(led4, LOW);
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led1, HIGH);
  }

  if(digitalRead(buttonPin2) == HIGH){
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
}
