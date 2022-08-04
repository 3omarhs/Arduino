int Val = A0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  Val = analogRead(A0);
  Serial.print(Val);
}
