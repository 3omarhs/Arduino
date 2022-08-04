#include <LedControl.h>
#define MIC A2
int DIN = 7;
int CS =  6;
int CLK = 5;
int sig = 0;
int timer,held;

long button_delay = 0;
long status_button = 0;

long buttonTimer = 0;
long longPressTime = 6000;
long shortPressTime = 1000;

boolean buttonActive = false;
boolean longPressActive = false;
boolean shortPressActive = false;

const int button  = 3;
int j = 0, val = 0, val0 = 0, val1 = 0, val2 = 0, val3 = 0;
byte invader1a[] = {B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000,};
byte invader1b[] = {B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000,};
byte invader2a[] = {B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00100100, B00100100,};
byte invader2b[] = {B00100100, B00100100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte invader3a[] = {B00011000, B00011000, B00100100, B01000010, B01000010, B01000010, B01000010, B01000010,};
byte invader3b[] = {B01000010, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00011000,};
byte invader4a[] = {B00011000, B00100100, B01000010, B10000001, B10000001, B10000001, B10000001, B10000001,};
byte invader4b[] = {B10000001, B10000001, B10000001, B10000001, B10000001, B01000010, B00100100, B00011000,};

byte d0[] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B11111111};
byte d1[] = {B00000000, B00000000, B00000000, B00000000, B00000000, B01010010, B01110110, B11111111};
byte d2[] = {B00000000, B00000000, B00000000, B00000000, B00000000, B10101001, B11101011, B11111111};
byte d3[] = {B00000000, B00000000, B00000000, B10010010, B10010010, B11011111, B11111111, B11111111};
byte d4[] = {B00000000, B00000000, B00000000, B01001001, B01101011, B11101111, B11111111, B11111111};
byte d5[] = {B00000000, B10010010, B11010011, B11010011, B11111011, B11111111, B11111111, B11111111};
byte d6[] = {B00000000, B00101100, B10101100, B11101110, B11101111, B11111111, B11111111, B11111111};

