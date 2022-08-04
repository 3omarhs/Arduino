byte led = 5, light = 128;
int i = 0;
void setup() {
pinMode(led, OUTPUT);
}

void loop() 
{
  for(i=0; i<=20; i++){
  light = i;
  analogWrite(led, light);
  delay(100);
}

 for(i=20; i>=0; i--){
  light = i;
  analogWrite(led, light);
  delay(100);
}
}
