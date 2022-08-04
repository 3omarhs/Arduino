#include <Servo.h>
int out1 = 5;
int out2 = 6;
int out3 = 7;
Servo servo;                                    //Servo

int i = 0;                                      //Counter

void setup() 
{
  servo.attach(A0);
  pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
pinMode(out3, OUTPUT);
    
}

void loop() 
{
  for(i =0; i < 200; i++) //When servo is a position 0, servo will rotate to 180 degrees (half rotation)
     { 
        servo.write(i); 
        delay(15); 
        };
 for(i = 200; i > 0; i--) //When servo is a position 180, servo will rotate to 0 degrees (beginning position)
     { 
        servo.write(i); 
        delay(15); 
        }
    digitalWrite(out1, HIGH);
    delay(300);
    digitalWrite(out1, LOW);
    delay(300);
    digitalWrite(out2, HIGH);
    delay(300);
    digitalWrite(out2, LOW);
    delay(300);
    digitalWrite(out3, HIGH);
    delay(300);
    digitalWrite(out3, LOW);
    delay(300);
  
    }