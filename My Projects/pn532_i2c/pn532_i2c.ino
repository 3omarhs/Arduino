// for I2C Communication
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
String tagId = "None";
byte nuidPICC[4];
void setup(void) {
 Serial.begin(9600);
 Serial.println("System initialized");
 nfc.begin();
}
void loop() {
 readNFC();
}
void readNFC() {
 if (nfc.tagPresent())
 {
   NfcTag tag = nfc.read();
   tag.print();
   Serial.print("ID == ");
   Serial.println(tag.getUidString());
   tagId = tag.getUidString();
 }
 delay(500);
}
