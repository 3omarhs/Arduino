#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);


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
int countN = 0;
int ijj;
String password = "", correct_pass = "", Hours, Hours1, correct_pass_1 = "", correct_pass_2 = "";
unsigned long myTime;
char stopRepeated;
bool lcdLight = false, lcdLight1 = false, lcdLight2 = false, notNum = false, lcdLight3 = false, stopRepeat = false, lcdLight4 = false;
int buzzer = 4;//Buzzer
int greenLed = 5;//Green led
int redLed = 6;//Red led
const int buttonPin = 7;
int motor = 8;
int reverse = 9;
const int buttonPinb = 10;
int reset = 11;
bool dd0 = false, dd1 = false, bz_off = true;
int i = 0;  //for loop
int j = 0;  //digits entred
int val = 0;//Counter
char charKey;//Key on keypad
char correctPassword[4] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[9];//Entered password on keypad
unsigned long clearTime;//used for millis
struct DATA_STRUCTURE {
  int int_data;
  char char_data;
};
DATA_STRUCTURE myData;
String strData = "N";
String strData1;
int charCounter = 0;

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void(* resetFunc) (void) = 0;//function to restart the board

void setup() {
  Wire.begin ();
  kpad.begin (makeKeymap (keys));
  Serial.begin (9600);

  SPI.begin();
  rfid.PCD_Init();

  lcd.noBacklight();
  lcd.init();
  lcd.setCursor(0, 1);
  lcd.print("Restarted...");
  delay(500);
  lcd.clear();
}


void loop() {
  lcd.setCursor(14,0);
  lcd.print("ON");
  lcd.setCursor(0, 0);
char key = kpad.getKey (); 
  if (key) {
    Serial.println (key);
    lcd.print(key);
  }
  lcd.setCursor(0, 1);
  rfid_read();
}

void rfid_read() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K && piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.println(strID);
  
  lcd.setCursor(0, 1);
  lcd.print(strID);
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
