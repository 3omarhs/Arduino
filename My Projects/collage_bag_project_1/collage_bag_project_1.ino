#include <Wire.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#include <Rtc_Pcf8563.h>

Rtc_Pcf8563 rtc;


#include <LM35.h>


//Accelerometer
#define DEVICE (0x53)    //ADXL345 device address
#define TO_READ (6)        //num of bytes we are going to read each time (two bytes for each axis)

#define offsetX   -10.5       // OFFSET values
#define offsetY   -2.5
#define offsetZ   -4.5

#define gainX     257.5        // GAIN factors
#define gainY     254.5
#define gainZ     248.5

int sensorPin = A0;
//LM35 temp(A0);


    // Otherwise leave the default "550" value. 
//Accelerometer Variables
byte buff[TO_READ] ;    //6 bytes buffer for saving data read from the device
char str[512];                      //string buffer to transform data before sending it to the serial port

int x,y,z, stepsStepped;

int xavg, yavg,zavg, steps=0, flag=0;
int xval[15]={0}, yval[15]={0}, zval[15]={0};
int threshhold = 60.0;


int strr;

void setup()   {                
  Serial.begin(9600);
  Wire.begin();
  
  u8g2.begin();

//  lcd.init();
//  lcd.backlight();
//
//  lcd.setCursor(0, 0);
//  lcd.print("3omar.hs");
  
  //Turning on the ADXL345
  writeTo(DEVICE, 0x2D, 0);      
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  Serial.println();
  
  delay(10);
}


void loop() {
  int regAddress = 0x32; //First axis-acceleration-data register on the ADXL345
  readFrom(DEVICE, regAddress, TO_READ, buff); //read the acceleration data from the ADXL345
  
  //each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
  //thus we are converting both bytes in to one int
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_t0_15_tf);
  x = (((int)buff[1]) << 8) | buff[0];   
  y = (((int)buff[3])<< 8) | buff[2];
  z = (((int)buff[5]) << 8) | buff[4];
  
  stepsStepped = ArduinoPedometer();
  
  delay(100);
  /*lcd.setCursor(11, 0);
  lcd.print(rtc.getDay());
  lcd.setCursor(13, 0);
  lcd.print("/");
  lcd.setCursor(14, 0);
  lcd.print(rtc.getMonth());*/
  u8g2.drawStr(0,12,"3omar.hs");
  strr = rtc.getDay();
  //u8g2.drawStr(89,12,strr);
  u8g2.setCursor(89,12);
  u8g2.print(strr);
  u8g2.drawStr(105,12,"/");
  //u8g2.drawStr(113,12,strr);
  u8g2.setCursor(113,12);
  u8g2.print(rtc.getMonth());  
  //u8g2.drawStr(0,30,"stp:");
  u8g2.setCursor(0,30);
  u8g2.print("stp:");

  //lcd.setCursor(11, 1);
  if(rtc.getHour() > 12){
    //lcd.print(rtc.getHour() - 12);
    //u8g2.drawStr(89,30,);
    u8g2.setCursor(89,30);
    u8g2.print(rtc.getHour() - 12);
  }
  else if(rtc.getHour() == 0){
    //lcd.print("12");
    //u8g2.drawStr(89,30,);
    u8g2.setCursor(89,30);
    u8g2.print("12");
  }
  else{
  //lcd.print(rtc.getHour());
   //u8g2.drawStr(89,30,);
    u8g2.setCursor(89,30);
    u8g2.print(rtc.getHour());
  }

  //lcd.setCursor(8, 1);
  switch (rtc.getWeekday()){
    case 1:{
       //u8g2.drawStr(66,30,);
        u8g2.setCursor(66,30);
        u8g2.print("Su");
//      lcd.print("Su");
      break;
    }
    case 2:{
//       u8g2.drawStr(66,30,"Mo");
        u8g2.setCursor(66,30);
        u8g2.print("Mo");
//      lcd.print("Mo");
      break;
    }
    case 3:{
//       u8g2.drawStr(66,30,"Tu");
        u8g2.setCursor(66,30);
        u8g2.print("Tu");
//      lcd.print("Tu");
      break;
    }
    case 4:{
//       u8g2.drawStr(66,30,"We");
        u8g2.setCursor(66,30);
        u8g2.print("We");
//      lcd.print("We");
      break;
    }
    case 5:{
//       u8g2.drawStr(66,30,"Th");
       u8g2.setCursor(66,30);
        u8g2.print("Th");
//      lcd.print("Th");
      break;
    }
    case 6:{
//       u8g2.drawStr(66,30,"Fr");
       u8g2.setCursor(66,30);
        u8g2.print("Fr");
//      lcd.print("Fr");
      break;
    }
    case 0:{
//       u8g2.drawStr(66,30,"Sa");
       u8g2.setCursor(66,30);
        u8g2.print("Sa");
//      lcd.print("Sa");
      break;
    }
    default:{
      u8g2.setCursor(66,30);
      u8g2.print(rtc.getWeekday());
//      lcd.print(rtc.getWeekday());
    }
  }
