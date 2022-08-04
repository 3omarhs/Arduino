#include <Keypad.h> 

const byte rows = 4;//rows
const byte columns = 4;//columns
char charKey;//Key on keypad 
int i = 0;  //for loop
int j = 0;  //digits entred
int val = 0;//Counter
char keypad[4][4] =//Keypad array
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowsPins[4] = {A0, A1, A2, A3};//Rows pins
byte columnspPins[4] = {A4, A5, 2, 3};//Columns pins

Keypad kpad = Keypad(makeKeymap(keypad),
rowsPins, columnspPins, 4, 4);//Keypad map


const int button = 4;
int relay = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(relay, OUTPUT);
pinMode(button, INPUT);
digitalWrite(relay, HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
/*val = digitalRead(button);
if(val == HIGH){
  digitalWrite(relay, LOW);
  delay(10000);
  digitalWrite(relay, HIGH);
}*/
charKey = kpad.getKey();
if(charKey == 'B'){
  Serial.print("B");
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(relay, HIGH);
}
if(charKey == '6'){
  Serial.print("6");
  digitalWrite(relay, LOW);
  delay(3500);
  digitalWrite(relay, HIGH);
}
if(charKey == '5'){
  Serial.print("5");
  digitalWrite(relay, LOW);
  delay(5000);
  digitalWrite(relay, HIGH);
}
if(charKey == '4'){
  Serial.print("4");
  digitalWrite(relay, LOW);
  delay(7000);
  digitalWrite(relay, HIGH);
}
if(charKey == 'C'){
  Serial.print("C");
  digitalWrite(relay, LOW);
  delay(10000);
  digitalWrite(relay, HIGH);
}
if(charKey == '9'){
  Serial.print("9");
  digitalWrite(relay, LOW);
  delay(15000);
  digitalWrite(relay, HIGH);
}
if(charKey == '8'){
  Serial.print("8");
  digitalWrite(relay, LOW);
  delay(20000);
  digitalWrite(relay, HIGH);
}
if(charKey == '7'){
  Serial.print("7");
  digitalWrite(relay, LOW);
  delay(22000);
  digitalWrite(relay, HIGH);
}
if(charKey != '-'){
  Serial.print(charKey);
}

}
