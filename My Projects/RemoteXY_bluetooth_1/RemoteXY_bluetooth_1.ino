/*
   -- bluetooth control LED --
   
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
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600



// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,1,0,27,0,11,191,1,
  2,1,14,53,37,16,2,26,31,31,
  226,152,176,0,226,152,176,0,65,4,
  20,21,23,23 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variables
  uint8_t led_1_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 12
const int button = 4;
bool btOn = false;

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode(button, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  if(RemoteXY.switch_1 == 0)
    RemoteXY.led_1_r = 0;
  if(RemoteXY.switch_1 == 1)
    RemoteXY.led_1_r = 255;

  if(digitalRead(button) == HIGH){
    if(btOn == false){
      RemoteXY.switch_1 = 0;
      btOn = true;
    }
    else if(btOn == true){
      RemoteXY.switch_1 = 1;
      btOn = false;
    }
    delay(300);
  }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
