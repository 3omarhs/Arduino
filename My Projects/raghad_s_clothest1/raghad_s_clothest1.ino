#include <Servo.h>
#include <Keypad.h> 
#include <elapsedMillis.h>
/*#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
int m = 0, n = 0;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;*/
int buzzer = 4;
#define switchPin 7
#define servoPin 8
#define dialPinMin 0
#define dialPinMax 1
Servo myservo;
elapsedMillis timeElapsed;
long timeElapsedSec;
long delayTimeElapsed;
bool switchPressed;
int servoPos;
long randomNum;
long randomSeedVar;
bool servoMoved = false;
float delayMin;
float delayMax;
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
//  SPI.begin();
//  rfid.PCD_Init();
pinMode(switchPin, INPUT);
   myservo.attach(servoPin);
   randomSeedVar = analogRead(5);     //generates a pseudo random seed by analog reading an empty pin (more info here: https://programmingelectronics.com/using-random-numbers-with-arduino/)
   randomSeed(randomSeedVar);
   myservo.write(0);
   pinMode(buzzer, OUTPUT);
}

void servo(){
delayMin = analogRead(dialPinMin);
//  delayMax = analogRead(dialPinMax);
//  delayMin = map(delayMin, 0, 1023, 5000, 0);
//  delayMax = map(delayMax, 0, 1023, 0, 10000);
  switchPressed = digitalRead(switchPin);
  //if(switchPressed) {     //if switch is pressed, move the servo to turn the switch back off.
      myservo.write(180);
      servoMoved = false;
      delay(2000);
  //}
  //else if(!servoMoved) {     //once the switch has been turned off, the servo will wait a random amount of time before moving back to its original position.
        randomNum = random(delayMin, delayMax);
        delayTimeElapsed = timeElapsed/2;
        while(timeElapsed < delayTimeElapsed + randomNum) {     //debugging data will continue to be printed while delaying.
          //debug(true);
        }
        myservo.write(0);
        servoMoved = true;
  //}
  timeElapsedSec = timeElapsed / 1000;
  //debug(false);
}





/*
void loop0(){
  {
    
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
      return;
    // Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
    // Serial.println(rfid.PICC_GetTypeName(piccType));
    // Check is the PICC of Classic MIFARE type
    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
      Serial.println(F("Your tag is not of type MIFARE Classic."));
      return;
    }
    String strID = "";
    for (byte i = 0; i < 4; i++) {
      strID +=
        (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
        String(rfid.uid.uidByte[i], HEX) +
        (i != 3 ? ":" : "");
    }
    strID.toUpperCase();
    Serial.print("Tap card key: ");
    Serial.println(strID);
    
    
    if (strID.indexOf("22:83:4C:63") >= 0)
    {
      
      servo();
      Serial.println("card accepted");
      digitalWrite(out, HIGH);
      delay(250);
      digitalWrite(out, LOW);
    }
    else
    {
      myservo.write(0);
      Serial.println("***WARNING: unconfirmed card \"new card\"");
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
*/
void loop(){
  delayMin = analogRead(dialPinMin);
   switchPressed = digitalRead(switchPin);
  if(charKey == '#')
{
enteredPassword[i=0] = charKey;
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}

if(charKey == 'D'){
digitalWrite(buzzer,HIGH);
delay(500);
digitalWrite(buzzer,LOW);
myservo.write(0);
}

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

charKey = kpad.getKey();
if(charKey&&charKey!='#'&&charKey!='*'&&charKey!='D')
{
enteredPassword[i++] = charKey;
Serial.print("key");
Serial.println(charKey);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}
if ( i== 4){
delay(200);
char correctPassword[4] = {'1','2','3','4'};//Correct password
if ((strncmp(enteredPassword, correctPassword, 4)==  0))
{
Serial.println("correct pascode");
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(100);
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(100);
myservo.write(180);
  i = 0;
}
else
Serial.println("wrong pascode");
}
}
}
/* void loop(){
  loop1();
  }
*/
