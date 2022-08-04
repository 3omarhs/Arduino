/*
Data on pin 12 (pin on the left")
*/


#include <VirtualWire.h>

uint8_t counter = 0; 

void setup() {
    vw_set_tx_pin(12);
    vw_set_rx_pin(11);
    vw_setup(1000);
}

void loop() {
  char msg[1];
  msg[0] = counter;
  vw_send((uint8_t *)msg, 1);
  vw_wait_tx();
  counter++;
  delay(1000);
}
