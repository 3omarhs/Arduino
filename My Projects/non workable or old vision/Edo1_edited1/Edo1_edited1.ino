#include <Keypad.h> 
//#include <LiquidCrystal.h>
//#include <Servo.h>
//Servo //servo;                                    //Servo
const int inn = 11;
const int inn2 = 12;
const int buttonPin = 7; 
const int buttonPinb = 10; 
int motor = 8;
int reverse = 9;
int greenLed = 5;                               //Green led
int redLed = 6;                                 //Red led
int buzzer = 4;                                 //Buzzer

//LiquidCrystal lcd(12, 11, 10, 9, 8, 7);         //LCD

const byte rows = 4;    //rows
const byte columns = 4; //columns
char correctPassword[4] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[9];                        //Entered password on keypad
char charKey;                                   //Key on keypad 
int i = 0;     
int val = 0;
                                 //Counter
char keypad[4][4] =                             //Keypad array
{ 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowsPins[4] = {A0, A1, A2, A3};           //Rows pins 
byte columnspPins[4] = {A4, A5, 2, 3};         //Columns pins

Keypad kpad = Keypad(makeKeymap(keypad), 
rowsPins, columnspPins, 4, 4);                 //Keypad map

void setup() 
{
// servo.attach(13);
pinMode(greenLed, OUTPUT);  
pinMode(buzzer, OUTPUT);
pinMode(redLed, OUTPUT);
pinMode(motor, OUTPUT);
pinMode(reverse, OUTPUT);
pinMode(inn, INPUT);
pinMode(inn2, INPUT);
pinMode(buttonPin, INPUT);
pinMode(buttonPinb, INPUT);
 
//  lcd.setCursor(0, 0); 
//lcd.print("Keypad Door Lock"); 
//delay(2000);
//lcd.clear();  
//  lcd.setCursor(0, 0); 
// lcd.print("Password: ");    
//  Serial.begin(9600);    
//Serial.println("Keypad Door Lock");  
}

void loop() 
{
   
if (charKey == '#')

{
digitalWrite(greenLed, HIGH); 
delay(100); 
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(100);
digitalWrite(reverse, HIGH); 
delay(400);
digitalWrite(greenLed, LOW); 
delay(100); 
digitalWrite(reverse, LOW); 
delay(500); 
} 
else {digitalWrite(motor, LOW); 

}
    
    
    
    
    
if (charKey == 'D')

{
enteredPassword[i=0] = charKey;
   
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
} 
else {digitalWrite(motor, LOW); 

}
    
    
if (charKey == 'C')

{
if(i>0){
enteredPassword[i--] = charKey;
        
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}
} 
else {digitalWrite(motor, LOW); 

}
    
    
    
if (charKey == '*')

{
  
for(i=1;i<=3;i++)
{ digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
}
delay(300);
digitalWrite(buzzer, HIGH); 
delay(300); 
digitalWrite(buzzer, LOW); 
delay(100); 
            
digitalWrite(buzzer, HIGH); 
delay(500); 
digitalWrite(buzzer, LOW); 
delay(100); 
     
delay(300);
for(i=1;i<=3;i++)
{ digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
}
           
           
           
delay(600);
for(i=1;i<=3;i++)
{ digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
}
delay(300);
digitalWrite(buzzer, HIGH); 
delay(300); 
digitalWrite(buzzer, LOW); 
delay(100); 
           
digitalWrite(buzzer, HIGH); 
delay(500); 
digitalWrite(buzzer, LOW); 
delay(100); 
     
delay(300);
for(i=1;i<=3;i++)
{ digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
}
  
        
}
else {digitalWrite(motor, LOW); 

}

    
    
val = digitalRead(buttonPinb);// cloase 
if (val == HIGH) 

{
digitalWrite(greenLed, HIGH); 
delay(100); 
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
digitalWrite(reverse, HIGH); 
delay(500); 
digitalWrite(greenLed, LOW); 
delay(100); 
digitalWrite(reverse, LOW); 
delay(500); 
} 
else {digitalWrite(motor, LOW); 

}
    
    
val = digitalRead(buttonPin);// cloase 
if (val == HIGH) 

{
digitalWrite(greenLed, HIGH); 
delay(100); 
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
digitalWrite(motor, HIGH); 
delay(500); 
digitalWrite(greenLed, LOW); 
delay(100);
} 
else {digitalWrite(motor, LOW); 

}



val = digitalRead(inn);// cloase 
if (val == HIGH) 
    

{
digitalWrite(greenLed, HIGH); 
delay(100); 
digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); 
delay(100); 
digitalWrite(motor, HIGH); 
delay(700); 
digitalWrite(greenLed, LOW); 
delay(1000); 
} 
else {digitalWrite(motor, LOW); 
     
}
val = digitalRead(inn2);// cloase 
if (val ==HIGH)
{
digitalWrite(redLed, HIGH); 
/*digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); */
delay(100); 
/* digitalWrite(reverse, HIGH); 
delay(700); */
digitalWrite(redLed, LOW); 
delay(100); 
digitalWrite(reverse, LOW);
} 
else {digitalWrite(motor, LOW); 
     
}
   
{
  
//  servo.write(0);
digitalWrite(redLed,LOW);
digitalWrite(greenLed,LOW);
charKey = kpad.getKey();  

if(charKey&&charKey!='#'&&charKey!='*'&&charKey!='D'&&charKey!='C') 
{
enteredPassword[i++] = charKey;
//  lcd.setCursor(i, 1); 
//  lcd.print("*");   
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
}

if(i==8)
{
delay(200);
switch(correctPassword[8])
{
case ('A','B','A','B','1','2','1','2'):
{
digitalWrite(greenLed, HIGH);
digitalWrite(redLed, LOW);
digitalWrite(motor, HIGH);
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(100);
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
delay(1000);
digitalWrite(motor, LOW);
i = 0;
}
break;
default:{ 
digitalWrite(greenLed, LOW);
digitalWrite(redLed, HIGH);
digitalWrite(reverse, HIGH);
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(1000);
digitalWrite(reverse, LOW);
i = 0;
}
}
}
 
}}
