#include <Key.h>
#include <Keypad.h>
#include <Keypad_I2C.h>
#define I2CADDR 0x20
// SDA >> A4,  SCL >> A5 : in Arduino micro pro
const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [ROWS] = {0, 1, 2, 3}; // Connect to Keyboard Row Pin
byte colPins [COLS] = {4, 5, 6, 7}; // Connect to Pin column of keypad.
Keypad_I2C keypad (makeKeymap (keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

void setup () {
  Wire .begin ();
  keypad.begin (makeKeymap (keys));
  Serial.begin (9600);

}
void loop () {
  char key = keypad.getKey (); 
  if (key) {
    Serial.println (key);
  }
}
