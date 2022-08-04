/*
Data on pin 11 (pin on right"behind GND")
*/


#include <VirtualWire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

uint8_t currentPacket = 0; 

void setup() {
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("3omar.hs TR");
  
  vw_set_tx_pin(12);
  vw_set_rx_pin(11);
  vw_setup(1000);
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    currentPacket = (uint8_t) buf[0];

    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print("Packet:");
    lcd.setCursor(7, 1);
    lcd.print(currentPacket);
  }
}
