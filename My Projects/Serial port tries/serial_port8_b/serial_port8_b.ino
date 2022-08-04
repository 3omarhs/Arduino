void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
}

void loop() {
  for(int i=0; i<=9; i++){
    analogWrite(A0, i);
    delay(500);
  }
}
