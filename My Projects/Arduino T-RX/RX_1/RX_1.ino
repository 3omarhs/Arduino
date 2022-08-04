void setup(){
  Serial.begin(9600);
}
byte b1,b2;
void loop(){
  b1=Serial.read();
  Serial.println(b1);
  delay(1000);
  b2=Serial.read();
  Serial.println(b1);
  //Serial.println(b1);
}
