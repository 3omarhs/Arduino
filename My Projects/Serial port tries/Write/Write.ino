int Write = A5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i<=9; i++){
  analogWrite(A5, i);
  Serial.println(i);
  delay(100);
}
}
