//RECEIVER

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// RadioHead - Version: Latest 
#include <RH_ASK.h>
// SPI - Version: Latest
// Not actualy used but needed to compile 
#include <SPI.h>

//RH_ASK driver; 
RH_ASK rf_driver;

long myTime;


void setup()
{
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3omar.hs TR");

  rf_driver.init();
  
    Serial.begin(9600);
    //if (!driver.init())
      //   Serial.println("init failed");
}

void loop()
{
    if(millis() >= myTime + 3000){
      //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                     ");
    }
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    if (rf_driver.recv(buf, &buflen))
    {
      int i;
      Serial.print("Message: ");
      String temp = (char*)buf;
      temp = temp.substring(0, temp.length());
      Serial.println(temp);   
      lcd.setCursor(0, 1);
  lcd.print(temp); //(char*)buf);  
  myTime = millis();    
    }
}
