// Include the required Wire library for I2C<br>
#include<Wire.h>
int x = 0;
const int button = 8;
void setup() {
  // Start the I2C Bus as Master
  pinMode(button,INPUT);
  Wire.begin(); 
  Wire.beginTransmission(9);
  Wire.write(88);
  Wire.endTransmission();
delay(1000);

 Wire.beginTransmission(9); // transmit to device #9
  Wire.write(4);              // sends x 
  Wire.endTransmission();
delay(1000);

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
delay(1000);
Wire.beginTransmission(9); // transmit to device #9
  Wire.write(0);              // sends x 
  Wire.endTransmission();
}
void loop() {
  if(digitalRead(button) == HIGH){
    Wire.beginTransmission(9); // transmit to device #9
  Wire.write(5);              // sends x 
  Wire.endTransmission();
  off();
  }
  /*x++; // Increment x
  if (x > 5) x = 0; // `reset x once it gets 6
  delay(500);*/
}
void off(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(0);              // sends x 
  Wire.endTransmission();
}
