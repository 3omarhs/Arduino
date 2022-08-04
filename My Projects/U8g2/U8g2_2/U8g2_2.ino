#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

 void setup(void) {
   u8g2.begin();
}

  void loop(void) {
   u8g2.clearBuffer();					// clear the internal memory
   u8g2.setFont(u8g2_font_t0_15_tf);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
//   u8g2.setFont(u8g2_font_t0_11_tf);
//   u8g2.drawStr(0,8,"3omar.hs");	// write something to the internal memory
//   u8g2.drawStr(123,20,"HI");
//   u8g2.drawStr(0,32,"I`m Omar");
   u8g2.drawStr(89,12,   "00/00");  // write something to the internal memory
   //u8g2.drawStr(0,20,"or call me 3omar.hs");
   u8g2.drawStr(0,30,  "stp:0   Tu 9 :05");
   u8g2.sendBuffer();					// transfer internal memory to the display

//
//   u8g2.setFont(u8g_font_unifont);
//    u8g2.setPrintPos(0, 15);
//    u8g2.print("0.91 OELD");
//    u8g2.setPrintPos(0,30);
//    u8g2.print("SmartPrototyping");
//    u8g2.setPrintPos(0, 20); 
//    u8g2.print("add your text here");

  
}
