#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include "Wire.h"
#include <Servo.h>
Servo servo;
#include <Key.h>
//#include <Keypad.h>
#include <Keypad_I2C.h>

#define I2CADDR 0x20 // Set the Address of the PCF8574

const byte ROWS = 4; // Set the number of Rows
const byte COLS = 4; // Set the number of Columns

// Set the Key at Use (4x4)
char keys [ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// define active Pin (4x4)
byte rowPins [ROWS] = {0, 1, 2, 3}; // Connect to Keyboard Row Pin
byte colPins [COLS] = {4, 5, 6, 7}; // Connect to Pin column of keypad.

// makeKeymap (keys): Define Keymap
// rowPins:Set Pin to Keyboard Row
// colPins: Set Pin Column of Keypad
// ROWS: Set Number of Rows.
// COLS: Set the number of Columns
// I2CADDR: Set the Address for i2C
// PCF8574: Set the number IC
Keypad_I2C kpd (makeKeymap (keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

 bool start = false;
 bool end = false;
 bool input = false;
 char key;
 String keyss;
 int num;
 int curser=0;
 int HH, MM, SSS;

 int buz = 5;
 unsigned long mms, mms1;

void setup() {
  // put your setup code here, to run once:
  servo.attach(A0);
  servo.write(0);  //125
  
  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print(".......");
  lcd.noBacklight();
  Serial.begin(9600);
//Serial.println(servo.read());
  pinMode(buz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("                   ");
  
  if(input == false){
    
    HH = first_digit();
    Serial.println(HH);
    lcd.setCursor(curser, 1);
    lcd.print(":");
    curser++;
  
    
    MM = first_digit();
    Serial.println(MM);
    lcd.setCursor(curser, 1);
    lcd.print(":");
    curser++;
  
    
    SSS = first_digit();
    Serial.println(SSS);
    lcd.setCursor(curser, 1);
    curser++;
    
    printt();
    input = true;
  }

  if(input == true){
    key = kpd.getKey();
    
    while(key != 'D'){
      key = kpd.getKey();
    }
    
    if(key == 'C'){
      input = false;
      HH = 0;
      MM = 0;
      SSS = 0;
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(9, 1);
      lcd.print("C");
      Serial.println("C");
    }
    
    if(key == 'D'){
      lcd.setCursor(9, 1);
      lcd.print("D");
      Serial.println("D");
      start = true;
      input = false;
    }
  }

  while(start == true){
    delay(935);  //add to get more slower..
    if(SSS<2){
      if(MM != 0){
        MM -= 1;
        SSS = 60;
      }

      if((MM == 0)&&(HH != 0)){
        HH -= 1;
        MM = 60;
      }
      
      if((MM == 0)&&(HH == 0)&&(SSS == 0)){
      start = false;
      end = true;
      }
    }
    SSS--;
    curser=0;
    lcd.setCursor(9, 1);
    lcd.print(" ");
    lcd.setCursor(11, 0);
    lcd.print("    ");
  
    printt();
  }

  if(end == true){
    mms = millis();
    while(millis() <= mms+30000){
      key = kpd.getKey();
        mms1 = millis();
        while(millis() <= mms1+200)
        digitalWrite(buz, HIGH);
  
        mms1 = millis();
        while(millis() <= mms1+100)
        digitalWrite(buz, LOW);
    }
    for(int i =0; i < 90; i++) //When servo is a position 0, servo will rotate to 180 degrees (half rotation)
    {   servo.write(i); 
        delay(15); 
    }
    lcd.setCursor(0, 1);
    lcd.print("finished..");
    lcd.setCursor(11, 0);
    lcd.print("    ");
    mms1 = millis();
        while(millis() <= mms1+1700)
        ;
    for(int i = 90; i > 0; i--) //When servo is a position 180, servo will rotate to 0 degrees (beginning position)
    { 
        servo.write(i); 
        delay(3); 
    }
    //delay(2000);
  }
}

int first_digit(){
  keyss = "";
  lcd.setCursor(0, 0);
  lcd.print("HH:MM:SS ");
  lcd.setCursor(0, 1);
  while(keyss.length() < 2){
    key = kpd.getKey();
    if((key == '0')||(key == '1')||(key == '2')||(key == '3')||(key == '4')||(key == '5')||(key == '6')||(key == '7')||(key == '8')||(key == '9')){
      keyss += key;
      lcd.setCursor(curser, 1);
      lcd.print(key);
      curser++;
    }
  }
  //Serial.println(keyss);
  num = keyss.toInt();
  Serial.print("num: ");
  Serial.println(num);
  return num;
}

void printt(){
  
  lcd.setCursor(0, 1);
  lcd.print("                  ");
  lcd.setCursor(0, 0);
  lcd.print("HH:MM:SS    tt");
  lcd.setCursor(0, 1);
  lcd.print(HH);
  lcd.setCursor(2, 1);
  lcd.print(":");
  lcd.setCursor(3, 1);
  lcd.print(MM);
  lcd.setCursor(5, 1);
  lcd.print(":");
  lcd.setCursor(6, 1);
  lcd.print(SSS);
  if(SSS == -1){
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    lcd.setCursor(0, 1);
    lcd.print("Alarm....");
  }
}

//void loop(){}
