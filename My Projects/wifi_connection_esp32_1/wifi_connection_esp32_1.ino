/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.7.12 or later version;
     - for iOS 1.4.7 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_WIFI_POINT
#include <WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "3omar.hs AI-Cam My Project"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,4,0,119,0,11,28,1,
  2,1,17,24,22,11,95,8,31,31,
  61,0,61,0,65,44,45,25,9,9,
  129,0,5,25,3,6,17,49,0,129,
  0,5,42,3,6,17,50,0,2,1,
  17,40,22,11,107,24,31,31,61,0,
  61,0,65,42,45,41,9,9,2,1,
  17,56,22,11,135,32,31,31,61,0,
  61,0,65,41,45,57,9,9,129,0,
  5,58,3,6,17,51,0,65,44,45,
  73,9,9,2,1,17,72,22,11,149,
  74,31,31,61,0,61,0,129,0,5,
  74,3,6,17,52,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 

    // output variables
  uint8_t led_1_r; // =0..255 LED Red brightness 
  uint8_t led_2_g; // =0..255 LED Green brightness 
  uint8_t led_3_b; // =0..255 LED Blue brightness 
  uint8_t led_4_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 4
#define PIN_SWITCH_2 2
#define PIN_SWITCH_3 14
#define PIN_SWITCH_4 15


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_SWITCH_4, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==0)?LOW:HIGH);
  
  

  if(RemoteXY.switch_1 == 0){
    RemoteXY.led_1_r = 0;
  }
  else if(RemoteXY.switch_1 == 1){
    RemoteXY.led_1_r = 255;
  }

  if(RemoteXY.switch_2 == 0){
    RemoteXY.led_2_g = 0;
  }
  else if(RemoteXY.switch_2 == 1){
    RemoteXY.led_2_g = 255;
  }

  if(RemoteXY.switch_3 == 0){
    RemoteXY.led_3_b = 0;
  }
  else if(RemoteXY.switch_3 == 1){
    RemoteXY.led_3_b = 255;
  }
  
  if(RemoteXY.switch_4 == 0){
    RemoteXY.led_4_r = 0;
  }
  else if(RemoteXY.switch_4 == 1){
    RemoteXY.led_4_r = 255;
  }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
