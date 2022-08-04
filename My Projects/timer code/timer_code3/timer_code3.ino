#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <Keypad.h>
#include <Servo.h>

Servo servo;

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns


char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = { 6, 7, 8, 9 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins
byte colPins[COLS] = { 10, 11, 12, 13 };// Connect keypad COL0, COL1 and COL2 to t

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

 bool start = false;
 bool end = false;
 bool input = false;
 char key;
 String keyss;
 int num;
 int curser=0;
 int HH, MM, SSS;

 
void setup() {
  // put your setup code here, to run once:
  servo.attach(A0);
  for(int i = 200; i > 0; i--){servo.write(i);}
  
  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print(".......");
  lcd.backlight();
  Serial.begin(9600);
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
    if(key == 'D'){
      lcd.setCursor(9, 1);
      lcd.print("D");
      Serial.println("D");
      start = true;
      input = false;
    }
  }

  while(start == true){
    delay(1000);
    if(SSS<2){
      if(MM != 0){
        MM -= 1;
        SSS = 59;
      }

      if((MM == 0)&&(HH != 0)){
        HH -= 1;
        MM = 59;
      }
      
      if((MM == 0)&&(HH == 0)){
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
    for(int i =0; i < 200; i++) //When servo is a position 0, servo will rotate to 180 degrees (half rotation)
    {   servo.write(i); 
        delay(15); 
    }
    lcd.setCursor(0, 1);
    lcd.print("finished..");
    lcd.setCursor(11, 0);
    lcd.print("    ");
    for(int i = 200; i > 0; i--) //When servo is a position 180, servo will rotate to 0 degrees (beginning position)
    { 
        servo.write(i); 
        delay(3); 
    }
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
}

//void loop(){}
