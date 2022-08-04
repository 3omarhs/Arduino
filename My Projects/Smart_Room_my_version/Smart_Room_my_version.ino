/*
   -- Smart Room my version --
   
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
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "3omar.hs_Smart Room"
#define REMOTEXY_WIFI_PASSWORD "12345678oa"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,8,0,159,0,11,178,1,
  2,1,27,16,22,11,1,176,31,31,
  226,152,176,0,226,152,176,0,129,0,
  2,18,18,6,111,82,111,111,109,0,
  129,0,2,35,18,6,6,66,108,117,
  101,0,2,1,27,33,22,11,1,176,
  31,31,79,78,0,79,70,70,0,129,
  0,2,55,18,6,46,84,86,0,2,
  1,27,52,22,11,1,176,31,31,79,
  78,0,79,70,70,0,129,0,2,72,
  18,6,3,70,97,110,0,2,1,27,
  70,22,11,1,176,31,31,79,78,0,
  79,70,70,0,65,7,52,17,9,9,
  65,1,52,34,9,9,65,5,52,53,
  9,9,65,3,52,71,9,9,129,0,
  7,3,48,8,200,83,109,97,114,116,
  32,82,111,111,109,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 

    // output variables
  uint8_t led_1_r; // =0..255 LED Red brightness 
  uint8_t led_1_g; // =0..255 LED Green brightness 
  uint8_t led_1_b; // =0..255 LED Blue brightness 
  uint8_t led_2_b; // =0..255 LED Blue brightness 
  uint8_t led_3_r; // =0..255 LED Red brightness 
  uint8_t led_3_b; // =0..255 LED Blue brightness 
  uint8_t led_4_g; // =0..255 LED Green brightness 
  uint8_t led_4_b; // =0..255 LED Blue brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 D0
#define PIN_SWITCH_2 D1
#define PIN_SWITCH_3 D2
#define PIN_SWITCH_4 D3


int button_1 = D5;
int button_2 = D6;
int button_3 = D7;
int button_4 = D8;
bool bp1 = false, bp2 = false, bp3 = false, bp4 = false;


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_SWITCH_4, OUTPUT);

  pinMode (button_1, INPUT);
  pinMode (button_2, INPUT);
  pinMode (button_3, INPUT);
  pinMode (button_4, INPUT);
  
  // TODO you setup code
  Serial.begin(9600);
  Serial.println("=============");
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==1)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==1)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==1)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==1)?LOW:HIGH);

  if(RemoteXY.switch_1 == 1){
    RemoteXY.led_1_r = 255;
    RemoteXY.led_1_g = 255;
    RemoteXY.led_1_b = 255;
  }
  else{
    RemoteXY.led_1_r = 0;
    RemoteXY.led_1_g = 0;
    RemoteXY.led_1_b = 0;
  }
  
  if(RemoteXY.switch_2 == 1){
    RemoteXY.led_2_b = 255;
  }
  else{
    RemoteXY.led_2_b = 0;
  }
  
  if(RemoteXY.switch_3 == 1){
    RemoteXY.led_3_r = 255;
    RemoteXY.led_3_b = 255;
  }
  else{
    RemoteXY.led_3_r = 0;
    RemoteXY.led_3_b = 0;
  }
  
  if(RemoteXY.switch_4 == 1){
    RemoteXY.led_4_g = 255;
    RemoteXY.led_4_b = 255;
  }
  else{
    RemoteXY.led_4_g = 0;
    RemoteXY.led_4_b = 0;
  }


  if(digitalRead(button_1) == HIGH){
    if(bp1 == false){
      RemoteXY.switch_1 = 0;
      bp1 = true;
      Serial.println("button_1");
    }
    else{
      RemoteXY.switch_1 = 1;
      bp1 = false;
    }
    delay(300);
  }

  if(digitalRead(button_2) == HIGH){
    if(bp2 == false){
      RemoteXY.switch_2 = 0;
      bp2 = true;
      Serial.println("button_2");
    }
    else{
      RemoteXY.switch_2 = 1;
      bp2 = false;
    }
    delay(300);
  }

  if(digitalRead(button_3) == HIGH){
    if(bp3 == false){
      RemoteXY.switch_3 = 0;
      bp3 = true;
      Serial.println("button_3");
    }
    else{
      RemoteXY.switch_3 = 1;
      bp3 = false;
    }
    delay(300);
  }

  if(digitalRead(button_4) == HIGH){
    if(bp4 == false){
      RemoteXY.switch_4 = 0;
      bp4 = true;
      Serial.println("button_4");
    }
    else{
      RemoteXY.switch_4 = 1;
      bp4 = false;
    }
    delay(300);
  }
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
