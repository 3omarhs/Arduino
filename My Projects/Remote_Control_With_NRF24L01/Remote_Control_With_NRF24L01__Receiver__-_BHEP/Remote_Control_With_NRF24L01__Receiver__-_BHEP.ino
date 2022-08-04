/* Burung Hantu Electronics Project
 * 
 * Remote Control With NRF24L01 PA LNA Communication Module (Receiver)
 */

// Library NRF24L01
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define the pins of NRF24L01
#define CE_PIN   9
#define CSN_PIN 10

// Create a Radio
RF24 radio(CE_PIN, CSN_PIN);

// The tx/rx address
const byte rxAddr[6] = "00001";

// Declaration of the value received
int msg[1];

// Define the pins of motor driver
#define EnA 5 //pwm left motor
#define EnB 6 //pwm right motor
#define In1 2 //+ left motor
#define In2 3 //- left motor
#define In3 4 //+ right motor
#define In4 7 //- left motor

// Define a pin of LED
#define led 8

void setup() {
  // Start the serial
  Serial.begin(9600);
  while (!Serial);
  Serial.println("NRF24L01P Receiver Starting...");

  // Start the radio, again set to min & slow as I'm guessing while testing theire really close to each other
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);   // RF24_PA_MIN ,RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate( RF24_250KBPS ); // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS

  // Set the reading pipe and start listening
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();

  // Set up a motor driver
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  // Set up a LED
  pinMode(led, OUTPUT);
}

void maju() {
// Move Forward
  
  // The left motor
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // Set speed to 150 out 255
  analogWrite(EnA, 200);

  // The right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // Set speed to 150 out 255
  analogWrite(EnB, 200);
}

void mundur() {
// Move backward
  
  // The left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  // Set speed to 150 out 255
  analogWrite(EnA, 200);

  // The right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  // Set speed to 150 out 255
  analogWrite(EnB, 200);
}

void kiri() {
// Move left
  
  // The left motor
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // Set speed to 150 out 255
  analogWrite(EnA, 200);

  // The right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  // Set speed to 150 out 255
  analogWrite(EnB, 200);
}

void kanan() {
// Move right

  // The left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  // Set speed to 150 out 255
  analogWrite(EnA, 200);

  // The right motor
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // Set speed to 150 out 255
  analogWrite(EnB, 200);
}

void berhenti() {
// Stop
  
  // The left motor
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  // The right motor
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void loop() {

  if (radio.available()) {
    bool done = false;
    while (!done) {
      radio.read(msg, 1);

      if (msg[0] == 114) {
        delay(10);
        kiri();
      }
      else if (msg[0] == 115) {
        delay(10);
        kanan();
      }
      else if (msg[0] == 116) {
        delay(10);
        maju();
        digitalWrite(led, HIGH);
      }
      else if (msg[0] == 117) {
        delay(10);
        mundur();
        digitalWrite(led, HIGH);
      }
      else if (msg[0] == 118) {
        delay(10);
        digitalWrite(led, HIGH);
      }
      else if (msg[0] == 111) {
        delay(10);
        maju();
      }
      else if (msg[0] == 112) {
        delay(10);
        mundur();
      }
      else if (msg[0] == 113) {
        delay(10);
        digitalWrite(led, HIGH);
      }
      else {
        berhenti();
        digitalWrite(led, LOW);
      }
      delay(30);
    }
  }
}
