#include <SoftwareSerial.h>
// Define a Software Serial object and the used pins 
SoftwareSerial softSerial(8, 9);  // RX, TX 
void setup()  {
  Serial.begin(9600); 
  softSerial.begin(9600);
} 
void loop()  { 
// Check for received characters from the computer 
  for(int i=0; i<=9; i++){
//    if (Serial.available())  { 
  // Write what is received to the soft serial 
      //Serial.print("i= ");
      //Serial.println(i);
      softSerial.write('x');
      Serial.println('x');
      delay(100);
//    }
  }  
}
