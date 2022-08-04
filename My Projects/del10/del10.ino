#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int m = 0, n = 0;
int out = 4;
int wrong = 3;
bool lcdLight = false, lcdLight1 = false, lcdLight2 = false;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
#include <EasyTransfer.h>
EasyTransfer ET;
struct DATA_STRUCTURE{
 int int_data;
 char char_data;
};
DATA_STRUCTURE myData;
String strData = "";
String strData1;
int charCounter=0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(out, OUTPUT);
  pinMode(wrong, OUTPUT);
 ET.begin(details(myData), &Serial);
 
  lcd.noBacklight();
  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print("Restarted...");
}

void loop() {
  lcd.setCursor(0, 1);
  if(myData.char_data == 'D'){
    if(lcdLight1 == true){
      if(lcdLight2 == false){
        lcd.backlight();
        clearLCD();
        lcd.setCursor(0, 1);
        lcd.print("Light ON          ");
        lcdLight = false;
        lcdLight1 = false;
        lcdLight2 = true;
      }
      else{
        lcd.noBacklight();
        clearLCD();
        lcd.setCursor(0, 1);
        lcd.print("Light OFF         ");
        lcdLight = false;
        lcdLight1 = false;
        lcdLight2 = false;
      }
    }
      lcdLight = true;
  }
  if(myData.char_data == 'C'){
    if(lcdLight == true){
      lcdLight1 = true;
    }
  }
  
    if(ET.receiveData())
 {
 Serial.println(myData.char_data);
   if((myData.char_data == '1')||(myData.char_data == '2')||(myData.char_data == '3')||(myData.char_data == '4')||(myData.char_data == '5')||(myData.char_data == '6')||(myData.char_data == '7')||(myData.char_data == '8')||(myData.char_data == '9')||(myData.char_data == '0')||(myData.char_data == 'A')||(myData.char_data == 'B')){
    if(strData == ""){
      clearLCD();
    }
    strData = myData.char_data;
    lcd.setCursor(charCounter, 1);
    charCounter++;
    lcd.print(strData);
   }
  if(myData.char_data == '#'){
    lcd.setCursor(0, 1);
    strData1 = myData.char_data + ", close Door       ";
    lcd.print(strData1);
  }
  if(myData.char_data == 'c'){
    lcd.setCursor(0, 1);
    lcd.print("Correct Password");
  }
  if(myData.char_data == 'C'){
    lcd.setCursor(charCounter-1, 1);
    lcd.print(" ");
  }
  if(myData.char_data == 'D'){
    lcd.setCursor(0, 1);
    charCounter = 0;
    strData = "";
    lcd.print("                     ");
  }
  if(myData.char_data == '*'){
    strData1 = myData.char_data + "                       ";
    lcd.print(strData1);
  }
   
   if(myData.char_data == 'b'){
    lcd.setCursor(0, 1);
    lcd.print("Auto Close Door       ");
   }
   if(myData.char_data == 'w'){
    lcd.setCursor(0, 1);
    lcd.print("Wrong password        ");
   }
 //lcd.print(myData.char_data);
 delay(250);
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
    if ((strID.indexOf("54:27:4C:D3") >= 0)||(strID.indexOf("59:26:E9:A9") >= 0)||(strID.indexOf("1E:F5:0B:FA") >= 0)||(strID.indexOf("59:26:E9:A9") >= 0)||(strID.indexOf("59:B9:D9:2A") >= 0)||(strID.indexOf("09:C4:E4:2A") >= 0)||(strID.indexOf("F2:71:5A:D3") >= 0)||(strID.indexOf("8A:FA:E3:81") >= 0))
    {
       Serial.println("card accepted");
       lcd.print("Card Accepted       ");
      digitalWrite(out, HIGH);
      delay(250);

      digitalWrite(out, LOW);
    }
    
    else
    {
      digitalWrite(wrong, HIGH);
      lcd.print("Wrong Card          ");
      delay(1000);
      digitalWrite(wrong, LOW);
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  void clearLCD(){
    lcd.setCursor(0, 1);
    lcd.print("                                    ");
  }
