byte X = 3, Y = 4, led = 5, light = 128;

void setup() {
pinMode(X, INPUT);
pinMode(Y, INPUT);
pinMode(led, OUTPUT);
}

void loop() /*{
{int value = analogRead(vrs1);
int motoresis11 = value/4;
analogWrite(motoresis1,motoresis11);
Serial.println(motoresis11);}

{int value2 = analogRead(vrs2);
int motoresis22 = value2;
analogWrite(motoresis2,motoresis22);
Serial.println(motoresis22);}
}*/
{
  if(digitalRead(X))
  light = light + 5;

   if(digitalRead(Y))
  light = light - 5;

  analogWrite(led, light);
  delay(500);
}
