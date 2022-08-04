#include <LedControl.h>
#define MIC A0
int DIN = 12;
int CS =  11;
int CLK = 10;
int sig = 0;
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
void setup(){
    lc.shutdown(0,false); // Wake up displays 
    lc.shutdown(1,false); 
    lc.setIntensity(0,5); // Set intensity levels 
    lc.setIntensity(1,5); 
    lc.clearDisplay(0); // Clear Displays 
    lc.clearDisplay(1);
    }
void sinvader1a() { 
    sig = analogRead(MIC)/14;
    Serial.print(sig);
   if ((sig==0)||(sig==1)||(sig==2))
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,invader1a[i]);
        lc.setRow(1,i,invader1b[i]);}
        delay(100);
        }
     else if ((sig>3&&sig<=4)||(sig<0)) 
        {for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader2a[i]);
        lc.setRow(1,i,invader2b[i]);} 
        delay(250);
        } 
    else if (sig>4&&sig<6) 
        {for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader3a[i]);
        lc.setRow(1,i,invader3b[i]);} 
        delay(350);
        } 
    else if (sig>=6) 
        { for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader4a[i]);
        lc.setRow(1,i,invader4b[i]);} 
        delay(500);
        }
    }
void loop(){     
sinvader1a(); }