byte o0[]  = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte o1[]  = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B10000001};
byte o2[]  = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B10000001, B11111111};
byte o3[]  = {B00000000, B00000000, B00000000, B00000000, B00000000, B10000001, B11111111, B10000001};
byte o4[]  = {B00000000, B00000000, B00000000, B00000000, B10000001, B11111111, B10000001, B00000000};
byte o5[]  = {B00000000, B00000000, B00000000, B10000001, B11111111, B10000001, B00000000, B00001100};
byte o6[]  = {B00000000, B00000000, B10000001, B11111111, B10000001, B00000000, B00001100, B00011110};
byte o7[]  = {B00000000, B10000001, B11111111, B10000001, B00000000, B00001100, B00011110, B00111110};
byte o8[]  = {B10000001, B11111111, B10000001, B00000000, B00001100, B00011110, B00111110, B01111100};
byte o9[]  = {B11111111, B10000001, B00000000, B00001100, B00011110, B00111110, B01111100, B01111100};
byte o10[] = {B10000001, B00000000, B00001100, B00011110, B00111110, B01111100, B01111100, B00111110};
byte o11[] = {B00000000, B00001100, B00011110, B00111110, B01111100, B01111100, B00111110, B00011110};
byte o12[] = {B00001100, B00011110, B00111110, B01111100, B01111100, B00111110, B00011110, B00001100};
byte o13[] = {B00011110, B00111110, B01111100, B01111100, B00111110, B00011110, B00001100, B00000000};
byte o14[] = {B00111110, B01111100, B01111100, B00111110, B00011110, B00001100, B00000000, B01000100};
byte o15[] = {B01111100, B01111100, B00111110, B00011110, B00001100, B00000000, B01000100, B10001010};
byte o16[] = {B01111100, B00111110, B00011110, B00001100, B00000000, B01000100, B10001010, B10010001};
byte o17[] = {B00111110, B00011110, B00001100, B00000000, B01000100, B10001010, B10010001, B10010001};
byte o18[] = {B00011110, B00001100, B00000000, B01000100, B10001010, B10010001, B10010001, B10010001};
byte o19[] = {B00001100, B00000000, B01000100, B10001010, B10010001, B10010001, B10010001, B10010001};
byte o20[] = {B00000000, B01000100, B10001010, B10010001, B10010001, B10010001, B10010001, B01100010};
byte o21[] = {B01000100, B10001010, B10010001, B10010001, B10010001, B10010001, B01100010, B00000000};
byte o22[] = {B10001010, B10010001, B10010001, B10010001, B10010001, B01100010, B00000000, B00110000};
byte o23[] = {B10010001, B10010001, B10010001, B10010001, B01100010, B00000000, B00110000, B01001000};
byte o24[] = {B10010001, B10010001, B10010001, B01100010, B00000000, B00110000, B01001000, B10000100};
byte o25[] = {B10010001, B10010001, B01100010, B00000000, B00110000, B01001000, B10000100, B10000100};
byte o26[] = {B10010001, B01100010, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100};
byte o27[] = {B01100010, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100};
byte o28[] = {B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000};
byte o29[] = {B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000};
byte o30[] = {B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B11111100};
byte o31[] = {B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B11111100, B00001000};
byte o32[] = {B10000100, B01000100, B00111100, B01000000, B00000000, B11111100, B00001000, B00000100};
byte o33[] = {B01000100, B00111100, B01000000, B00000000, B11111100, B00001000, B00000100, B00000100};
byte o34[] = {B00111100, B01000000, B00000000, B11111100, B00001000, B00000100, B00000100, B00000100};
byte o35[] = {B01000000, B00000000, B11111100, B00001000, B00000100, B00000100, B00000100, B00000000};
byte o36[] = {B00000000, B11111100, B00001000, B00000100, B00000100, B00000100, B00000000, B00110000};
byte o37[] = {B11111100, B00001000, B00000100, B00000100, B00000100, B00000000, B00110000, B01001000};
byte o38[] = {B00001000, B00000100, B00000100, B00000100, B00000000, B00110000, B01001000, B10000100};
byte o39[] = {B00000100, B00000100, B00000100, B00000000, B00110000, B01001000, B10000100, B10000100};
byte o40[] = {B00000100, B00000100, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100};
byte o41[] = {B00000100, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100};
byte o42[] = {B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000};
byte o43[] = {B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000};
byte o44[] = {B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B00000000};
byte o45[] = {B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B00000000, B00000000};
byte o46[] = {B10000100, B01000100, B00111100, B01000000, B00000000, B00000000, B00000000, B00000000};

byte h1[8] = {B00001100, B00011110, B00111110, B01111100, B01111100, B00111110, B00011110, B00001100};
byte h2[8] = {B11110011, B11100001, B11000001, B10000011, B10000011, B11000001, B11100001, B11110011};

