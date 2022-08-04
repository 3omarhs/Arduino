#include <Servo.h>
#include <elapsedMillis.h>
//http://playground.arduino.cc/Code/ElapsedMillis
//We used a package that lets us see how much time has elapsed since starting the code, which allowed us to continue printing data to the serial port while the random delay is running (instead of using delay();)
#define switchPin 7
#define servoPin 8
#define dialPinMin 0
#define dialPinMax 1
Servo myservo;
elapsedMillis timeElapsed;
long timeElapsedSec;
long delayTimeElapsed;
bool switchPressed;
int servoPos;
long randomNum;
long randomSeedVar;
bool servoMoved = false;
float delayMin;
float delayMax;
 
void setup() {
   pinMode(switchPin, INPUT);
   myservo.attach(servoPin);
   randomSeedVar = analogRead(5);     //generates a pseudo random seed by analog reading an empty pin (more info here: https://programmingelectronics.com/using-random-numbers-with-arduino/)
   randomSeed(randomSeedVar);
   Serial.begin(9600);
}
 
void loop() {
	delayMin = analogRead(dialPinMin);
	delayMax = analogRead(dialPinMax);
	delayMin = map(delayMin, 0, 1023, 5000, 0);
	delayMax = map(delayMax, 0, 1023, 0, 10000);
 	switchPressed = digitalRead(switchPin);
	if(switchPressed) {     //if switch is pressed, move the servo to turn the switch back off.
    	myservo.write(20);
    	servoMoved = false;
 	} else if(!servoMoved) {     //once the switch has been turned off, the servo will wait a random amount of time before moving back to its original position.
      	randomNum = random(delayMin, delayMax);
      	delayTimeElapsed = timeElapsed/2;
      	while(timeElapsed < delayTimeElapsed + randomNum) {     //debugging data will continue to be printed while delaying.
      		debug(true);
      	}
      	myservo.write(100);
      	servoMoved = true;
 	}
	timeElapsedSec = timeElapsed / 1000;
	debug(false);
}
 
void debug(bool delaying) {
	Serial.println("");
	Serial.print("|Elapsed Time: \t");
	Serial.print(timeElapsedSec);
	Serial.print(" | Switched Pressed: \t");
	Serial.print(switchPressed);
	Serial.print(" | Servo Value: \t");
	if(myservo.read() == 90) Serial.print("90");
	else Serial.print(" 0");
	Serial.print(" | Random Number: \t");
	Serial.print(randomNum);
	Serial.print(" | Random Number Seed: \t");
	Serial.print(randomSeedVar);
	Serial.print(" | Min Dial Value: \t");
	Serial.print(analogRead(dialPinMin));
	Serial.print(" | Max Dial Value: \t");
	Serial.print(analogRead(dialPinMax));
	Serial.print(" | Min Delay: \t");
	Serial.print(delayMin / 1000);
	Serial.print(" | Max Delay: \t");
	Serial.print(delayMax / 1000);
	if(delaying) {
		Serial.print("| DELAYING |\t");
	} else {
		Serial.print("|");
	}
	return;
}
