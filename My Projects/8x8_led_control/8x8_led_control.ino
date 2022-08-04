#include <LedControl.h>
#define MIC A0
int DIN = 7;
int CS =  6;
int CLK = 5;
byte a[] = {B00000000, B00000000, B00110000, B00001000, B00111000, B01001000, B00111100, B00000000};
byte A[] = {B00001000, B00101000, B01000100, B01000100, B01111100, B01000100, B01000100, B00000000};

LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() {
  lc.shutdown(0, false); // Wake up displays
  lc.shutdown(1, false);
  lc.setIntensity(0, 5); // Set intensity levels
  lc.setIntensity(1, 5);
  lc.clearDisplay(0); // Clear Displays
  lc.clearDisplay(1);
}



void loop() {
  for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, a[i]);
      }
    delay(500);
  }
