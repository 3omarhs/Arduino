int vrs1 = 3;  
int vrs2 = 4;
int motoresis1 = 5;
int motoresis2 = 6;

void setup() {
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
Serial.begin(9600);
}

void loop() {
{int value = analogRead(vrs1);
int motoresis11 = value/4;
analogWrite(motoresis1,motoresis11);
Serial.println(motoresis11);}

{int value2 = analogRead(vrs2);
int motoresis22 = value2;
analogWrite(motoresis2,motoresis22);
Serial.println(motoresis22);}
}
