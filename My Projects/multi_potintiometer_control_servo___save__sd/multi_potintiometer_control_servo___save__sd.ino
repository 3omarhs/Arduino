#include <Servo.h>  // add servo library
#include <SPI.h>
#include <SD.h>
File myFile;

 
Servo myservo;  // create servo object to control a servo
Servo myservo1;
 
int potpin = A0;  // analog pin used to connect the potentiometer
int potpin1 = A1;
int val;    // variable to read the value from the analog pin
int val1;
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(8);


  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
  Serial.println("initialization failed!");
  while (1);
  }
  Serial.println("initialization done.");
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
  Serial.print("Writing to test.txt...");
  myFile.println("This is a test file :)");
  myFile.println("testing 1, 2, 3.");
  for (int i = 0; i < 20; i++) {
  myFile.println(i);
  }
  // close the file:
  myFile.close();
  Serial.println("done.");
  } else {
  // if the file didn't open, print an error:
  Serial.println("error opening test.txt");
  }
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
