#include <Arduino.h>
#include <U8g2lib.h>
#include <Ultrasonic.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);


//Ultrasonic ultrasonic(11, 12);
Ultrasonic ultrasonic(A2, A3);
int distance, dist;


void setup(void) {
  u8g2.begin();
}

void loop() {
  distance = ultrasonic.read();
//  distance = (100 - distance) + 23;
distance = (100 - distance);
  if(distance >= 100){
    distance = -1;
  }
  else if(distance < 0){
    distance = -1;
  }
  else if(distance == 99){
    distance = 100;
  }
  if(distance != -1){
    dist = distance;
  }
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_luRS24_te);
  u8g2.setCursor(20,32);
  u8g2.print(dist);
  u8g2.print("%");

  u8g2.setFont(u8g2_font_4x6_tf);
  u8g2.setCursor(10,5);
  u8g2.print("Tank measure project:");

  u8g2.sendBuffer();
  delay(500);
}
