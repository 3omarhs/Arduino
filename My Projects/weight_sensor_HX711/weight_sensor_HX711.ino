#include "HX711.h"


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

double x = 0;

HX711 scale;
void setup() {
  
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3omar.hs Balance");
  
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(-1537.34);
  //if (scale.is_ready())
  x = scale.read() * 0.045674/10;
}
void loop() {
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println((reading * 0.045674/10)- x);  //(reading * 0.045674/10)-198
    
  lcd.setCursor(0, 1);
  lcd.print("Weight:");
  lcd.setCursor(7, 1);
//  lcd.print((reading * 0.045674/10)-198);
lcd.print((reading * 0.045674/10) - x);
  
//    Serial.print("get_value");
//    Serial.print(scale.get_value());
//    Serial.print("      ");
//    Serial.print("get_units");
//    Serial.println(((scale.get_units()-36186.0)* 0.035274)- 35.24);
  } else {
    Serial.println("HX711 not found.");
  }
  delay(1000);
}