//  lcd.setCursor(13, 1);
//  lcd.print(":");
//  lcd.setCursor(14, 1);
//  lcd.print(rtc.getMinute());
u8g2.drawStr(105,30,":");
//u8g2.drawStr(113,30,);
u8g2.setCursor(113,30);
        u8g2.print(rtc.getMinute());

  u8g2.setFont(u8g2_font_5x7_tf);
  /*int reading = analogRead(sensorPin);// Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);// Convert the voltage into the temperature in degree Celsius:
//  float temperature = (voltage / 10);// Print the temperature in the Serial Monitor:
  String temp = (String)(temperature);
  temp = temp.substring(0, temp.length() - 1);*/

  float xx = (analogRead(sensorPin)* 0.34);
  String tem = (String)(xx);
  tem = tem.substring(0, 4);
  
  u8g2.setCursor(66,8);
  u8g2.print(tem);
  u8g2.setCursor(85,8);
  u8g2.print("\xB0");
  
  u8g2.setFont(u8g2_font_t0_15_tf);

  u8g2.sendBuffer();
}

//---------------- Functions
//Writes val to address register on device
void writeTo(int device, byte address, byte val) {
   Wire.beginTransmission(device); //start transmission to device 
   Wire.write(address);        // send register address
   Wire.write(val);        // send value to write
   Wire.endTransmission(); //end transmission
}

//reads num bytes starting from address register on device in to buff array
void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);        //sends address to read from
  Wire.endTransmission(); //end transmission
  
  Wire.beginTransmission(device); //start transmission to device
  Wire.requestFrom(device, num);    // request 6 bytes from device
  
  int i = 0;
  while(Wire.available())    //device may send less than requested (abnormal)
  { 
    buff[i] = Wire.read(); // receive a byte
    i++;
  }
  Wire.endTransmission(); //end transmission
}


//Get pedometer.

int ArduinoPedometer(){
    int acc=0;
    int totvect[15]={0};
    int totave[15]={0};
    int xaccl[15]={0};
    int yaccl[15]={0};
    int zaccl[15]={0};
    for (int i=0;i<15;i++)
    {
      xaccl[i]= x;
      delay(1);
      yaccl[i]= y;
      delay(1);
      zaccl[i]= z;
      delay(1);
      totvect[i] = sqrt(((xaccl[i]-xavg)* (xaccl[i]-xavg))+ ((yaccl[i] - yavg)*(yaccl[i] - yavg)) + ((zval[i] - zavg)*(zval[i] - zavg)));
      totave[i] = (totvect[i] + totvect[i-1]) / 2 ;
      delay(150);
  
      //cal steps 
      if (totave[i]>threshhold && flag==0)
      {
         steps=steps+1;
         flag=1;
      }
      else if (totave[i] > threshhold && flag==1)
      {
          //do nothing 
      }
      if (totave[i] <threshhold  && flag==1)
      {
        flag=0;
      }
      Serial.print("steps=");
      Serial.println(steps);
//      lcd.setCursor(0, 1);
//      lcd.print("stp:");
//      lcd.setCursor(4, 1);
//      lcd.print(steps);
//  u8g2.drawStr(0,30,"stp:");
//  u8g2.drawStr(32,30,);
  u8g2.setCursor(32,30);
  u8g2.print(steps);
     return(steps);
    }
  delay(100); 
 }
