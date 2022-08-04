const int button = 3;
int relay = 2;
int val;
void setup() {
  // put your setup code here, to run once:
pinMode(relay, OUTPUT);
pinMode(button, INPUT);
digitalWrite(relay, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(button);
if(val == HIGH){
  digitalWrite(relay, LOW);
  delay(10000);
  digitalWrite(relay, HIGH);
}
}
