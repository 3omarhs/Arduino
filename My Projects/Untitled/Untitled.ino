#include <Keypad.h> 
#include "SPI.h"
#include "MFRC522.h" 
#define SS_PIN 10 
#define RST_PIN 9 
//#include <LiquidCrystal.h>
//#include <Servo.h>
//Servo //servo;                                    //Servo

const int buttonPin = 2; 
const int buttonPinb = 3; 
int motor = 7;
int reverse = 8;
int greenLed = 5;                               //Green led
int redLed = 6;                                 //Red led
int buzzer = 4;                                 //Buzzer
int m=0,n=0;
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
byte columnspPins[4] = {A4, A5, A6, A7};         //Columns pins  

Keypad kpad = Keypad(makeKeymap(keypad), 
rowsPins, columnspPins, 4, 4);                 //Keypad map

MFRC522 rfid(SS_PIN, RST_PIN); 

MFRC522::MIFARE_Key key;
void setup() 
{
  Serial.begin(9600); 

  SPI.begin(); 

  rfid.PCD_Init(); 

 // servo.attach(13);
  pinMode(greenLed, OUTPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(reverse, OUTPUT);
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
   
    {

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())  

    return; 

  // Serial.print(F("PICC type: ")); 

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak); 

  // Serial.println(rfid.PICC_GetTypeName(piccType)); 

  // Check is the PICC of Classic MIFARE type 

  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && 

    piccType != MFRC522::PICC_TYPE_MIFARE_1K && 

    piccType != MFRC522::PICC_TYPE_MIFARE_4K) { 

    Serial.println(F("Your tag is not of type MIFARE Classic.")); 

    return; 

  } 

  String strID = ""; 

  for (byte i = 0; i < 4; i++) { 

    strID += 

    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") + 

    String(rfid.uid.uidByte[i], HEX) + 

    (i!=3 ? ":" : ""); 

  } 

  strID.toUpperCase(); 

  Serial.print("Tap card key: "); 

  Serial.println(strID); 

if(strID.indexOf("59:26:E9:A9")>=0) 

{ 

  Serial.println("card accepted"); 

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
else if(strID.indexOf("F2:71:5A:D3")>=0) 

{ 

  Serial.println("card accepted"); 

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
else if(strID.indexOf("09:C4:E4:2A")>=0) 

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
else if(strID.indexOf("1E:F5:0B:FA")>=0) 

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
else 
{ 
  digitalWrite(motor, LOW);
  } 

  rfid.PICC_HaltA(); 

  rfid.PCD_StopCrypto1(); 

} 

     
    
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
    
     {
      
   
    
//  servo.write(0);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  charKey = kpad.getKey();  

  
  if(charKey&&charKey!='#'&&charKey!='*'&&charKey!='D'&&charKey!='C') 
  {
    enteredPassword[i++] = charKey;  

  //  lcd.setCursor(i, 1); 
  //  lcd.print("*");   
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
  }

  if (i == 8)
  { 
    delay(200);
    char correctPassword[8] = {'A','B','A','B','1','2','1','2'};        //Correct password

    if ((strncmp(enteredPassword, correctPassword, 8)==  0))
    {
 /*   lcd.clear();
     lcd.setCursor(0, 0);
     servo.write(90);
     lcd.print("Access Granted!!!"); */
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
//     lcd.clear();
//     lcd.setCursor(0, 0); 
//     lcd.print("Password: ");   
      i = 0;
    }
                //from here0
            else if (i == 8)
  { 
    delay(200);
 char correctPassword[8] = {'7','7','9','9','5','5','9','9'};        //Correct password

    if ((strncmp(enteredPassword, correctPassword, 8)==  0))
    {
 /*   lcd.clear();
     lcd.setCursor(0, 0);
     servo.write(90);
     lcd.print("Access Granted!!!"); */
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
//     lcd.clear();
//     lcd.setCursor(0, 0); 
//     lcd.print("Password: ");   
      i = 0;
    }
            //tell here0
         
                
                     
    else
    {
  //    lcd.clear();
  //    lcd.setCursor(0, 0); 
//     lcd.print("Access Denied!!!");  
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      digitalWrite(reverse, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(reverse, LOW);
//     lcd.clear();
  //    lcd.setCursor(0, 0); 
  //    lcd.print("Password: "); 
      i = 0;
    }
     
                   
  }}
}}
