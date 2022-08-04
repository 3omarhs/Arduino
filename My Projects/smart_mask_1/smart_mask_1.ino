//int vu[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
int p,i;

////////////////////////////////////
#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;
byte invader1a[] = 
    { B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000,}; 

byte invader1b[] = 
    { B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000,};
byte invader2a[] = 
    { B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00100100, B00100100,};
byte invader2b[] = 
    { B00100100, B00100100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte invader3a[] = 
    { B00011000, B00011000, B00100100, B01000010, B01000010, B01000010, B01000010, B01000010,};
byte invader3b[] = 
    { B01000010, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00011000,};
byte invader4a[] = 
    { B00011000, B00100100, B01000010, B10000001, B10000001, B10000001, B10000001, B10000001,};
byte invader4b[] = 
    { B10000001, B10000001, B10000001, B10000001, B10000001, B01000010, B00100100, B00011000,};
 byte d0[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111};
byte d1[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B01010010,B01110110,B11111111};
byte d2[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B10101001,B11101011,B11111111};
byte d3[]= {B00000000,B00000000,B00000000,B10010010,B10010010,B11011111,B11111111,B11111111};
byte d4[]= {B00000000,B00000000,B00000000,B01001001,B01101011,B11101111,B11111111,B11111111};
byte d5[]= {B00000000,B10010010,B11010011,B11010011,B11111011,B11111111,B11111111,B11111111};
byte d6[]= {B00000000,B00101100,B10101100,B11101110,B11101111,B11111111,B11111111,B11111111};   
LedControl lc=LedControl(DIN,CLK,CS,0);
////////////////////////////////////



void setup()
{


  /////////////////////
   lc.shutdown(0,false); // Wake up displays 
    lc.shutdown(1,false); 
    lc.setIntensity(0,5); // Set intensity levels 
    lc.setIntensity(1,5); 
    lc.clearDisplay(0); // Clear Displays 
    lc.clearDisplay(1);
  /////////////////////


  
/*for (i = 0; i < 14; i++)  
  pinMode(vu[i], OUTPUT);*/
//Serial.begin(9600);
}
void loop()
{
  printByte(invader1a);
  printByte1(invader1b);
p = analogRead(A0);
//Serial.println(s);  
p = p / 48;      //Change the  sensitivity by changing Denominator
Serial.print(p);
  if(p<15)
  {
  if (p == 0)  
   {
   for(i = 0; i < 8; i++)
     {
      printByte(invader1a);
      printByte1(invader1b);
    // digitalWrite(vu[i], LOW);
     }
  }
  else
  {
   for (i = 0; i <8;  i++) 
    {
      printByte(invader2a);
      printByte1(invader2b);
    // digitalWrite(vu[i], HIGH);
     delay(5);
    }
    for(i = i; i < 8; i++)  
     {
      printByte(invader3a);
      printByte1(invader3b);
     // digitalWrite(vu[i], LOW);
     }
  }
  }
}
void printByte(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}
void printByte1(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(1, i, character[i]);
  }
}
