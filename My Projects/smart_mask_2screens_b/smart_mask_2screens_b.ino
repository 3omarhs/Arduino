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

byte o0[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte o1[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111};
byte o2[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,B00010000};
byte o3[]= {B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,B00010000,B00010000};
byte o4[]= {B00000000,B00000000,B00000000,B00000000,B11111111,B00010000,B00010000,B11111111};
byte o5[]= {B00000000,B00000000,B00000000,B11111111,B00010000,B00010000,B11111111,B00000000};
byte o6[]= {B00000000,B00000000,B11111111,B00010000,B00010000,B11111111,B00000000,B10000001};
byte o7[]= {B00000000,B11111111,B00010000,B00010000,B11111111,B00000000,B10000001,B11111111};
byte o8[]= {B11111111,B00010000,B00010000,B11111111,B00000000,B10000001,B11111111,B10000001};
byte o9[]= {B00010000,B00010000,B11111111,B00000000,B10000001,B11111111,B10000001,B00000000};
byte o10[]= {B00010000,B11111111,B00000000,B10000001,B11111111,B10000001,B00000000,B00000000};
byte o11[]= {B11111111,B00000000,B10000001,B11111111,B10000001,B00000000,B00000000,B00000000};
byte o12[]= {B00000000,B10000001,B11111111,B10000001,B00000000,B00000000,B00000000,B10000001};
byte o13[]= {B10000001,B11111111,B10000001,B00000000,B00000000,B00000000,B10000001,B11111111};
byte o14[]= {B11111111,B10000001,B00000000,B00000000,B00000000,B10000001,B11111111,B10000001};
byte o15[]= {B10000001,B00000000,B00000000,B00000000,B10000001,B11111111,B10000001,B00000000};
byte o16[]= {B00000000,B00000000,B00000000,B10000001,B11111111,B10000001,B00000000,B11111010};
byte o17[]= {B00000000,B00000000,B10000001,B11111111,B10000001,B00000000,B11111010,B00001011};
byte o18[]= {B00000000,B10000001,B11111111,B10000001,B00000000,B11111010,B00001011,B01111000};
byte o19[]= {B11111111,B10000001,B00000000,B11111010,B00001011,B01111000,B00001000,B00001000};
byte o20[]= {B11111111,B10000001,B00000000,B11111010,B00001011,B01111000,B00001000,B11111000};
byte o21[]= {B10000001,B00000000,B11111010,B00001011,B01111000,B00001000,B11111000,B00000000};
byte o22[]= {B00000000,B11111010,B00001011,B01111000,B00001000,B11111000,B00000000,B00000000};
byte o23[]= {B11111010,B00001011,B01111000,B00001000,B11111000,B00000000,B00000000,B00000000};
byte o24[]= {B00001011,B01111000,B00001000,B11111000,B00000000,B00000000,B00000000,B00111100};
byte o25[]= {B01111000,B00001000,B11111000,B00000000,B00000000,B00000000,B00111100,B01000010};
byte o26[]= {B00001000,B11111000,B00000000,B00000000,B00000000,B00111100,B01000010,B10000001};
byte o27[]= {B11111000,B00000000,B00000000,B00000000,B00111100,B01000010,B10000001,B10000001};
byte o28[]= {B00000000,B00000000,B00000000,B00111100,B01000010,B10000001,B10000001,B10000001};
byte o29[]= {B00000000,B00000000,B00111100,B01000010,B10000001,B10000001,B10000001,B10000001};
byte o30[]= {B00000000,B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010};
byte o31[]= {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte o32[]= {B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100,B00000000};
byte o33[]= {B10000001,B10000001,B10000001,B10000001,B01000010,B00111100,B00000000,B11111000};
byte o34[]= {B10000001,B10000001,B10000001,B01000010,B00111100,B00000000,B11111000,B00001000};
byte o35[]= {B10000001,B10000001,B01000010,B00111100,B00000000,B11111000,B00001000,B01111000};
byte o36[]= {B10000001,B01000010,B00111100,B00000000,B11111000,B00001000,B01111000,B00001000};
byte o37[]= {B01000010,B00111100,B00000000,B11111000,B00001000,B01111000,B00001000,B11111000};
byte o38[]= {B00111100,B00000000,B11111000,B00001000,B01111000,B00001000,B11111000,B00000000};
byte o39[]= {B00000000,B11111000,B00001000,B01111000,B00001000,B11111000,B00000000,B00110000};
byte o40[]= {B11111000,B00001000,B01111000,B00001000,B11111000,B00000000,B00110000,B01001000};
byte o41[]= {B00001000,B01111000,B00001000,B11111000,B00000000,B00110000,B01001000,B10000100};
byte o42[]= {B01111000,B00001000,B11111000,B00000000,B00110000,B01001000,B10000100,B10000100};
byte o43[]= {B00001000,B11111000,B00000000,B00110000,B01001000,B10000100,B10000100,B01000100};
byte o44[]= {B11111000,B00000000,B00110000,B01001000,B10000100,B10000100,B01000100,B00111100};
byte o45[]= {B00000000,B00110000,B01001000,B10000100,B10000100,B01000100,B00111100,B01000000};
byte o46[]= {B00110000,B01001000,B10000100,B10000100,B01000100,B00111100,B01000000,B00000000};
byte o47[]= {B01001000,B10000100,B10000100,B01000100,B00111100,B01000000,B00000000,B11111100};
byte o48[]= {B10000100,B10000100,B01000100,B00111100,B01000000,B00000000,B11111100,B00001000};
byte o49[]= {B10000100,B01000100,B00111100,B01000000,B00000000,B11111100,B00001000,B00000100};
byte o50[]= {B01000100,B00111100,B01000000,B00000000,B11111100,B00001000,B00000100,B00000100};
byte o51[]= {B00111100,B01000000,B00000000,B11111100,B00001000,B00000100,B00000100,B00000100};
byte o52[]= {B01000000,B00000000,B11111100,B00001000,B00000100,B00000100,B00000100,B00000000};
byte o53[]= {B00000000,B11111100,B00001000,B00000100,B00000100,B00000100,B00000000,B00000000};

byte h1[8]= {B00001100,B00011110,B00111110,B01111100,B01111100,B00111110,B00011110,B00001100};
byte h2[8]= {B11110011,B11100001,B11000001,B10000011,B10000011,B11000001,B11100001,B11110011};

byte t0a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00100100, B00100100,};
byte t0b[] = { B00100100, B00100100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte t1a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00110100, B01110100,};
byte t1b[] = { B01110100, B00110100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte t2a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00110100, B01110100, B11110100,};
byte t2b[] = { B11110100, B01110100, B00110100, B00100100, B00100100, B00011000, B00011000, B00011000,};
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
    lc.shutdown(0,false); // Wake up displays 
    lc.shutdown(1,false); 
    lc.setIntensity(0,5); // Set intensity levels 
    lc.setIntensity(1,5); 
    lc.clearDisplay(0); // Clear Displays 
    lc.clearDisplay(1);
    }
    
