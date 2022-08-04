/*(A0,A1,A2,A3,A4,A5,2,3)>>> KEYPAD , 4>>BUZZER , 5>>GREENLED , 6>>REDLED , 7>>BUTTONPIN , 8>>MOTOR , 9>>REVERSE , 10>>BUTTONPIN , 11>>INN , 12>>INN2  */
#include <Keypad.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EasyTransfer.h> 
EasyTransfer ET;
struct DATA_STRUCTURE{
 int int_data;
 char char_data;
};
unsigned long clearTime;
DATA_STRUCTURE myData;
//#include <LiquidCrystal_I2C.h>
//#include <Servo.h>
//Servo //servo;//Servo
//const int inn = 11;
//const int inn2 = 12;
const int buttonPin = 7;
const int buttonPinb = 10;
int motor = 8;
int reverse = 9;
int greenLed = 5;//Green led
int redLed = 6;//Red led
int buzzer = 4;//Buzzer
int reset = 11;

//LiquidCrystal lcd(12, 11, 10, 9, 8, 7);//LCD
//LiquidCrystal_I2C lcd(0x27,20,4);

bool dd0 = false, dd1 = false, bz_off = true;

const byte rows = 4;//rows
const byte columns = 4;//columns
char correctPassword[4] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[9];//Entered password on keypad
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

