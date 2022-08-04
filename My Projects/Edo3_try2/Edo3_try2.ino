#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;
#include <Key.h>
#include <Keypad.h>
#include <Keypad_I2C.h>
#define I2CADDR 0x20
// SDA >> A4,  SCL >> A5 : in Arduino micro pro
const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins [ROWS] = {0, 1, 2, 3}; // Connect to Keyboard Row Pin
byte colPins [COLS] = {4, 5, 6, 7}; // Connect to Pin column of keypad.
Keypad_I2C kpad (makeKeymap (keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

//int led1 = 2;
//int led2 = 3;
//int led3 = 4;
//int led4 = 5;
//int led5 = 6;
//int led6 = 7;
//int led7 = 8;
//int led8 = A0;

int m = 0, n = 0;
int countN = 0;
int ijj;
String password = "", correct_pass = "", Hours, Hours1, correct_pass_1 = "", correct_pass_2 = "";
unsigned long myTime;
char stopRepeated;
bool lcdLight = false, lcdLight1 = false, lcdLight2 = false, notNum = false, lcdLight3 = false, stopRepeat = false, lcdLight4 = false;
const int buttonPin = 2;
const int buttonPinb = 3;
int buzzer = 4;//Buzzer
int greenLed = 5;//Green led
int redLed = 6;//Red led
int reverse = 7;
int motor = 8;
int restart_pin = A0;
bool dd0 = false, dd1 = false, bz_off = true;
int i = 0;  //for loop
int j = 0;  //digits entred
int val = 0;//Counter
char charKey;//Key on keypad
char correctPassword[4] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[9];//Entered password on keypad
unsigned long clearTime;//used for millis

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
struct DATA_STRUCTURE {
  int int_data;
  char char_data;
};
String strData = "N";
String strData1;
int charCounter = 0;

//void(* resetFunc) (void) = 0;//function to restart the board

void setup() {
  Wire .begin ();
  kpad.begin (makeKeymap (keys));
  Serial.begin (9600);

  SPI.begin();
  rfid.PCD_Init();

  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinb, INPUT);

  //  pinMode(led1, OUTPUT);
  //  pinMode(led2, OUTPUT);
  //  pinMode(led3, OUTPUT);
  //  pinMode(led4, OUTPUT);
  //  pinMode(led5, OUTPUT);
  //  pinMode(led6, OUTPUT);
  //  pinMode(led7, OUTPUT);
  //  pinMode(led8, OUTPUT);

  lcd.noBacklight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print("Restarted...");
}

void loop() {
  if (millis > 200)
    val = digitalRead(buttonPin);
  if (val == HIGH)
    buttonPinb0();
  while (digitalRead(buttonPin) != 0) {
    sorce_code();
  }
  sorce_code();
}






void clearLCD() {
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
}

void clear_lcd_after_8_seconds() {
  if ((millis() - myTime >= 8000) && (millis() - myTime <= 8100)) {
    clearLCD();
    j = 0;
    charCounter = 0;
    password = "";
  }
}

void clear_lcd_after_15_seconds() {
  if ((millis() - clearTime >= 15000) && (millis() - clearTime <= 15100)) {
    clearLCD();
    charCounter = 0;
    //    led_Counter(charCounter);
    j = 0;
    charCounter = 0;
    password = "";
  }
}

void LCDlight() {
  if (lcdLight3 == true) {
    if ((lcdLight1 == true) && (lcdLight3 == true)) {
      notNum = false;
      if (lcdLight2 == false) {
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
      else {
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
  /*else if(myData.char_data == 'C'){//&&(lcdLight4 == false)){
    lcdLight1 = false;
      lcdLight3 = false;
    }*/
}

/*void led_Counter(int led_Count) {
  if (led_Count == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 6) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 7) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, LOW);
  }
  else if (led_Count == 8) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
  }
  }*/

void rtc_password_1() {
  rtc_time_display();
  if (rtc.getHour() > 12)
    Hours = (String)(int(rtc.getHour()) - 12);
  else if (rtc.getHour() == 0)
    Hours = "12";
  else {
    Hours = (String)int(rtc.getHour());
  }
  String sss = (String)int(rtc.getMinute());
  correct_pass = "3";
  correct_pass += sss[sss.length() - 1];
  correct_pass += (String)int(rtc.getWeekday());
  sss = Hours;
  correct_pass += sss[sss.length() - 1];
  sss = (String)int(rtc.getDay());
  correct_pass += sss[sss.length() - 1];
  //  Serial.print("correct_pass: ");Serial.println(correct_pass);
  Serial.print("rtc_pass1: ");
  Serial.println(correct_pass);
  if (password == correct_pass) {
    lcd.setCursor(0, 1);
    lcd.print("RTC password_1..");
    inn0();
  }
}

void rtc_time_display() {
  if (rtc.getHour() > 12)
    Hours = (String)(int(rtc.getHour()) - 12);
  else if (rtc.getHour() == 0)
    Hours = "12";
  lcd.setCursor(0, 0);
  if (millis() < 3100) {
    lcd.print("                    ");
    lcd.setCursor(0, 0);
  }
  lcd.print(Hours);
  lcd.print(":");
  lcd.print(rtc.getMinute());
  lcd.print("  ");
  lcd.setCursor(7, 0);
  lcd.print(rtc.getWeekday());
  lcd.setCursor(12, 0);
  lcd.print(rtc.getMonth());
  lcd.print("/");
  lcd.print(rtc.getDay());
  lcd.print(" ");
}


void rtc_password_2() {
  if (rtc.getHour() > 12)
    Hours1 = (String)(int(rtc.getHour()) - 12 + 3);
  else if (rtc.getHour() == 0)
    Hours1 = "12";
  else {
    Hours1 = (String)int(rtc.getHour());
  }
  String sss1 = (String)(int(rtc.getMinute() + 3));
  correct_pass_1 = "3";
  correct_pass_1 += sss1[sss1.length() - 1];
  correct_pass_1 += (String)(int(rtc.getWeekday()) - 3);
  sss1 = Hours1;
  correct_pass_1 += sss1[sss1.length() - 1];
  sss1 = (String)(int(rtc.getDay()) - 3);
  correct_pass_1 += sss1[sss1.length() - 1];

  //(3 LM+3 WD-3 LH LDN-3) >>> if < or > original >>> = 3

  correct_pass_2 = "";
  for (int i = 0; i <= correct_pass_1.length() - 1; i++) {
    if (((String)correct_pass_1[i] != "0") && ((String)correct_pass_1[i] != "1") && ((String)correct_pass_1[i] != "2") && ((String)correct_pass_1[i] != "3") && ((String)correct_pass_1[i] != "4") && ((String)correct_pass_1[i] != "5") && ((String)correct_pass_1[i] != "6") && ((String)correct_pass_1[i] != "7") && ((String)correct_pass_1[i] != "8") && ((String)correct_pass_1[i] != "9")) {
      correct_pass_2 += "3";
    }
    else
      correct_pass_2 += (String)correct_pass_1[i];
  }
  //  Serial.print("correct_pass1: ");Serial.println(correct_pass_2);
  Serial.print("                          rtc_pass2: ");
  Serial.println(correct_pass_2);
  if (password == correct_pass_2) {
    lcd.setCursor(0, 1);
    lcd.print("RTC password_2..");
    inn0();
  }
}

void rfid_read() {
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
  if ((strID.indexOf("59:26:E9:A9") >= 0) || (strID.indexOf("1E:F5:0B:FA") >= 0) || (strID.indexOf("4A:E2:E2:5C") >= 0) || (strID.indexOf("FA:39:E9:5C") >= 0)) //||(strID.indexOf("59:26:E9:A9") >= 0)||(strID.indexOf("F2:71:5A:D3") >= 0)||(strID.indexOf("54:27:4C:D3") >= 0)||(strID.indexOf("59:B9:D9:2A") >= 0)||(strID.indexOf("09:C4:E4:2A") >= 0)||(strID.indexOf("8A:FA:E3:81") >= 0))
  {
    Serial.println("card accepted");
    Serial.println("Door opened by a card \"RFID\"");
    lcd.println("Door opened by \"RFID\"");
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Card Accepted");
    inn0();
    delay(1000);
    myTime = millis();
    //digitalWrite(out, LOW);
  }

  else
  {
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("Wrong Card...");
    inn20();
    delay(1000);
    myTime = millis();
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}


//**************************************************************************************************************************************************************************************************************


void square() {
  Serial.println("# cloase the door");
  charCounter = 0;
  //  led_Counter(charCounter);
  notNum = false;
  clearLCD();
  lcd.setCursor(0, 1);
  lcd.print("Close Door");
  myTime = millis();
  digitalWrite(greenLed, HIGH);
  delay(100);
  if (bz_off == false) {
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
  digitalWrite(redLed, LOW);
  delay(100);
  digitalWrite(reverse, LOW);
  delay(500);
  j = 0;
  charCounter = 0;
}


void D() {
  Serial.println("D clear all digits enterd");
  clearLCD();
  charCounter = 0;
  //  led_Counter(charCounter);
  strData = "N";
  password = "";

  if (dd1 == true) {
    if (bz_off == false) {
      clearLCD();
      lcd.setCursor(0, 1);
      lcd.print("Buzzer off..");
      bz_off = true;
      digitalWrite(buzzer, HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
      dd0 = false;
      dd1 = false;
      myTime = millis();
      return;
    }
    else if (bz_off == true) {
      bz_off = false;
      clearLCD();
      lcd.setCursor(0, 1);
      lcd.print("Buzzer on..");
      for (int i = 0; i <= 10; i++) {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(50);
      }
      dd0 = false;
      dd1 = false;
      myTime = millis();
      return;
    }
  }
  if (dd0 == true) {
    dd0 = false;
    dd1 = true;
  }
  else if (dd0 == false) {
    dd0 = true;
  }
  if (j > 0) {
    enteredPassword[j = 0] = charKey;
    if (bz_off == false) {
      digitalWrite(buzzer, HIGH);
      delay(250);
      digitalWrite(buzzer, LOW);
    }
  }
  else {
    if (bz_off == false) {
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
    }
  }
  lcdLight3 = true;
  LCDlight();
}


void C() {
  Serial.println("C clear last digit enterd");
  lcdLight1 = false;
  lcdLight3 = false;
  if (lcdLight == true) {
    lcdLight1 = true;
    lcdLight3 = false;
  }
  lcdLight4 = false;
  if ((notNum == true) && (charCounter != 0)) { //clear last digit..
    //lcd.setCursor(charCounter-(countN+1), 1);
    lcd.setCursor(charCounter - 1, 1);
    lcd.print(" ");
    countN++;
    charCounter = charCounter - 1;
    //    led_Counter(charCounter);
    password = password.substring(0, password.length() - 1);
  }

  if (j > 0) {
    enteredPassword[j--] = charKey;
    if (bz_off == false) {
      digitalWrite(buzzer, HIGH);
      delay(250);
      digitalWrite(buzzer, LOW);
    }
  }
  else {
    if (bz_off == false) {
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
    }
  }
  clearTime = millis();
}


void star() {
  Serial.println("* restart the RFID board");
  //  static_cast<void(*)(void)>(0)();
  //  asm("jmp 0");
  digitalWrite(restart_pin, HIGH);
  delay(300);
  digitalWrite(restart_pin, LOW);
  //  resetFunc();
  /*
    charCounter = 0;
    //  led_Counter(charCounter);
    notNum = false;
    clearLCD();
    lcd.setCursor(0, 1);
    lcd.print("not Rest...");
    if (bz_off == false) {
    for (i = 1; i <= 3; i++) {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(100);
    delay(300);
    for (i = 1; i <= 3; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
    delay(600);
    }
    else {
    delay(300);
    digitalWrite(buzzer, LOW);
    }
    j = 0 ;*/
}


void buttonPinb0() {
  Serial.println("buttonPin b   auto close system");
  charCounter = 0;
  //  led_Counter(charCounter);
  notNum = false;
  clearLCD();
  lcd.setCursor(0, 1);
  lcd.print("Auto Close Door");
  myTime = millis();
  digitalWrite(greenLed, HIGH);
  delay(100);
  if (bz_off == false) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else {
    delay(200);
  }
  delay(100);
  digitalWrite(motor, HIGH);
  delay(300);
  digitalWrite(motor, LOW);
  digitalWrite(reverse, HIGH);
  delay(500);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  delay(100);
  digitalWrite(reverse, LOW);
  delay(500);
  j = 0;
  charCounter = 0;
}


void buttonPin0() {
  Serial.println("buttonPin   open the door");
  clearLCD();
  lcd.setCursor(0, 1);
  lcd.print("open door button");
  myTime = millis();
  digitalWrite(greenLed, HIGH);
  delay(100);
  if (bz_off == false) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  digitalWrite(motor, HIGH);
  delay(500);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  delay(100);
  digitalWrite(motor, LOW);
}


void inn0() {
  digitalWrite(greenLed, HIGH);
  delay(100);
  if (bz_off == false) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  digitalWrite(motor, HIGH);
  delay(400);
  digitalWrite(redLed, LOW);
  delay(200);
  digitalWrite(motor, LOW);
  password = "";
  myTime = millis();
  j = 0 ;
}


void inn20() {
  digitalWrite(redLed, HIGH);
  delay(200);
  if (bz_off == false) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
  digitalWrite(redLed, LOW);
  delay(100);
  j = 0;
  charCounter = 0;
}


void charkey0() {
  if (password == "") {
    charCounter = 0;
    clearLCD();
  }
  Serial.print("charKey: ");
  password += charKey;
  char ii = charKey;
  myTime = millis();
  if (notNum == false) {
    clearLCD();
  }
  notNum = true;
  charCounter++;
  //  led_Counter(charCounter);
  lcd.setCursor(charCounter - 1, 1);
  lcd.print(ii);
  Serial.println(j);
  if (bz_off == false)
    digitalWrite(buzzer, HIGH);
  digitalWrite(greenLed, HIGH);
  delay(100);
  if (charCounter > 1) {
    lcd.setCursor(charCounter - 2, 1);
    countN++;
    lcd.print('*');
  }
  Serial.println(charKey);
  enteredPassword[j++] = charKey;
  if (bz_off == false)
    digitalWrite(buzzer, LOW);
  digitalWrite(greenLed, LOW);
  clearTime = millis();
}


void correct() {
  Serial.println("correct password    door opened");
  lcd.setCursor(0, 1);
  lcd.print("Correct password");
  notNum = false;
  charCounter = 0;
  inn0();
}


void elsee() {
  Serial.println("wrong password");
  notNum = false;
  charCounter = 0;
  //  led_Counter(charCounter);
  lcd.setCursor(0, 1);
  lcd.print("Wrong password");
  myTime = millis();
  Serial.println("9 digits wrong");
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  digitalWrite(reverse, HIGH);
  if (bz_off == false) {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
  }
  delay(1000);
  digitalWrite(reverse, LOW);
  j = 0;
  charCounter = 0;
  clearLCD();
}

void sorce_code() {
  rtc_time_display();

  if ((j == 5) || (j == 6)) {
    rtc_password_1();

    rtc_password_2();
  }

  clear_lcd_after_8_seconds();

  lcd.setCursor(0, 1);
  LCDlight();

  rfid_read();

  //  clear_lcd_after_15_seconds();

  keypad_entery();

  if (j == 8)
    check_pass();

  val = digitalRead(buttonPinb);
  if (val == HIGH)
    buttonPin0();
}

void keypad_entery() {
  charKey = kpad.getKey();
  if ((charKey == 'A') || (charKey == 'B') || (charKey == '1') || (charKey == '2') || (charKey == '3') || (charKey == '4') || (charKey == '5') || (charKey == '6') || (charKey == '7') || (charKey == '8') || (charKey == '9') || (charKey == '0') || (charKey == '*') || (charKey == '#')) {
    lcdLight = false;
    lcdLight1 = false;
    lcdLight3 = false;
    countN = 0;
    dd0 = false;
    dd1 = false;
    if (charKey && charKey != '#' && charKey != '*' && charKey != 'D' && charKey != 'C') {
      charkey0();
    }

    else if (charKey == '#')
      square();

    else if (charKey == '*')
      star();
  }

  else if (charKey == 'C') {
    dd0 = false;
    dd1 = false;
    C();
  }

  else if (charKey == 'D')
    D();
}

void check_pass() {
  char correctPassword[8] = {'7', '7', '7', '8', '7', '9', '8', '7'}; //Correct password
  if ((strncmp(enteredPassword, correctPassword, 8) ==  0))
    correct();
  ///////////////////
  else
    elsee();
  ///////////////////

  if (password == correct_pass) {
    inn0();
  }
}
