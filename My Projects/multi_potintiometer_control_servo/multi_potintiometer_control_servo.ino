#include <Servo.h>  // add servo library
 
Servo myservo;  // create servo object to control a servo
Servo myservo1;
 
int potpin = A0;  // analog pin used to connect the potentiometer
int potpin1 = A1;
int val;    // variable to read the value from the analog pin
int val1;
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(8);
}
 
void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                // sets the servo position according to the scaled value
  
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val1);                // sets the servo position according to the scaled value
  
  delay(15);                           // waits for the servo to get there
}