byte t0a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00100100, B00100100,};
byte t0b[] = { B00100100, B00100100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte t1a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00100100, B00110100, B01110100,};
byte t1b[] = { B01110100, B00110100, B00100100, B00100100, B00100100, B00011000, B00011000, B00011000,};
byte t2a[] = { B00011000, B00011000, B00011000, B00100100, B00100100, B00110100, B01110100, B11110100,};
byte t2b[] = { B11110100, B01110100, B00110100, B00100100, B00100100, B00011000, B00011000, B00011000,};
LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() {
  lc.shutdown(0, false); // Wake up displays
  lc.shutdown(1, false);
  lc.setIntensity(0, 5); // Set intensity levels
  lc.setIntensity(1, 5);
  lc.clearDisplay(0); // Clear Displays
  lc.clearDisplay(1);
  pinMode(button, INPUT);
  pinMode(2, OUTPUT);
}
void sound() {
  while (val0 != 1) {
    j = 3;
    sig = analogRead(MIC) / 15;
    Serial.println(" b ");
    Serial.print(sig);
    //if ((sig == 4))
    if ((sig >= 4) && (sig <= 5))
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader1a[i]);
        lc.setRow(0, i, invader1b[i]);
      }
      delay(1);
    }
    else if ((sig > 5 && sig <= 11) || (sig < 10))
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader2a[i]);
        lc.setRow(0, i, invader2b[i]);
      }
      delay(250);
      for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader3a[i]);
        lc.setRow(0, i, invader3b[i]);
      }
      delay(250);
      for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader2a[i]);
        lc.setRow(0, i, invader2b[i]);
      }
      delay(250);
    }
    else if (sig > 11 && sig < 13)
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader3a[i]);
        lc.setRow(0, i, invader3b[i]);
      }
      delay(350);
    }
    else if (sig >= 13)
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader4a[i]);
        lc.setRow(0, i, invader4b[i]);
      }
      delay(200);
      for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader2a[i]);
        lc.setRow(0, i, invader2b[i]);
      }
      delay(150);
      for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader3a[i]);
        lc.setRow(0, i, invader3b[i]);
      }
      delay(150);
      for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, invader4a[i]);
        lc.setRow(0, i, invader4b[i]);
      }
      delay(200);
    }
    ////////////////////////////////////////
    
    val2 = digitalRead(button);
    //if (val2 == 1) {
    while((val2 == HIGH)&&(button_delay<=80)){
      button_delay++;
      delay(100);
      val2 = digitalRead(button);
      if(val2==LOW){
        break;}
      }
      //status_button = digitalRead(button);
      if(button_delay >= 10){
       j = 2;
       button_delay=0;
       return;
    }
      
      if((button_delay > 0)&&(button_delay < 10)){
         j = 3;
         button_delay=0;
       return;
      }}
   /*  val2 = digitalRead(button);
    if (val2 == 1) {
    // if (digitalRead(button) == HIGH) {

    if (buttonActive == false) {

      buttonActive = true;
      buttonTimer = millis();

    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {

      longPressActive = true;
       j = 2;
      return;

    }

    }else {

    if (buttonActive == true) {

      if (longPressActive == true) {

        longPressActive = false;

      } else {

         j = 1;
     // return;

      }

      buttonActive = false;

    }
   }
  

/*
    val2 = digitalRead(button);
    if (val2 == 1) {
      j = 2;
      return;
     }*/
    }
  


