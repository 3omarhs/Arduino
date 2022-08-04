#include <LedControl.h>
#define MIC A0
int DIN = 12;
int CS =  11;
int CLK = 10;
int sig = 0;
int A,B,C,D;

byte a[8]=     {0x00,0xE9,0x89,0xE9,0x29,0xEF,0x00,0x00,};
byte b[8]=     {0x00,0xE7,0x94,0xE7,0x91,0xE7,0x00,0x00,};
byte c[8]=     {0x00,0xEC,0x8A,0x8C,0x8A,0xEA,0x00,0x00,};
byte d[8]=     {0x00,0xEE,0x49,0x4E,0x49,0xEE,0x00,0x00,};
byte e[8]= {0x00,0xF0,0x80,0xF0,0x80,0xF0,0x00,0x00,};
byte s[8]= {00000000, 00000000, 00000000, 0xFF,0xFF,  B00000000, 00000000, 00000000};


byte invader01a[] = 
    { B00011000,B00111100, B01111110, B11011011, B11111111, B00100100, B01011010, B10100101 
    }; 

byte n[8]= {B11000001,B11100001,B11110001,B10111001,B10011101,B10001111,B10000111,B10000011};
byte s1[8]= {B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000};
byte l1[8]= {B00011000,B00100100, B00100100, B00100100, B00100100, B00100100, B00100100,B00100100};
byte h1[8]= {B00011000,B00100100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010//B00100100,B00011000
    };
byte k1[8]= {B00011000,B00100100,B01000010,B10000001,B10000001,B10000001,B10000001,B10000001,};


byte d0[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111};
byte d1[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B01010010,B01110110,B11111111};
byte d2[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B10101001,B11101011,B11111111};
byte d3[8]= {B00000000,B00000000,B00000000,B10010010,B10010010,B11011111,B11111111,B11111111};
byte d4[8]= {B00000000,B00000000,B00000000,B01001001,B01101011,B11101111,B11111111,B11111111};
byte d5[8]= {B00000000,B10010010,B11010011,B11010011,B11111011,B11111111,B11111111,B11111111};
byte d6[8]= {B00000000,B00101100,B10101100,B11101110,B11101111,B11111111,B11111111,B11111111};

LedControl lc=LedControl(DIN,CLK,CS,0); 

void setup(){
    
pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
   lc.shutdown(0,false); // Wake up displays 
    lc.shutdown(1,false); 
    lc.setIntensity(0,5); // Set intensity levels 
    lc.setIntensity(1,5); 
    lc.clearDisplay(0); // Clear Displays 
    lc.clearDisplay(1);
    
    
    
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}
void dcart() {
    sig = analogRead(MIC)*25;

 if (sig==0) //||(sig>0&&sig<300)) 
     {printByte(d0); }
     else if (sig>775&&sig<800){ printByte(d1); delay(100); printByte(d2); printByte(d0);} 
    else if (sig>800&&sig<900) {printByte(d3); delay(100); printByte(d4); printByte(d0);} 
    else if (sig>900) {printByte(d5); delay(100); printByte(d6); printByte(d0);} 
   
}
void dcartt() {
    sig = analogRead(MIC)*50;

 if (sig==0) //||(sig>0&&sig<300)) 
     {printByte(d0); }
     else if (sig>50&&sig<400){ printByte(d1); delay(100); printByte(d2); printByte(d0);} 
    else if (sig>400&&sig<700) {printByte(d3); delay(100); printByte(d4); printByte(d0);} 
    else if (sig>700) {printByte(d5); delay(100); printByte(d6); printByte(d0);} 
   
}

void led() {
 sig = analogRead(MIC)*50;
    if (sig==0) //||(sig>0&&sig<300)) 
    {printByte(s1);
        
        delay(10);
        }  
    else if (sig>50&&sig<250) {printByte(l1);
        
        delay(250);
        } 
    else if (sig>250&&sig<500) {printByte(h1);
       
        delay(350);
        } 
    else if (sig>700) {printByte(k1);
        
        delay(500);
        } }

/*void leda() {
 sig = analogRead(MIC)*50;
    if (sig==0) //||(sig>0&&sig<300)) 
    {printByte1(s1);
        
        delay(10);
        }  
    else if (sig>50&&sig<250) {printByte1(l1);
        
        delay(250);
        } 
    else if (sig>250&&sig<500) {printByte1(h1);
       
        delay(350);
        } 
    else if (sig>700) {printByte1(k1);
        
        delay(500);
        } }
    
    */
    
  void led1() {
    {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,s1[i]);
        lc.setRow(1,i,s1[i]);}
        delay(10);
        }}
 void led2() {
     for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,l1[i]);
        lc.setRow(1,i,l1[i]);}
        delay(250);
        } 
  void led3() {
    for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,h1[i]);
        lc.setRow(1,i,h1[i]);}
        delay(350);
        } 
 void led4() {
    for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,k1[i]);
        lc.setRow(1,i,k1[i]);}
        delay(500);
        }
    
    

void loop(){ 

    byte f[8]=   {0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
    byte g[8]= {0xFF,0x99,0x00,0x00,0x81,0xC3,0xE7,0xFF,};
    byte h[8]=   {0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
    byte i[8] = {0xFF,0x99,0x00,0x00,0x81,0xC3,0xE7,0xFF,};
    
    /*printByte(d11);
     
    delay(100);

    printByte(d12);
    
    delay(100);
    
    printByte(d11);
     
    delay(100);

    printByte(d12);
    
    delay(1000);
  
    printByte(d21);
     
    delay(100);

    printByte(d22);
    
    delay(100);
    
    printByte(d21);
     
    delay(100);

    printByte(d22);
    
    delay(1000);

    printByte(d31);    

    delay(100);

    printByte(d32);

    delay(100); 
    
    printByte(d31);    

    delay(100);

    printByte(d32);

    delay(1000); */
    
   
    
   // printEduc8s();
   
 //   lc.clearDisplay(0);
    
  //  delay(1000);
    
   // dcartt();
  //dcart();
  led();
 // leda(); 
   /* sig = analogRead(MIC)*50;
    if (sig==0) //||(sig>0&&sig<300)) 
        led1();
        
     else if (sig>50&&sig<250) {
        led2();
        }
    else if (sig>250&&sig<500) {
        led3();
        
        }
    else if (sig>700) {
        led4();
        }
    //printByte(s);
 // delay(1000);
  
    */
}

void printEduc8s()
{
printByte(s1);
  delay(1000);
printByte(l1);
  delay(1000);
printByte(h1);
  delay(1000);
printByte(k1);
  delay(1000);
  
  
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
    
  }
}
void printByte1(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(1,i,character[i]);
  }
}
