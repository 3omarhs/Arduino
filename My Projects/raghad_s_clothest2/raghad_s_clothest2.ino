#include <Servo.h>
#include <Keypad.h> 
int buzzer = 4;
#define switchPin 7
#define servoPin 8
#define dialPinMin 0
#define dialPinMax 1
Servo myservo;
const byte rows = 4;//rows
const byte columns = 4;//columns
char correctPassword[4] = {'1', '2', '3', '4'}; //Correct password
char enteredPassword[9];//Entered password on keypad
char charKey;//Key on keypad 
int i = 0;
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


void setup() {
 Serial.begin(9600);
pinMode(switchPin, INPUT);
   myservo.attach(servoPin);
   myservo.write(0);
   pinMode(buzzer, OUTPUT);
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
}





void loop()
{
if (charKey == '*')
{
if(i>0){
enteredPassword[i--] = charKey;
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}
}
 if(charKey == 'D')
{
enteredPassword[i=0] = charKey;
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}

if(charKey == '#'){
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
myservo.write(0);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
}

charKey = kpad.getKey();
if(charKey&&charKey!='#'&&charKey!='*'&&charKey!='D')
{
  Serial.println(charKey);
enteredPassword[i++] = charKey;
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}
if (i == 4)
{
delay(200);
char correctPassword[4] = {'1','2','3','4'};//Correct password
if ((strncmp(enteredPassword, correctPassword, 4)==  0))
{
myservo.write(180);
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(100);
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(1000);
i = 0;
}
else
{
  myservo.write(0);
digitalWrite(buzzer, HIGH);
delay(2000);
digitalWrite(buzzer, LOW);
delay(100);
i = 0;
}}}
