//https://www.circuitbasics.com/arduino-7-segment-display-tutorial/

#include "SevSeg.h"
SevSeg sevseg;
unsigned long timer = 0;
String number="";
int num;
bool zero = false;

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
  sevseg.setNumber(0000, 4);
  sevseg.refreshDisplay();
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
    Serial.println(number);
    num = number.toInt()+7;
    Serial.print("=");
    i=number.toInt();
    number="";
    Serial.print(i);
    Serial.println();
    static unsigned long timer = millis();
  }
}
  timer = millis();
  if ((millis() > timer)&&(i>0)){
Serial.print("i= ");
Serial.println(i);
    timer += 1000;
    sevseg.setNumber(i-1, 4);
    //Serial.print(i);
    delay(0);
    i--;
    zero=true;
  }
    if((i <=0)&&(zero == true)){
      zero = false;
      sevseg.setNumber(99999999, 4);
    }
    sevseg.refreshDisplay();
  //}
}




/*
 * sevseg.setChars("E");
    sevseg.setNumber(V, 1);
    sevseg.refreshDisplay(); 
 */
