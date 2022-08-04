#include <SoftwareSerial.h>
// Define a Software Serial object and the used pins 
SoftwareSerial softSerial(8, 9);
// LED Pin 
int LED = 13; 
void setup()  { 
softSerial.begin(9600); 
pinMode(LED, OUTPUT);
} 
void loop()  { 
// Check if there is anything in the soft Serial Buffer 
  if (softSerial.available()){
// Read one value from the soft serial buffer and store it in the variable com 
    char com = softSerial.read(); 


    
// Act according to the value received 
    /*if (com == 'x')  { 
// Stop the LED 
      digitalWrite(LED, LOW); 
    } 
    else if (com == 'a')  { 
// Start the LED 
    digitalWrite(LED, HIGH); 
    } */
    Serial.print(com);
      digitalWrite(LED, HIGH);
      delay(500);
      Serial.println("Recieved");
    }
    
  
  {
    for(int i=0; i<=9; i++){
      if (i%2 == 0)  { 
      digitalWrite(LED, HIGH);
      Serial.println("Not Recieved");
      delay(100);
      digitalWrite(LED, LOW); 
      delay(100);
    }
    }
  }
}
