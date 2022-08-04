const int buttonpin = 2;
int x = 3;
void setup() {
  pinMode(buttonpin, INPUT);
  pinMode(x, OUTPUT);
}

void loop() {
  int val = digitalRead(buttonpin);
if(val == HIGH){
  digitalWrite(x, HIGH);
    delay(100);  //change time here
    digitalWrite(x, LOW);
}
}
