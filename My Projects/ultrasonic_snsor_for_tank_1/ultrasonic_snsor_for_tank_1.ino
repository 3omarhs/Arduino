#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;
LedControl lc=LedControl(DIN,CLK,CS,0);
byte zero[] = { B00111110, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00111110};
                
byte one[] = {  B00001110, 
                B00000100, 
                B00000100, 
                B00000100, 
                B00000100, 
                B00000100, 
                B00001100, 
                B00000100}; 
                
byte two[] = {  B00111110, 
                B00100000, 
                B00010000, 
                B00001000, 
                B00000100, 
                B00000010, 
                B00100010, 
                B00011100};
                
byte three[] = {B00111110, 
                B00000010, 
                B00000100, 
                B00001000, 
                B00000110, 
                B00000010, 
                B00000010, 
                B00111100};
                
byte four[] = { B00000100, 
                B00000100, 
                B00000100, 
                B00111110, 
                B00100100, 
                B00100100, 
                B00100100, 
                B00100000};
                
byte five[] = { B00111110, 
                B00000010, 
                B00000010, 
                B00000010, 
                B00111110, 
                B00100000, 
                B00100000, 
                B00111110};
                
byte six[]  = { B00111110, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00111110, 
                B00100000, 
                B00100000, 
                B00111110};
                
byte seven[] = {B00010000, 
                B00010000, 
                B00010000, 
                B00010000, 
                B00001000, 
                B00000100, 
                B00000010, 
                B00111110};
                
byte eight[] = {B00111110, 
                B00100010, 
                B00100010, 
                B00100010, 
                B00011100, 
                B00100010, 
                B00100010, 
                B00111110};
                
byte nine[] = { B00111110, 
                B00000010, 
                B00000010, 
                B00000010, 
                B00111110, 
                B00100010, 
                B00100010, 
                B00111110};

byte zero1[] = { B01111100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B01111100};
                
byte one1[] = {  B00011100, 
                B00001000, 
                B00001000, 
                B00001000, 
                B00001000, 
                B00001000, 
                B00011000, 
                B00001000}; 
                
byte two1[] = {  B01111100, 
                B01000000, 
                B00100000, 
                B00010000, 
                B00001000, 
                B00000100, 
                B01000100, 
                B00111000};
                
byte three1[] = {B01111100, 
                B00000100, 
                B00001000, 
                B00010000, 
                B00001100, 
                B00000100, 
                B00000100, 
                B01111000};
                
byte four1[] = { B00001000, 
                B00001000, 
                B00001000, 
                B01111100, 
                B01001000, 
                B01001000, 
                B01001000, 
                B01000000};
                
byte five1[] = { B01111100, 
                B00000100, 
                B00000100, 
                B00000100, 
                B01111100, 
                B01000000, 
                B01000000, 
                B01111100};
                
byte six1[]  = { B01111100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B01111100, 
                B01000000, 
                B01000000, 
                B01111100};
                
byte seven1[] = {B00100000, 
                B00100000, 
                B00100000, 
                B00100000, 
                B00010000, 
                B00001000, 
                B00000100, 
                B01111100};
                
byte eight1[] = {B01111100, 
                B01000100, 
                B01000100, 
                B01000100, 
                B00111000, 
                B01000100, 
                B01000100, 
                B01111100};
                
byte nine1[] = { B01111100, 
                B00000100, 
                B00000100, 
                B00000100, 
                B01111100, 
                B01000100, 
                B01000100, 
                B01111100};
                
byte percent[] = {B11101001,
                  B00101100, 
                  B00101100, 
                  B00100110, 
                  B00100110, 
                  B00100011, 
                  B00100011,  
                  B11101001};

byte full1[] = {B01000111, 
                B01000101,
                B01000101,
                B01000101,
                B11100101,
                B01000101,
                B01010000,
                B01110000};

byte full2[] = {B01010000,
                B01010101,
                B01010000,
                B01010000,
                B01010000,
                B01010000,
                B01010000,
                B01010000};

