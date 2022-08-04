#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  // Print a message to the LCD.
  lcd.backlight();
  lcd.init();
  lcd.setCursor(1,0);
  lcd.print("3omar.hs project.. "); 
}
void loop()
{
   lcd.setCursor(16,1);
   lcd.autoscroll();    // Set diplay to scroll automatically
   lcd.print(" ");      // set characters
   delay(700);    
}
