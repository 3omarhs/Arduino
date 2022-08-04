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
if(charKey == '4'){
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(relay, HIGH);
  Serial.print("4");
}
if(charKey == '5'){
  digitalWrite(relay, LOW);
  delay(3500);
  digitalWrite(relay, HIGH);
  Serial.print("5");
}
if(charKey == '6'){
  digitalWrite(relay, LOW);
  delay(5000);
  digitalWrite(relay, HIGH);
  Serial.print("6");
}
if(charKey == 'B'){
  digitalWrite(relay, LOW);
  delay(7000);
  digitalWrite(relay, HIGH);
  Serial.print("B");
}

}
