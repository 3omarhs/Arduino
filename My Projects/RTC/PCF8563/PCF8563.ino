#include <Wire.h>
#include <Rtc_Pcf8563.h>
 
//init the real-time clock
Rtc_Pcf8563 rtc;
 
void setup()
{
  // set up the LCD's number of rows and columns: 
  Serial.begin(9600);
  //clear out all the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  rtc.setDate(10, 3, 5, 20, 22);
  //hr, min, sec
  rtc.setTime(00, 44, 00);
}
 
void loop()
{
  Serial.println();
  Serial.print("Time:");
  Serial.print(rtc.formatTime());
  Serial.println();
  Serial.print("Date:");
  Serial.print(rtc.formatDate());
  delay(1000);
}