/*void sinvader1a() { 
    sig = analogRead(MIC)/11;
    Serial.println(" b ");
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
        delay(200);
        for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader2a[i]);
        lc.setRow(1,i,invader2b[i]);}
        delay(150);
        for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader3a[i]);
        lc.setRow(1,i,invader3b[i]);}
        delay(150);
         for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader4a[i]);
        lc.setRow(1,i,invader4b[i]);} 
        delay(200);
        }
    }*/
    void sinvader1a() { 
    sig = analogRead(MIC)/15;
    Serial.println(" b ");
    Serial.print(sig);
   if ((sig==4))
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,invader1a[i]);
        lc.setRow(1,i,invader1b[i]);}
        delay(1);
        }
     else if ((sig>5&&sig<=6)||(sig<3)) 
        {for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader2a[i]);
        lc.setRow(1,i,invader2b[i]);} 
        delay(250);
         for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader3a[i]);
        lc.setRow(1,i,invader3b[i]);}
        delay(250);
        for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader2a[i]);
        lc.setRow(1,i,invader2b[i]);} 
        delay(250);
        } 
    else if (sig>6&&sig<8) 
        {for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader3a[i]);
        lc.setRow(1,i,invader3b[i]);} 
        delay(350);
        } 
    else if (sig>=8) 
        { for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader4a[i]);
        lc.setRow(1,i,invader4b[i]);}
        delay(200);
        for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader2a[i]);
        lc.setRow(1,i,invader2b[i]);}
        delay(150);
        for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader3a[i]);
        lc.setRow(1,i,invader3b[i]);}
        delay(150);
         for (int i = 0; i < 8; i++) {
        lc.setRow(0,i,invader4a[i]);
        lc.setRow(1,i,invader4b[i]);} 
        delay(200);
        }
    }
