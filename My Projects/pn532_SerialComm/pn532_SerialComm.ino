/*

  PN532 NFC RFID Module (v3)

  Quick Test Code v2

  Based on an example code from PN532 Arduino Library

  Tailored for HSUART & Arduino Uno

  T.K.Hareendran/2019

  www.electroschematics.com

*/

#include <SoftwareSerial.h>
#include <PN532_SWHSU.h>
#include <PN532.h>
SoftwareSerial SWSerial( 10, 11 ); // RX, TX
PN532_SWHSU pn532swhsu( SWSerial );
PN532 nfc( pn532swhsu );
String RFval = "";

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello Maker!");
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't Find PN53x Module");
    while (1); // Halt
  }// Got valid data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);
  // Configure board to read RFID tags
  nfc.SAMConfig();
  Serial.println("Waiting for an ISO14443A Card ...");

}

void loop(void) {
  RFval = "";
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                       // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  if (success) {
//    Serial.print("UID Value: ");
    for (uint8_t i = 0; i < uidLength; i++)
    {
//      Serial.print(" 0x"); Serial.print(uid[i], HEX);
      RFval += (uid[i]);
    }
//    Serial.println("");
    Serial.print("my card: ");
    Serial.print(RFval);
    Serial.print(", ");
    
    if ((RFval == "2505723392")||(RFval == "83128933")) {
      Serial.println("correct");
    }
    else {
      Serial.println("wrong card");
    }
    delay(1000);
  }
}

void RFID_read(){
  RFval = "";
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                       // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  if (success) {
    for (uint8_t i = 0; i < uidLength; i++)
    {
      RFval += (uid[i]);
    }
    Serial.print("my card: ");
    Serial.print(RFval);
    Serial.print(", ");
    
    if ((RFval == "2505723392")||(RFval == "83128933")) {
      Serial.println("correct");
    }
    else {
      Serial.println("wrong card");
    }
  }
}
