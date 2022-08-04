#include <Wire.h>
#include <Rtc_Pcf8563.h>
#include <LiquidCrystal.h>
 
//init the real-time clock
Rtc_Pcf8563 rtc;
 
LiquidCrystal lcd(12 ,11 ,5 ,4 ,3 ,2);
 
void setup()
{
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("PCF8563");
  lcd.setCursor(0, 1);
  lcd.print("Real Time Clock");
  delay(4000);
  lcd.clear();
  
  //clear out all the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  rtc.setDate(20, 3, 9, 20, 21);
  //hr, min, sec
  rtc.setTime(21, 18, 50);
}
 
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(6, 0);
  //lcd.print(rtc.formatTime(RTCC_TIME_HM));
  lcd.print(rtc.formatTime());
 
  lcd.setCursor(0, 1);
  lcd.print("Date:");
  lcd.setCursor(6, 1);
  //lcd.print(rtc.formatDate(RTCC_DATE_ASIA));
  lcd.print(rtc.formatDate());
  
 // delay(1000);
    
}
