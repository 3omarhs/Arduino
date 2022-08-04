#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);
// 0x27 is the address
// 16*2 is the size of screen

int x=0;
void setup(){
  lcd.init();   // initialize
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("3omar.hs");
}
void loop(){
  lcd.clear();
  lcd.setCursor(1,0);   //(C,R)
  lcd.print("simple counter");
  lcd.setCursor(7,1);   //(C,R)
  lcd.print(x);
  x = x + 1;
  delay(1000);
}
