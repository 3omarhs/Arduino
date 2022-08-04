#include "SevSeg.h"
SevSeg sevseg;
unsigned long timer = 0;
String number="";

void setup(){
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  Serial.begin(9600);
}
int i=0;
void loop(){
  //for(int i=0; i<=1000; i++){
    static unsigned long timer = millis();
if(Serial.available()){
  char a = Serial.read();
  if((a == '0')||(a == '1')||(a == '3')||(a == '4')||(a == '5')||(a == '6')||(a == '7')||(a == '8')||(a == '9')){
    //a = Serial.parseInt()*10;
    number += a;
  }
  else if(a == 's'){
    number = number.toInt();
  }
}
  if (millis() > timer) {
    timer += 1000;
    sevseg.setNumber(i, 2);
    //Serial.print(i);
    delay(0);
    i--;
  }
    sevseg.refreshDisplay();
  //}
}
