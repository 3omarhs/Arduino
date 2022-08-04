#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int m = 0, n = 0;
int out = 4;
int wrong = 3;
int countN=0;
int ijj;
char stopRepeated;
void(* resetFunc) (void) = 0;
bool lcdLight = false, lcdLight1 = false, lcdLight2 = false, notNum = false, lcdLight3 = false, stopRepeat = false;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
#include <EasyTransfer.h>
EasyTransfer ET;
struct DATA_STRUCTURE{
 int int_data;
 char char_data;
};
DATA_STRUCTURE myData;
String strData = "N";
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
  myData.char_data = '.';
      ET.sendData();
}

void loop() {
  lcd.setCursor(0, 1);
  if(lcdLight3 == true){
    if((lcdLight1 == true)&&(lcdLight3 == true)){
      notNum = false;
      if(lcdLight2 == false){
        lcd.backlight();
        clearLCD();
        lcd.setCursor(0, 1);
        lcd.print("Light ON...");
        delay(2000);
        clearLCD();
        lcdLight = false;
        lcdLight1 = false;
        lcdLight2 = true;
      }
      else{
        lcd.noBacklight();
        clearLCD();
        lcd.setCursor(0, 1);
        lcd.print("Light OFF..");
        delay(2000);
        clearLCD();
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
      lcdLight3 = false;
    }
  }
  
    if(ET.receiveData())
 {
 Serial.println(myData.char_data);
   if((myData.char_data != 'D')&&(myData.char_data != 'C')&&(myData.char_data != 'F')&&(myData.char_data != 'G')&&(myData.char_data != 'H')&&(myData.char_data != 'I')&&(myData.char_data != 'J')&&(myData.char_data != 'K')&&(myData.char_data != 'L')&&(myData.char_data != 'M')&&(myData.char_data != 'N')&&(myData.char_data != 'O')){
    lcdLight = false;
    lcdLight1 = false;
    lcdLight3 = false;
    countN = 0;
   }
   /*
   if(myData.char_data == 'F'){
      ijj = 0;
      Serial.println(ijj);
   }
   if(myData.char_data == 'G'){
      ijj = 1;
      Serial.println(ijj);
   }
   if(myData.char_data == 'H'){
      ijj = 2;
      Serial.println(ijj);
   }
   if(myData.char_data == 'I'){
      ijj = 3;
      Serial.println(ijj);
   }
   if(myData.char_data == 'J'){
      ijj = 4;
      Serial.println(ijj);
   }
   if(myData.char_data == 'K'){
      ijj = 5;
      Serial.println(ijj);
   }
   if(myData.char_data == 'L'){
      ijj = 6;
      Serial.println(ijj);
   }
   if(myData.char_data == 'M'){
      ijj = 7;
      Serial.println(ijj);
   }
   if(myData.char_data == 'N'){
      ijj = 8;
      Serial.println(ijj);
   }
   if(myData.char_data == 'O'){
      ijj = 9;
      Serial.println(ijj);
   }
   */
   if((myData.char_data == '1')||(myData.char_data == '2')||(myData.char_data == '3')||(myData.char_data == '4')||(myData.char_data == '5')||(myData.char_data == '6')||(myData.char_data == '7')||(myData.char_data == '8')||(myData.char_data == '9')||(myData.char_data == '0')||(myData.char_data == 'A')||(myData.char_data == 'B')){
    char ii = myData.char_data;
    myData.char_data = "..";
    myData.char_data = '.';
    if(notNum == false){
      clearLCD();
    }
    notNum = true;
    //strData = myData.char_data;
    
    charCounter++;
    //lcd.print(strData);
    lcd.setCursor(charCounter-1, 1);
    lcd.print(ii);
    
    delay(200);
    lcd.setCursor(charCounter-2, 1);
    countN++;
    lcd.print('*');
   }
  if(myData.char_data == '#'){
    charCounter = 0;
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Close Door");
    delay(2000);
    clearLCD();
  }
  if(myData.char_data == 'c'){
    notNum = false;
    charCounter = 0;
    strData = "N";
    delay(1000);
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Correct Password");
  }
  if((myData.char_data == 'C')&&(notNum == true)&&(charCounter != 0)){
    //lcd.setCursor(charCounter-(countN+1), 1);
    lcd.setCursor(charCounter-1, 1);
    lcd.print(" ");
    countN++;
    charCounter=charCounter-1;
  }
  if(myData.char_data == 'D'){
    lcdLight3 = true;
    clearLCD();
    charCounter = 0;
    strData = "N";
  }
  if(myData.char_data == '*'){
    resetFunc();
    charCounter = 0;
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("not Rest...");
  }
   
   if(myData.char_data == 'b'){
    charCounter = 0;
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Auto Close Door");
    
    delay(2000);
    clearLCD();
   }
   if(myData.char_data == 'w'){
    notNum = false;
    charCounter = 0;
    delay(1000);
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Wrong password");
   }
   /*if(myData.char_data == 'R'){
    //resetFunc();
    resetFunc();
   }*/
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
       notNum = false;
       clearLCD();
       lcd.setCursor(0, 1);
       lcd.print("Card Accepted");
      myData.char_data = '+';
      ET.sendData();
      delay(50);

      digitalWrite(out, LOW);
    }
    
    else
    {
      digitalWrite(wrong, HIGH);
      notNum = false;
      clearLCD();
      lcd.setCursor(0, 1);
      lcd.print("Wrong Card...");
      myData.char_data = '-';
      ET.sendData();
      delay(1000);
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  void clearLCD(){
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  
