  #include <Keypad.h>

#include "SPI.h" 

#include "MFRC522.h" 

#define SS_PIN 10 

#define RST_PIN 9 

int m=0,n=0;


//




MFRC522 rfid(SS_PIN, RST_PIN); 

MFRC522::MIFARE_Key key;



const int buttonPin = 7;
const int buttonPinb = 8;
int motor = 2;
int reverse = 3;
int greenLed = 5;                               //Green led
int redLed = 6;                                 //Red led
int buzzer = 4;                                 //Buzzer
const byte rows = 4;    //rows
const byte columns = 4; //columns
char correctPassword[4] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[9];                        //Entered password on keypad
char charKey;                                   //Key on keypad
int i = 0;
int val = 0;
char keypad[4][4] =                             //Keypad array
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowsPins[4] = {A0, A1, A2, A3};//Rows pins
byte columnspPins[4] = {A4, A5, 2, 3};//Columns pins
Keypad kpad = Keypad(makeKeymap(keypad),
rowsPins, columnspPins, 4, 4);    
void setup() { 

Serial.begin(9600); 

SPI.begin(); 

rfid.PCD_Init();

  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(reverse, OUTPUT);
 
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinb, INPUT);

} 

void loop() {
    if (charKey == '#')
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
else {
digitalWrite(motor, LOW);
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
  else {
digitalWrite(motor, LOW);
}
if (charKey)
{
enteredPassword[i++] = charKey;
digitalWrite(buzzer, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
}
if (i == 8)
{
delay(200);
char correctPassword[8] = {'A', 'B', 'A', 'B', '2', '3', '2', '3'};//Correct password
if ((strncmp(enteredPassword, correctPassword, 9) == 0))
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
else
{
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

digitalWrite(motor,HIGH);
delay(250);

digitalWrite(motor,LOW);




} 

else 

{
  digitalWrite(motor, LOW);

} 

        
        
        if(strID.indexOf("F2:71:5A:D3")>=0) 

{ 

Serial.println("card accepted"); 

digitalWrite(motor,HIGH);
delay(250);

digitalWrite(motor,LOW);




} 

else 

{
  digitalWrite(motor, LOW);

} 
if(strID.indexOf("09:C4:E4:2A")>=0) 

{ 

Serial.println("card accepted"); 

digitalWrite(motor,HIGH);
delay(250);

digitalWrite(motor,LOW);




} 

else 

{
digitalWrite(motor, LOW);
}
        
        
        
        
if(strID.indexOf("1E:F5:0B:FA")>=0) 

{ 

Serial.println("card accepted"); 
digitalWrite(motor,HIGH);
delay(250);

digitalWrite(motor,LOW);


//8motor 3reverse 6redled 5greenled 4buzzer 

} 

else 

{ 

  digitalWrite(motor, LOW);
} 

rfid.PICC_HaltA();
rfid.PCD_StopCrypto1(); 

} 

     
    
}