void name() {/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //it was val2!=1
  while (val2 != 0) {
    j = 3;
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o0[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
/*    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }*/
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o1[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    /*val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }*/
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o2[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    /*val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }*/
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o3[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o4[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o5[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o6[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o7[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o8[i]);
        lc.setRow(1, i, o0[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o9[i]);
        lc.setRow(1, i, o1[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o10[i]);
        lc.setRow(1, i, o2[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o11[i]);
        lc.setRow(1, i, o3[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o12[i]);
        lc.setRow(1, i, o4[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o13[i]);
        lc.setRow(1, i, o5[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o14[i]);
        lc.setRow(1, i, o6[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o15[i]);
        lc.setRow(1, i, o7[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o16[i]);
        lc.setRow(1, i, o8[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o17[i]);
        lc.setRow(1, i, o9[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o18[i]);
        lc.setRow(1, i, o10[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o19[i]);
        lc.setRow(1, i, o11[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o20[i]);
        lc.setRow(1, i, o12[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o21[i]);
        lc.setRow(1, i, o13[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o22[i]);
        lc.setRow(1, i, o14[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o23[i]);
        lc.setRow(1, i, o15[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o24[i]);
        lc.setRow(1, i, o16[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o25[i]);
        lc.setRow(1, i, o17[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o26[i]);
        lc.setRow(1, i, o18[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o27[i]);
        lc.setRow(1, i, o19[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o28[i]);
        lc.setRow(1, i, o20[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o29[i]);
        lc.setRow(1, i, o21[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o30[i]);
        lc.setRow(1, i, o22[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o31[i]);
        lc.setRow(1, i, o23[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o32[i]);
        lc.setRow(1, i, o24[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o33[i]);
        lc.setRow(1, i, o25[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o34[i]);
        lc.setRow(1, i, o26[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o35[i]);
        lc.setRow(1, i, o27[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o36[i]);
        lc.setRow(1, i, o28[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o37[i]);
        lc.setRow(1, i, o29[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o38[i]);
        lc.setRow(1, i, o30[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o39[i]);
        lc.setRow(1, i, o31[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o40[i]);
        lc.setRow(1, i, o32[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o41[i]);
        lc.setRow(1, i, o33[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o42[i]);
        lc.setRow(1, i, o34[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o43[i]);
        lc.setRow(1, i, o35[i]);
      }
    }
     delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o44[i]);
        lc.setRow(1, i, o36[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o45[i]);
        lc.setRow(1, i, o37[i]);
      }
    }
    delay(400);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, o46[i]);
        lc.setRow(1, i, o38[i]);
      }
    }
    delay(1000);
    val3 = digitalRead(button);
    if (val3 == 1) {
      j = 3;
      return;
    }
    //////////////////////////////////////////////////////////////
    /*
      val3 = digitalRead(button);
    if (val3 == 1) {
           
   // if (digitalRead(button) == HIGH) {

    if (buttonActive == false) {

      buttonActive = true;
      buttonTimer = millis();

    }

    if ((millis() - buttonTimer > shortPressTime) && (shortPressActive == false)) {

      shortPressActive = true;
      LED1State = !LED1State;
       j = 1;
      return;

    }

  } else {

    if (buttonActive == true) {

      if (shortPressActive == true) {

        shortPressActive = false;

      } else {

         j = 2;
     // return;

      }

      buttonActive = false;

    }

  }*/
   
    }
  }

void heart() {////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  while (val != 1) {
    j = 4;
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, h1[i]);
        lc.setRow(1, i, h1[i]);
      }
    }
    val = digitalRead(button);
    if (val == 1) {
      return;
    }
    delay(400);
  { for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, h2[i]);
        lc.setRow(1, i, h2[i]);
      }
    }
    val = digitalRead(button);
    if (val == 1) {
      return;
    }
    delay(400);
    val = digitalRead(button);
    if (val == 1) {
      return;
    }
  }
}
void tongue() {///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  while (val != 0) {
    j = 1;
  { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, t0a[i]);
        lc.setRow(0, i, t0b[i]);
      }
    }
    val1 = digitalRead(button);
    if (val1 == 1) {
      j = 1;
      return;
    }
    delay(800);
  { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, t1a[i]);
        lc.setRow(0, i, t1b[i]);
      }
    }
    val1 = digitalRead(button);
    if (val1 == 1) {
      j = 1;
      return;
    }
    delay(150);
  { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, t2a[i]);
        lc.setRow(0, i, t2b[i]);
      }
    }
    val1 = digitalRead(button);
    if (val1 == 1) {
      j = 1;
      return;
    }
    delay(800);
    val1 = digitalRead(button);
    if (val1 == 1) {
      j = 1;
      return;
    }
  }
}
void loop() {//////////-----------------------------------------------------------------------------------------------------------
  digitalWrite(2, HIGH);
  if ((j != 1) && (j != 2) && (j != 3) && (j != 4)) {
    sound();
    //name();
  }
  /*val=0;
  val0=0;
  val1=0;
  val2=0;
  val3=0;*/
  
  if (j == 1) {
    delay(500);
    //name();
    //sinvader1a();
    sound();
    //val=0;
    val1=0;
    //val2=0;
    //val3=0;
  }
  if (j == 2) {
    delay(500);
    name();
    //val=0;
    val1=0;
    val2=0;
    //val3=0;
  }
  if (j == 3) {
    delay(500);
    heart();
    //val=0;
    //val1=0;
    val2=0;
    val3=0;
  }
  if (j == 4) {
    delay(500);
    tongue();
    val=0;
    //val1=0;
    //val2=0;
    val3=0;
  }
}
