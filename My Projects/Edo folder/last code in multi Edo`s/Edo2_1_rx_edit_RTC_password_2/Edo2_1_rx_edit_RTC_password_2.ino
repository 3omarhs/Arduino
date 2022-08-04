#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <EasyTransfer.h>
EasyTransfer ET;

#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = A0;


int m = 0, n = 0;
int out = 4;
int wrong = 3;
int countN=0;
int ijj;

//int led_Count = 0;

String password = "", correct_pass = "", Hours, Hours1, correct_pass_1 = "", correct_pass_2 = "";
unsigned long myTime;
char stopRepeated;
void(* resetFunc) (void) = 0;
bool lcdLight = false, lcdLight1 = false, lcdLight2 = false, notNum = false, lcdLight3 = false, stopRepeat = false, lcdLight4 = false;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
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

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  
 ET.begin(details(myData), &Serial);
 
  lcd.noBacklight();
  lcd.init();
//  lcd.setCursor(1, 0);
//  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print("Restarted...");
  myData.char_data = '.';
      ET.sendData();
}

void loop() {
  
  lcd.setCursor(0, 0);
  if(rtc.getHour() > 12)
    Hours = (String)(int(rtc.getHour()) - 12);
  else if(rtc.getHour() == 0)
    Hours = "12";
  lcd.print(Hours);
  lcd.print(":");
  lcd.print(rtc.getMinute());
  lcd.setCursor(7, 0);
  lcd.print(rtc.getWeekday());
  lcd.setCursor(12, 0);
  lcd.print(rtc.getMonth());
  lcd.print("/");
  lcd.print(rtc.getDay());
  
  if(rtc.getHour() > 12)
    Hours = (String)(int(rtc.getHour()) - 12);
  else if(rtc.getHour() == 0)
    Hours = "12";
  else{
    Hours = (String)int(rtc.getHour());
  }
  String sss = (String)int(rtc.getMinute());
  correct_pass = "3";
  correct_pass += sss[sss.length() -1];
  correct_pass += (String)int(rtc.getWeekday());
  sss = Hours;
  correct_pass += sss[sss.length() -1];
  sss = (String)int(rtc.getDay());
  correct_pass += sss[sss.length() -1];
  Serial.print("correct_pass: ");Serial.println(correct_pass);
  
  if(password == correct_pass){
    password = "";
    myData.char_data = '+';
    ET.sendData();
    lcd.setCursor(0, 1);
    lcd.print("RTC password..");
    myTime = millis();
  }
  
//////////////////////////////***************************************////////////////////////////////////////////////////////////////

  if(rtc.getHour() > 12)
    Hours1 = (String)(int(rtc.getHour()) - 12 + 3);
  else if(rtc.getHour() == 0)
    Hours1 = "12";
  else{
    Hours1 = (String)int(rtc.getHour());
  }
  String sss1 = (String)(int(rtc.getMinute() + 3));
  correct_pass_1 = "3";
  correct_pass_1 += sss1[sss1.length() -1];
  correct_pass_1 += (String)(int(rtc.getWeekday()) - 3);
  sss1 = Hours1;
  correct_pass_1 += sss1[sss1.length() -1];
  sss1 = (String)(int(rtc.getDay()) - 3);
  correct_pass_1 += sss1[sss1.length() -1];

  //(3 LM+3 WD-3 LH LDN-3) >>> if < or > original >>> = 3
  
  correct_pass_2 = "";
  for(int i=0; i<=correct_pass_1.length()-1; i++){
    if(((String)correct_pass_1[i] != "0")&&((String)correct_pass_1[i] != "1")&&((String)correct_pass_1[i] != "2")&&((String)correct_pass_1[i] != "3")&&((String)correct_pass_1[i] != "4")&&((String)correct_pass_1[i] != "5")&&((String)correct_pass_1[i] != "6")&&((String)correct_pass_1[i] != "7")&&((String)correct_pass_1[i] != "8")&&((String)correct_pass_1[i] != "9")){
      correct_pass_2 += "3";
    }
    else
      correct_pass_2 += (String)correct_pass_1[i];
    }
  Serial.print("correct_pass1: ");Serial.println(correct_pass_2);
  
  if(password == correct_pass_2){
    password = "";
    myData.char_data = '+';
    ET.sendData();
    lcd.setCursor(0, 1);
    lcd.print("RTC password1..");
    myTime = millis();
  }
  
//  Serial.print("Time: ");
//  Serial.println(rtc.formatTime());
  
  if((millis() - myTime >= 5000)&&(millis() - myTime <= 5100))
    clearLCD();
  lcd.setCursor(0, 1);
  LCDlight();
  
  
    if(ET.receiveData())
 {
 Serial.println(myData.char_data);
   if((myData.char_data != 'D')&&(myData.char_data != 'C')&&(myData.char_data != 'F')&&(myData.char_data != 'G')&&(myData.char_data != 'H')&&(myData.char_data != 'I')&&(myData.char_data != 'J')&&(myData.char_data != 'K')&&(myData.char_data != 'L')&&(myData.char_data != 'M')&&(myData.char_data != 'N')&&(myData.char_data != 'O')){
    lcdLight = false;
    lcdLight1 = false;
    lcdLight3 = false;
    countN = 0;
   }
   
   if((myData.char_data == '1')||(myData.char_data == '2')||(myData.char_data == '3')||(myData.char_data == '4')||(myData.char_data == '5')||(myData.char_data == '6')||(myData.char_data == '7')||(myData.char_data == '8')||(myData.char_data == '9')||(myData.char_data == '0')||(myData.char_data == 'A')||(myData.char_data == 'B')){
    password += myData.char_data;
    char ii = myData.char_data;
    myData.char_data = "..";
    myData.char_data = '.';
    myTime = 0;
    if(notNum == false){
      clearLCD();
    }
    notNum = true;
    //strData = myData.char_data;
    charCounter++;
    led_Counter(charCounter);
    //lcd.print(strData);
    lcd.setCursor(charCounter-1, 1);
    lcd.print(ii);
    delay(100);
    lcd.setCursor(charCounter-2, 1);
    countN++;
    lcd.print('*');
   }
   
  if(myData.char_data == '#'){     //close door
    charCounter = 0;
    led_Counter(charCounter);
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Close Door");
    myTime = millis();
  }
  
  if(myData.char_data == 'c'){   //correct pass..
    notNum = false;
    charCounter = 0;
    led_Counter(charCounter);
    strData = "N";
    delay(1000);
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Correct Password");
  }
  if((myData.char_data == 'C')&&(notNum == true)&&(charCounter != 0)){     //clear last digit..
    //lcd.setCursor(charCounter-(countN+1), 1);
    lcd.setCursor(charCounter-1, 1);
    lcd.print(" ");
    countN++;
    charCounter=charCounter-1;
    led_Counter(charCounter);
    password = password.substring(0, password.length() - 1);
  }
  
  if(myData.char_data == 'd'){    //clear password by delay..
    clearLCD();
    charCounter = 0;
    led_Counter(charCounter);
  }
  if(myData.char_data == 'D'){    //clear password by D..
    lcdLight3 = true;
    clearLCD();
    charCounter = 0;
    led_Counter(charCounter);
    strData = "N";
    password = "";
  }
  
  if(myData.char_data == '*'){    //restart board..
    resetFunc();
    charCounter = 0;
    led_Counter(charCounter);
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("not Rest...");
  }
  
   if(myData.char_data == 'p'){    //turn buzzer off..
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Buzzer off..");
    myTime=millis();
   }
   
   if(myData.char_data == 'q'){    //turn buzzer on..
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Buzzer on..");
    myTime=millis();
   }
   
   if(myData.char_data == 'b'){    //auto close door..
    charCounter = 0;
    led_Counter(charCounter);
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Auto Close Door");
    myTime = millis();
   }
   
   if(myData.char_data == 'w'){     //worong pass..
    notNum = false;
    charCounter = 0;
    led_Counter(charCounter);
    delay(1000);
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Wrong password");
    myTime=millis();
   }
   
   if(myData.char_data == 'b'){      //button inside (close door)..
    charCounter = 0;
    led_Counter(charCounter);
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Auto Close Door");
    myTime = millis();
   }
   
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
  if ((strID.indexOf("59:26:E9:A9") >= 0)||(strID.indexOf("1E:F5:0B:FA") >= 0)||(strID.indexOf("4A:E2:E2:5C") >= 0)||(strID.indexOf("FA:39:E9:5C") >= 0))//||(strID.indexOf("59:26:E9:A9") >= 0)||(strID.indexOf("F2:71:5A:D3") >= 0)||(strID.indexOf("54:27:4C:D3") >= 0)||(strID.indexOf("59:B9:D9:2A") >= 0)||(strID.indexOf("09:C4:E4:2A") >= 0)||(strID.indexOf("8A:FA:E3:81") >= 0))
  {
     Serial.println("card accepted");
     notNum = false;
     clearLCD();
     lcd.setCursor(0, 1);
     lcd.print("Card Accepted");
    myData.char_data = '+';
    ET.sendData();
    delay(1000);
    myTime=millis();
    //digitalWrite(out, LOW);
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
    myTime=millis();
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  
}

void clearLCD(){
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void LCDlight(){
  if(lcdLight3 == true){
    if((lcdLight1 == true)&&(lcdLight3 == true)){
      notNum = false;
      if(lcdLight2 == false){
        lcd.backlight();
        clearLCD();
        lcd.setCursor(0, 1);
        
        lcd.print("Light ON...");
        myTime = millis();
//        if(millis() - myTime >= 2000)
//          clearLCD();
        lcdLight = false;
        lcdLight1 = false;
        lcdLight2 = true;
      }
      else{
        lcd.noBacklight();
        clearLCD();
        lcd.setCursor(0, 1);
        lcd.print("Light OFF..");
        myTime = millis();
        lcdLight = false;
        lcdLight1 = false;
        lcdLight2 = false;
      }
    }
      lcdLight = true;
      lcdLight3 = false;
      lcdLight4 = true;
  }  
  if(myData.char_data == 'C'){
    lcdLight1 = false;
    lcdLight3 = false;
    if(lcdLight == true){
      lcdLight1 = true;
      lcdLight3 = false;
    }
      lcdLight4 = false;
  }
  /*else if(myData.char_data == 'C'){//&&(lcdLight4 == false)){
    lcdLight1 = false;
      lcdLight3 = false;
  }*/
}

void led_Counter(int led_Count){
 if(led_Count == 0){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 1){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 2){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 3){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 4){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 5){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 6){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 7){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, LOW);
 }
 else if(led_Count == 8){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
 }
}
