const int IR_Sensor = 2;
int relay = 3;
int x = 1;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(IR_Sensor,INPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
}

void loop() {
  x = digitalRead(IR_Sensor);
  while(x == LOW){
    x = digitalRead(IR_Sensor);
    digitalWrite(relay, LOW);
    delay(800);
    digitalWrite(relay, HIGH);
    //Serial.println("relay on");
    x = digitalRead(IR_Sensor);
    delay(1000);
    x = digitalRead(IR_Sensor);
  }
  digitalWrite(relay, HIGH);
  //else{
    //digitalWrite(relay, HIGH);
    //Serial.println("relay off");
  //}
  //Serial.println(digitalRead(IR_Sensor));
  //delay(500);
}
