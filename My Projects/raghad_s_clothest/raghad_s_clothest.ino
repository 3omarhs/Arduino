#include <Servo.h>
#include <elapsedMillis.h>
#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
int m = 0, n = 0, val;
int buzzer = 4;
const int buttonPin = 5;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
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


void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(switchPin, INPUT);
   myservo.attach(servoPin);
   randomSeedVar = analogRead(5);     //generates a pseudo random seed by analog reading an empty pin (more info here: https://programmingelectronics.com/using-random-numbers-with-arduino/)
   randomSeed(randomSeedVar);
   myservo.write(180);
   pinMode(buzzer, OUTPUT);
   pinMode(buttonPin, INPUT);
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
}

void servo_open(){
delayMin = analogRead(dialPinMin);
//  delayMax = analogRead(dialPinMax);
//  delayMin = map(delayMin, 0, 1023, 5000, 0);
//  delayMax = map(delayMax, 0, 1023, 0, 10000);
  switchPressed = digitalRead(switchPin);
  //if(switchPressed) {     //if switch is pressed, move the servo to turn the switch back off.
      myservo.write(30);
      servoMoved = false;
      delay(2000);
  //}
  //else if(!servoMoved) {     //once the switch has been turned off, the servo will wait a random amount of time before moving back to its original position.
        randomNum = random(delayMin, delayMax);
        delayTimeElapsed = timeElapsed/2;
        while(timeElapsed < delayTimeElapsed + randomNum) {     //debugging data will continue to be printed while delaying.
          //debug(true);
        }
        //myservo.write(0);
        //servoMoved = true;
  //}
  timeElapsedSec = timeElapsed / 1000;
  //debug(false);
}



void servo_close(){
  delayMin = analogRead(dialPinMin);
   switchPressed = digitalRead(switchPin);
    myservo.write(180);
      servoMoved = false;
      delay(2000);
}


void loop(){
  
    val = digitalRead(buttonPin);// cloase
  if (val == HIGH)
  {
    Serial.print("button prissed");
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(100);
    servo_close();
  }
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
    
    
    if ((strID.indexOf("22:83:4C:63") >= 0)||(strID.indexOf("59:B9:D9:2A") >= 0))
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      servo_open();
      Serial.println("card accepted");
      
    }
    /*else if (strID.indexOf("59:B9:D9:2A") >= 0)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      servo_open();
      Serial.println("card accepted");
      
    }*/
    else
    {
      
      Serial.println("***WARNING: unconfirmed card \"new card\"");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
