#include "SPI.h" 

#include "MFRC522.h" 

#define SS_PIN 10 

#define RST_PIN 9 

int m=0,n=0;


//

int out = 3; 
int wrong = 4; 


MFRC522 rfid(SS_PIN, RST_PIN); 

MFRC522::MIFARE_Key key;



void setup() { 

Serial.begin(9600); 

SPI.begin(); 

rfid.PCD_Init();

pinMode(out, OUTPUT);
pinMode(wrong, OUTPUT);

} 

void loop() {
    
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

digitalWrite(out,HIGH);
delay(250);

digitalWrite(out,LOW);




} 

else 

{
  digitalWrite(wrong, LOW);

} 

        
        
        if(strID.indexOf("F2:71:5A:D3")>=0) 

{ 

Serial.println("card accepted"); 

digitalWrite(out,HIGH);
delay(250);

digitalWrite(out,LOW);




} 

else 

{
  digitalWrite(wrong, LOW);

} 
if(strID.indexOf("09:C4:E4:2A")>=0) 

{ 

Serial.println("card accepted"); 

digitalWrite(out,HIGH);
delay(250);

digitalWrite(out,LOW);




} 

else 

{
digitalWrite(wrong, LOW);
}
        
        
        
        
if(strID.indexOf("1E:F5:0B:FA")>=0) 

{ 

Serial.println("card accepted"); 
digitalWrite(out,HIGH);
delay(250);

digitalWrite(out,LOW);


//8motor 3reverse 6redled 5greenled 4buzzer 

} 

else 

{ 

  digitalWrite(wrong, LOW);
} 

rfid.PICC_HaltA();
rfid.PCD_StopCrypto1(); 

} 

     
    
}
