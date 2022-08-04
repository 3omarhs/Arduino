//int vu[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;
int sig = 0;
int p,i,z1=0;

byte a[8] =     {0x00, 0xE9, 0x89, 0xE9, 0x29, 0xEF, 0x00, 0x00,};
byte b[8] =     {0x00, 0xE7, 0x94, 0xE7, 0x91, 0xE7, 0x00, 0x00,};
byte c[8] =     {0x00, 0xEC, 0x8A, 0x8C, 0x8A, 0xEA, 0x00, 0x00,};
byte d[8] =     {0x00, 0xEE, 0x49, 0x4E, 0x49, 0xEE, 0x00, 0x00,};
byte e[8] = {0x00, 0xF0, 0x80, 0xF0, 0x80, 0xF0, 0x00, 0x00,};
byte n[8] = {B11000001, B11100001, B11110001, B10111001, B10011101, B10001111, B10000111, B10000011};
byte s1[8] = {B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};
byte l1[8] = {B00011000, B00100100, B00100100, B00100100, B00100100, B00100100, B00100100, B00011000};
byte h1[8] = {B00011000, B00100100, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000};
byte k1[8] = {B00011000, B00100100, B01000010, B10000001, B10000001, B01000010, B00100100, B00011000};


byte d0[8] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B11111111};
byte d1[8] = {B00000000, B00000000, B00000000, B00000000, B00000000, B01010010, B01110110, B11111111};
byte d2[8] = {B00000000, B00000000, B00000000, B00000000, B00000000, B10101001, B11101011, B11111111};
byte d3[8] = {B00000000, B00000000, B00000000, B10010010, B10010010, B11011111, B11111111, B11111111};
byte d4[8] = {B00000000, B00000000, B00000000, B01001001, B01101011, B11101111, B11111111, B11111111};
byte d5[8] = {B00000000, B10010010, B11010011, B11010011, B11111011, B11111111, B11111111, B11111111};
byte d6[8] = {B00000000, B00101100, B10101100, B11101110, B11101111, B11111111, B11111111, B11111111};
LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup()
{
for (i = 0; i < 14; i++)  
//  pinMode(vu[i], OUTPUT);
//Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  lc.shutdown(0, false);      //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 15);     // Set the brightness to maximum value
  lc.clearDisplay(0);         // and clear the display
}
void loop()
{
p = analogRead(A0);
//Serial.println(s);  
p = p;// / 48;      //Change the  sensitivity by changing Denominator
 /* if(p<15)
  {
  if (p == 0)  
   {
   //for(i = 0; i < 14; i++)
     {
     printByte(s1);
    delay(10);
     }
  }
  else
  {
 //  for (i = 0; i < p; i++) 
    {
      printByte(h1);
    delay(450);
    }
   // for(i = i; i < 14; i++)  
     {
      printByte(s1);
    delay(10);
     }
  }
  }*/
  Serial.print(p);
  p=z1;
  if (z1=6){digitalWrite(2,HIGH);delay(100);digitalWrite(2,LOW);}
  else if (z1=7){digitalWrite(2,HIGH);delay(100);digitalWrite(2,LOW);}
  else if (z1=8){digitalWrite(2,HIGH);delay(100);digitalWrite(2,LOW);}
  else if (z1=0){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=1){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=2){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=3){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=4){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=5){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  //if (p=8){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else if (z1=9){digitalWrite(4,HIGH);digitalWrite(5,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);}
  else {digitalWrite(4,HIGH);digitalWrite(5,HIGH);digitalWrite(7,HIGH);delay(100);digitalWrite(4,LOW);digitalWrite(5,LOW);digitalWrite(7,LOW);}
  
}
void printByte(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}
