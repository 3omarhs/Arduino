#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

signed short minutes, secondes;
char timeline[16];

void setup() {

  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("3omar.hs");
  lcd.setCursor(0, 1);
  lcd.print(".......");
  lcd.backlight();


}

void loop() {

  lcd.setCursor(0, 1);
  sprintf(timeline,"%0.2d mins %0.2d secs", minutes, secondes);
  lcd.print(timeline);
  
  delay(1000);
  secondes++;
  
  if (secondes == 60)
  {
    secondes = 0;
    minutes ++;
  }

}