//mar>>>3.mar
byte mar[] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte mar1[] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01000100};
byte mar2[] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01000100, B11000110};
byte mar3[] = { B00000000, B00000000, B00000000, B00000000, B00000000, B01000100, B11000110, B10010010};
byte mar4[] = { B00000000, B00000000, B00000000, B00000000, B01000100, B11000110, B10010010, B10010010};
byte mar5[] = { B00000000, B00000000, B00000000, B01000100, B11000110, B10010010, B10010010, B11111110};
byte mar6[] = { B00000000, B00000000, B01000100, B11000110, B10010010, B10010010, B11111110, B01101100};
byte mar7[] = { B00000000, B01000100, B11000110, B10010010, B10010010, B11111110, B01101100, B00000000};
byte mar8[] = { B01000100, B11000110, B10010010, B10010010, B11111110, B01101100, B00000000, B01100000};
byte mar9[] = { B11000110, B10010010, B10010010, B11111110, B01101100, B00000000, B01100000, B01100000};
byte mar10[] = { B10010010, B10010010, B11111110, B01101100, B00000000, B01100000, B01100000, B00000000};
byte mar11[] = { B10010010, B11111110, B01101100, B00000000, B01100000, B01100000, B00000000, B11111000};
byte mar12[] = { B11111110, B01101100, B00000000, B01100000, B01100000, B00000000, B11111000, B00001000};
byte mar13[] = { B01101100, B00000000, B01100000, B01100000, B00000000, B11111000, B00001000, B01111000};
byte mar14[] = { B00000000, B01100000, B01100000, B00000000, B11111000, B00001000, B01111000, B00001000};
byte mar15[] = { B01100000, B01100000, B00000000, B11111000, B00001000, B01111000, B00001000, B11111000};
byte mar16[] = { B01100000, B00000000, B11111000, B00001000, B01111000, B00001000, B11111000, B00000000};
byte mar17[] = { B00000000, B11111000, B00001000, B01111000, B00001000, B11111000, B00000000, B00110000};
byte mar18[] = { B11111000, B00001000, B01111000, B00001000, B11111000, B00000000, B00110000, B01001000};
byte mar19[] = { B00001000, B01111000, B00001000, B11111000, B00000000, B00110000, B01001000, B10000100};
byte mar20[] = { B01111000, B00001000, B11111000, B00000000, B00110000, B01001000, B10000100, B10000100};
byte mar21[] = { B00001000, B11111000, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100};
byte mar22[] = { B11111000, B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100};
byte mar23[] = { B00000000, B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000};
byte mar24[] = { B00110000, B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000};
byte mar25[] = { B01001000, B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B11111100};
byte mar26[] = { B10000100, B10000100, B01000100, B00111100, B01000000, B00000000, B11111100, B00001000};
byte mar27[] = { B10000100, B01000100, B00111100, B01000000, B00000000, B11111100, B00001000, B00000100};
byte mar28[] = { B01000100, B00111100, B01000000, B00000000, B11111100, B00001000, B00000100, B00000100};
byte mar29[] = { B00111100, B01000000, B00000000, B11111100, B00001000, B00000100, B00000100, B00000100};
byte mar30[] = { B01000000, B00000000, B11111100, B00001000, B00000100, B00000100, B00000100, B00000000};
byte mar31[] = { B00000000, B11111100, B00001000, B00000100, B00000100, B00000100, B00000000, B00000000};
byte mar32[] = { B11111100, B00001000, B00000100, B00000100, B00000100, B00000000, B00000000, B00000000};


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int distance0, distance1;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
  Serial.println("3omar.hs Ultrasonic Sensor HC-SR04 Test");
  lc.shutdown(0,false); // Wake up displays 
    lc.shutdown(1,false); 
    lc.setIntensity(0,5); // Set intensity levels 
    lc.setIntensity(1,5); 
    lc.clearDisplay(0); // Clear Displays 
    lc.clearDisplay(1);
    marn();
  /*for (int i = 0; i < 8; i++) { 
        lc.setColumn(0,i,zero[i]);
        lc.setColumn(1,i,percent[i]);
        }*/
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2)/10; // Speed of sound wave divided by 2 (go and back)Monitor
  distance0 = (duration * 0.034 / 2);
  distance1 = (distance0 + 10) % 10;
  Serial.println(distance0);
  
    
    if(10 - distance1 == 9){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,nine1[i]);
      }
    }
    if(10 - distance1 == 8){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,eight1[i]);
      }
    }
    if(10 - distance1 == 7){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,seven1[i]);
      }
    }
    if(10 - distance1 == 6){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,six1[i]);
      }
    }
    if(10 - distance1 == 5){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,five1[i]);
      }
    }
    if(10 - distance1 == 4){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,four1[i]);
      }
    }
    if(10 - distance1 == 3){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,three1[i]);
      }
    }
    if(10 - distance1 == 2){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,two1[i]);
      }
    }
    if(10 - distance1 == 1){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,one1[i]);
      }
    }
    if(10 - distance1 == 0){
      for (int i = 0; i < 8; i++) { 
        lc.setColumn(1,i,zero1[i]);
      }
    }

    
    if(10 - distance == 10){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,full1[i]);
      lc.setColumn(1,i,full2[i]);
        }
      }
    /*if(10 - (duration * 0.034 / 2) >= 95){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,full1[i]);
      lc.setColumn(1,i,full2[i]);
        }
      }*/
      if(10 - distance == 9){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,nine[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 8){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,eight[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 7){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,seven[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 6){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,six[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 5){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,five[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 4){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,four[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 3){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,three[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 2){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,two[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(10 - distance == 1){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,one[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
    if(9 - distance == 0){
      for (int i = 0; i < 8; i++) { 
      lc.setColumn(0,i,zero[i]);
      //lc.setColumn(1,i,percent[i]);
        }
      }
      
    //Serial.print(10-distance);
    //Serial.println("0%");
    if(distance < 10)
    delay(500);
  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


void marn(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar1[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar2[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar3[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar4[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar5[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar6[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar7[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar8[i]);
        lc.setRow(0, i, mar[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar9[i]);
        lc.setRow(0, i, mar1[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar10[i]);
        lc.setRow(0, i, mar2[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar11[i]);
        lc.setRow(0, i, mar3[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar12[i]);
        lc.setRow(0, i, mar4[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar13[i]);
        lc.setRow(0, i, mar5[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar14[i]);
        lc.setRow(0, i, mar6[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar15[i]);
        lc.setRow(0, i, mar7[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar16[i]);
        lc.setRow(0, i, mar8[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar17[i]);
        lc.setRow(0, i, mar9[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar18[i]);
        lc.setRow(0, i, mar10[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar19[i]);
        lc.setRow(0, i, mar11[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar20[i]);
        lc.setRow(0, i, mar12[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar21[i]);
        lc.setRow(0, i, mar13[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar22[i]);
        lc.setRow(0, i, mar14[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar23[i]);
        lc.setRow(0, i, mar15[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar24[i]);
        lc.setRow(0, i, mar16[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar25[i]);
        lc.setRow(0, i, mar17[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar26[i]);
        lc.setRow(0, i, mar18[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar27[i]);
        lc.setRow(0, i, mar19[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar28[i]);
        lc.setRow(0, i, mar20[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar29[i]);
        lc.setRow(0, i, mar21[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar30[i]);
        lc.setRow(0, i, mar22[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar31[i]);
        lc.setRow(0, i, mar23[i]);
      }
    }
    delay(100);
    { for (int i = 0; i < 8; i++) {
        lc.setRow(1, i, mar32[i]);
        lc.setRow(0, i, mar24[i]);
      }
    }
    delay(1000);
    }