void name() {
       {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o0[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
         {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o1[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o2[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o3[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o4[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o5[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o6[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o7[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o8[i]);
        lc.setRow(0,i,o0[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o9[i]);
        lc.setRow(0,i,o1[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o10[i]);
        lc.setRow(0,i,o2[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o11[i]);
        lc.setRow(0,i,o3[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o12[i]);
        lc.setRow(0,i,o4[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o13[i]);
        lc.setRow(0,i,o5[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o14[i]);
        lc.setRow(0,i,o6[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o15[i]);
        lc.setRow(0,i,o7[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o16[i]);
        lc.setRow(0,i,o8[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o17[i]);
        lc.setRow(0,i,o9[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o18[i]);
        lc.setRow(0,i,o10[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o19[i]);
        lc.setRow(0,i,o11[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o20[i]);
        lc.setRow(0,i,o12[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o21[i]);
        lc.setRow(0,i,o13[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o22[i]);
        lc.setRow(0,i,o14[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o23[i]);
        lc.setRow(0,i,o15[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o24[i]);
        lc.setRow(0,i,o16[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o25[i]);
        lc.setRow(0,i,o17[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o26[i]);
        lc.setRow(0,i,o18[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o27[i]);
        lc.setRow(0,i,o19[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o28[i]);
        lc.setRow(0,i,o20[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o29[i]);
        lc.setRow(0,i,o21[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o30[i]);
        lc.setRow(0,i,o22[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o31[i]);
        lc.setRow(0,i,o23[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o32[i]);
        lc.setRow(0,i,o24[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o33[i]);
        lc.setRow(0,i,o25[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o34[i]);
        lc.setRow(0,i,o26[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o35[i]);
        lc.setRow(0,i,o27[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o36[i]);
        lc.setRow(0,i,o28[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o37[i]);
        lc.setRow(0,i,o29[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o38[i]);
        lc.setRow(0,i,o30[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o39[i]);
        lc.setRow(0,i,o31[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o40[i]);
        lc.setRow(0,i,o32[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o41[i]);
        lc.setRow(0,i,o33[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o42[i]);
        lc.setRow(0,i,o34[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o43[i]);
        lc.setRow(0,i,o35[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o44[i]);
        lc.setRow(0,i,o36[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o45[i]);
        lc.setRow(0,i,o37[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o46[i]);
        lc.setRow(0,i,o38[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o47[i]);
        lc.setRow(0,i,o39[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o48[i]);
        lc.setRow(0,i,o40[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o49[i]);
        lc.setRow(0,i,o41[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o50[i]);
        lc.setRow(0,i,o42[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o51[i]);
        lc.setRow(0,i,o43[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o52[i]);
        lc.setRow(0,i,o44[i]);}
        }
        delay(400);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,o53[i]);
        lc.setRow(0,i,o45[i]);}
        }
    delay(1000);
    }
    
void heart() {
      {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,h1[i]);
        lc.setRow(0,i,h1[i]);}
        }
        delay(800);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(1,i,h2[i]);
        lc.setRow(0,i,h2[i]);}
        }
        delay(800);
    }

void tongue() {
      {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,t0a[i]);
        lc.setRow(1,i,t0b[i]);}
        }
        delay(800);
      {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,t1a[i]);
        lc.setRow(1,i,t1b[i]);}
        }
        delay(150);
        {for (int i = 0; i < 8; i++) { 
        lc.setRow(0,i,t2a[i]);
        lc.setRow(1,i,t2b[i]);}
        }
        delay(800);
    }
    
void loop(){     
sinvader1a(); 
//name();
//heart();
//tongue();
}
