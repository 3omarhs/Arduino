int Read = A5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int reading = analogRead(A5);
if(reading !=0)
  Serial.println(reading);
}
