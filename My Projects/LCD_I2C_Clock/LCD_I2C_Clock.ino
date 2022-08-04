#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  lcd.backlight();
  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("3omar.hs");
}

int h=11, m=59, s=55;
String ap="am";

void loop() {delay(1000);
String H=String(h);
String M=String(m);
String S=String(s);
s++;
lcd.clear();
lcd.setCursor(1, 0);
lcd.print("3omar.hs");
lcd.setCursor(1, 1);
if(h<10)
  H="0"+H;
if(m<10)
  M="0"+M;
if(s<11)
  S="0"+S;
lcd.print(H+":"+M+":"+S+" "+ap);
if(ap=="pm")
  lcd.backlight();
if(ap=="am")
  lcd.noBacklight();
if(s==60){
  m++;
  s=0;
}
if(m==60){
  h++;
  m=0;
}
if(h==13){
  h=1;
}
if((h==12)&&(m==0)&&(s==0)){
  if(ap=="am"){
    ap="pm";
  }
  else{
    ap="am";
  }
}
}