void setup()
{
pinMode(greenLed, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(redLed, OUTPUT);
pinMode(motor, OUTPUT);
pinMode(reverse, OUTPUT);
//pinMode(inn, INPUT);
//pinMode(inn2, INPUT);
pinMode(buttonPin, INPUT);
pinMode(buttonPinb, INPUT);
pinMode(reset, OUTPUT);
/*for(int j=0; j<=2; j++){
  digitalWrite(buzzer, HIGH);
delay(30);
digitalWrite(buzzer, LOW);
delay(50);
}*/

 //lcd.init();                      // initialize the lcd 
  //lcd.init();
 Serial.begin(9600);
 ET.begin(details(myData), &Serial);
  }

  
void square(){
Serial.println("# cloase the door");
myData.char_data = '#';
ET.sendData();
digitalWrite(greenLed, HIGH);
delay(100);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
digitalWrite(reverse, HIGH);
delay(400);
digitalWrite(greenLed, LOW);
delay(100);
digitalWrite(reverse, LOW);
delay(500);
j=0;
}


void D(){
Serial.println("D clear all digits enterd");
myData.char_data = 'D';
ET.sendData();

if(dd1 == true){
  if(bz_off == false){
    bz_off = true;
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    dd0 = false;
    dd1 = false;
    myData.char_data = 'p';
    ET.sendData();
    return;
  }
  else if(bz_off == true){
    bz_off = false;
    for(int i=0;i<=10;i++){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
    dd0 = false;
    dd1 = false;
    myData.char_data = 'q';
    ET.sendData();
    return;
  }
}
if(dd0 == true){
  dd0 = false;
  dd1 = true;
}
else if(dd0 == false){
  dd0 = true;
}
if(j>0){
enteredPassword[j=0] = charKey;
if(bz_off == false){
  digitalWrite(buzzer,HIGH);
  delay(250);
  digitalWrite(buzzer,LOW);
  }
}
else{
  if(bz_off == false){
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
  }
}
}


void C(){
Serial.println("C clear last digit enterd");
myData.char_data = 'C';
ET.sendData();
if(j>0){
  enteredPassword[j--] = charKey;
  if(bz_off == false){
    digitalWrite(buzzer,HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
  }
}
else{
  if(bz_off == false){
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
  }
}
clearTime = millis();
}


void star(){
Serial.println("* restart the RFID board");
myData.char_data = '*';
ET.sendData();
digitalWrite(reset, HIGH);
//myData.char_data = 'R';
//ET.sendData();
if(bz_off == false){
  for(i=1;i<=3;i++){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  digitalWrite(reset, LOW);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(100);
  delay(300);
  for(i=1;i<=3;i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  delay(600);
}
else{
  delay(300);
  digitalWrite(reset, LOW);
}
j = 0 ;
}


void buttonPinb0(){
Serial.println("buttonPin b   auto close system");
myData.char_data = 'b';
ET.sendData();
digitalWrite(greenLed, HIGH);
delay(100);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
else{
  delay(200);
}
delay(100);
digitalWrite(motor, HIGH);
delay(300);
digitalWrite(motor, LOW);
digitalWrite(reverse, HIGH);
delay(500);
digitalWrite(greenLed, LOW);
delay(100);
digitalWrite(reverse, LOW);
delay(500);
j=0;
}


void buttonPin0(){
Serial.println("buttonPin   open the door");
myData.char_data = 'p';
ET.sendData();
digitalWrite(greenLed, HIGH);
delay(100);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
digitalWrite(motor, HIGH);
delay(500);
digitalWrite(greenLed, LOW);
delay(100);
digitalWrite(motor, LOW);
}


void inn0(){
Serial.println("Door opened by a card \"RFID\"");
digitalWrite(greenLed, HIGH);
delay(100);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
}
digitalWrite(motor, HIGH);
delay(400);
digitalWrite(greenLed, LOW);
delay(600);
if(bz_off == false){
  digitalWrite(buzzer, LOW);
  delay(100);
}
digitalWrite(motor, LOW);
j = 0 ;
}


void inn20(){
digitalWrite(redLed, HIGH);
delay(200);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(300);
}
digitalWrite(redLed, LOW);
delay(100);
}


void charkey0(){
Serial.print("charKey: ");
myData.char_data = charKey;
ET.sendData();
Serial.println(charKey);
enteredPassword[j++] = charKey;
if(bz_off == false){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}
digitalWrite(redLed,HIGH);
digitalWrite(greenLed,HIGH);
  delay(100);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
clearTime = millis();
}


void correct(){
delay(200);
Serial.println("correct password    door opened");
myData.char_data = 'c';
ET.sendData();
digitalWrite(greenLed, HIGH);
digitalWrite(redLed, LOW);
digitalWrite(motor, HIGH);
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
ET.sendData();
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
}
delay(1000);
digitalWrite(motor, LOW);
j = 0;
}


void elsee(){
Serial.println("wrong password");
delay(500);
myData.char_data = 'w';
ET.sendData();
Serial.println("9 digits wrong");
digitalWrite(greenLed, LOW);
digitalWrite(redLed, HIGH);
digitalWrite(reverse, HIGH);
ET.sendData();
if(bz_off == false){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}
delay(1000);
digitalWrite(reverse, LOW);
j = 0;
}


/*void serial(){
char letter = Serial.read();
if(letter == '*'){
star();
}
if(letter == '#'){
square();
}
if(letter == '-'){
inn0();
}
if(letter == '+'){
correct();
}
if(letter == '/'){
buttonPin0();
}
if(letter == '.'){
buttonPinb0();
} 
if(isDigit(letter)){
charKey = letter;
charkey0();
}
if(letter == 'c'){
C();
}
if(letter == 'd'){
D();
}
}*/

/*void readRx(){
if(ET.receiveData())
 {
   if((myData.char_data != '+')||(myData.char_data != '-')){
    Serial.print("");
   }
 }*/

void sorce_code(){
  if((millis() - clearTime >= 15000)&&(millis() - clearTime <= 15100)){
    myData.char_data = 'd';
    ET.sendData();
    j=0;
  }
  
if(ET.receiveData()){
  if(myData.char_data == '+'){
    inn0();
  }
  if(myData.char_data == '-'){
    inn20();
  }
  /*else
    Serial.print("");*/
}
if (charKey == '#')
square();

/*if(Serial.available() > 0){
serial();
}*/

if(charKey == 'D')
D();

if((charKey == 'A')||(charKey == 'B')||(charKey == 'C')||(charKey == '1')||(charKey == '2')||(charKey == '3')||(charKey == '4')||(charKey == '5')||(charKey == '6')||(charKey == '7')||(charKey == '8')||(charKey == '9')||(charKey == '0')||(charKey == '*')||(charKey == '#')){
  dd0 = false;
  dd1 = false;
}

if (charKey == 'C')
C();

if (charKey == '*')
star();


/*val = digitalRead(buttonPinb);
if (val == HIGH)
buttonPinb0();

val = digitalRead(buttonPin);
if (val == HIGH)
buttonPin0();
*/
/*val = digitalRead(inn);
if (val == HIGH)
inn0();

val = digitalRead(inn2);
if (val ==HIGH)
inn20();
*/
charKey = kpad.getKey();
if(charKey&&charKey!='#'&&charKey!='*'&&charKey!='D'&&charKey!='C')
charkey0();

//if ( j== 4){
//char correctPassword[4] = {'7','9','5','9'};//Correct password
//if ((strncmp(enteredPassword, correctPassword, 4)==  0))
//correct();
//}

//if ( j== 8){
//char correctPassword[8] = {'A','B','A','B','1','2','1','2'};//Correct password
//if ((strncmp(enteredPassword, correctPassword, 8)==  0))
//correct();
//}

if (j == 8)
{
char correctPassword[8] = {'7','7','7','8','7','9','8','7'};//Correct password
if ((strncmp(enteredPassword, correctPassword, 8)==  0))
correct();
///////////////////
else
elsee();
///////////////////
}

//if (j == 9)
//{
//char correctPassword[9] = {'2','0','1','9','1','0','1','5','5'};//Correct password
//if ((strncmp(enteredPassword, correctPassword, 9)==  0))
//correct();
////else
////elsee();
//}
}

void loop(){///////////////////////////////////////////////////////////////////////////////////////////////
val = digitalRead(buttonPin);
  if (val == HIGH)
    buttonPinb0();
while(digitalRead(buttonPin) != 0){
//  val = digitalRead(buttonPin);
//  if (val == HIGH)
//    buttonPinb0();
  sorce_code();
}
sorce_code();

}