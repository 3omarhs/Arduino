/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>

#include <RemoteXY.h>
#include <Ultrasonic.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "OPPO Reno Z"
#define REMOTEXY_WIFI_PASSWORD "nnnnnnnnnn1"
#define REMOTEXY_CLOUD_SERVER ""
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN ""

Ultrasonic ultrasonic(12, 14); //(tigger, echo)  >> echo>D5
int distance;

  int relay_ground_humidity = 5;
  int relay_LDR = 13;
  int relay_pump = 4;
  int buzzer = 2;
  int Sensor_read = A0;
  int Red_led = 15;
  int Green_led = 16;

  String ults = "";

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 105 bytes

  { 255,1,0,18,0,98,0,16,16,1,10,48,24,18,15,15,4,26,31,79,
  78,0,31,79,70,70,0,67,5,32,43,22,6,2,26,6,67,5,32,54,
  22,6,2,26,6,67,5,32,64,22,6,2,26,6,129,0,6,44,21,4,
  178,87,97,116,101,114,32,76,101,118,101,0,129,0,6,55,21,4,0,72,
  117,109,105,100,105,116,121,0,129,0,6,65,17,4,80,83,117,110,32,76,
  105,103,104,116,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Turn_On_Pump; // =1 if state is ON, else =0 
  

    // output variables
  char Ultrasonic_val[6];  // string UTF8 end zero 
  char Humidity_val[6];  // string UTF8 end zero 
  char LDR_val[6];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  
  pinMode(relay_ground_humidity, OUTPUT);
  pinMode(relay_LDR, OUTPUT);
  pinMode(relay_pump, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Sensor_read, INPUT);
  pinMode(Red_led, OUTPUT);
  pinMode(Green_led, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();

  distance = ultrasonic.read();
  
//  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==1)?LOW:HIGH);
  if(RemoteXY.Turn_On_Pump == 1){
    digitalWrite(relay_pump, HIGH);
  }
  
  ults = distance + "";
  ults += "CM";
  char ultraStr[6] = "hjhbj";
  RemoteXY.Ultrasonic_val = ultraStr;
  if(Ultrasonic_val >= 30){
    digitalWrite(Red_led, HIGH);
  }
  else{
    digitalWrite(Green_led, LOW);
  }
  
  for(int i=0; i<=1; i++){
    if(i == 0){
      digitalWrite(relay_LDR, LOW);
      digitalWrite(relay_ground_humidity, HIGH);
      LDR_val = analogRead(Sensor_read);
    }
    else if(i == 1){
      digitalWrite(relay_LDR, HIGH);
      digitalWrite(relay_ground_humidity, LOW);
      LDR_val = analogRead(Sensor_read);
    }
  }
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
