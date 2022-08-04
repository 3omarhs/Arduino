/* Burung Hantu Electronics Project
 *
 * Remote Control With NRF24L01 PA LNA Communcation Module (Transmitter)
*/

// Library NRF24L01
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define the pins of NRF24L01
#define CE_PIN   9
#define CSN_PIN 10

// The tx/rx address
const byte rxAddr[6] = "00001";

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN);

// Declaration of the value Transmited
int msg[1];

// Define the KY-023 Joystick pin
int button_Pin = 5;
int x_Pin = A0; //Nama alias pin A1 yaitu xPin
int y_Pin = A1; //Nama aliasa pin A0 yaitu yPin

// Default Value for Joystick
int x_Position = 0;
int y_Position = 0;
int buttonState = 0;

void setup() {
  // Start the serial
  while (!Serial);
  Serial.begin(9600);

  // Start radio
  radio.begin();

  // Power setting. Due to likelihood of close proximity of the devices, set as RF24_PA_MIN (RF24_PA_MAX is default)
  radio.setPALevel(RF24_PA_MIN); // RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX

  // Slower data rate for better range
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS

  // Number of retries and set tx/rx address
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);

  // Stop listening, so we can send!
  radio.stopListening();

  // Define push button pin
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  // Declaration of x_Pin and y_Pin for value
  pinMode(x_Pin, INPUT); pinMode(y_Pin, INPUT);

  // Declaration of button_Pin as input with pull-up condition
  pinMode(button_Pin, INPUT_PULLUP);
}

void loop() {
  // Declaration of push button value
  int pbmaju = digitalRead(2);
  int pbmundur = digitalRead(3);
  int pbled = digitalRead(4);

  // Declaration of joystick value
  x_Position = analogRead(x_Pin); y_Position = analogRead(y_Pin);
  buttonState = digitalRead(button_Pin);

  // Serial print for joystick value
  Serial.print("X: "); Serial.print(x_Position);
  Serial.print(" | Y: "); Serial.print(y_Position);
  Serial.print(" | Button: "); Serial.println(buttonState);

  // If commands
  if (x_Position <= 50) {
    msg[0] = 115;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (x_Position >= 900) {
    msg[0] = 114;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (y_Position >= 900) {
    msg[0] = 116;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (y_Position <= 50) {
    msg[0] = 117;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (buttonState == LOW) {
    msg[0] = 118;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (pbmaju == LOW) {
    msg[0] = 111;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (pbmundur == LOW) {
    msg[0] = 112;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
  if (pbled == LOW) {
    msg[0] = 113;
    radio.stopListening();
    radio.write(msg, 1);
    radio.startListening();
  }
}
