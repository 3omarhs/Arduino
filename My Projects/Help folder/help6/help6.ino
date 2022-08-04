#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
bool n = false , m = false;
int relay1 = 2;
int relay2 = 3;
int buzzer = 4;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
  
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
    
    readCard();
    if((m == true) && (n == false)){
      Serial.println("card accepted");
      digitalWrite(relay1, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);///////////////////////////////////
      digitalWrite(relay1, LOW);
      digitalWrite(buzzer, LOW);
      n = true;
      m = false;
      Serial.print("Now it`s working, tap card again to stop: ");
    }
    readCard();
    if((m == true) && (n == true)){
      Serial.print("Now it`s stopped: ");
      doubleBeeb();
      digitalWrite(relay2, HIGH);
      delay(500);///////////////////////////////////
      digitalWrite(relay2, LOW);
      n = false;
    }
    
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
void readCard(){
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
    if ((strID.indexOf("B1:CA:C5:20") >= 0)||(strID.indexOf("*:*:**:**") >= 0)||(strID.indexOf("*:*:**:**") >= 0)||(strID.indexOf("*:*:**:**") >= 0)||(strID.indexOf("*:*:**:**") >= 0))
    {//////////////////////////////////////////////
      m = true;
    }
}

void doubleBeeb(){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
}
