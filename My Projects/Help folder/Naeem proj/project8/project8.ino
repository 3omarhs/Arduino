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

//#define REMOTEXY_WIFI_SSID "Airbox_8F80"
//#define REMOTEXY_WIFI_PASSWORD "7LY4HBL72L9"

#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "0b3827ed006a68d9750dbd3ae8dc3877"

Ultrasonic ultrasonic(D7, D6); //(tigger, echo)  >> echo>D5
int distance;
#include "DHTesp.h"
#define DHTpin 14 //D5
DHTesp dht;

int relay_pump = D2;
int buzzer = D1;
int Sensor_read = A0;
int Red_led = D8;

const int sensorPin = D4;  //D4  soil humidity
int sensorState = 0;

int val = 0;
int myvar;
int ultraStr;
unsigned long myTime;



// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 233 bytes
  { 255,11,0,0,0,226,0,16,16,1,10,58,24,12,15,15,4,26,31,79,
  78,0,31,79,70,70,0,129,0,6,44,21,4,178,87,97,116,101,114,32,
  76,101,118,101,0,129,0,6,55,21,4,0,83,111,105,108,32,72,117,109,
  105,100,105,116,121,0,129,0,6,66,17,4,80,83,117,110,32,76,105,103,
  104,116,0,129,0,6,77,23,4,35,84,101,109,112,101,114,97,116,117,114,
  101,0,7,53,33,66,20,5,2,26,2,7,53,33,55,20,5,2,26,2,
  7,53,33,44,20,5,2,26,2,7,53,33,77,20,5,2,26,2,129,0,
  6,87,23,4,254,72,117,109,105,100,105,116,121,0,7,53,33,87,20,5,
  2,26,2,129,0,54,44,5,6,17,37,0,129,0,54,77,6,5,17,194,
  176,67,0,129,0,54,66,5,6,17,37,0,129,0,54,87,5,6,17,37,
  0,129,0,33,60,19,3,36,49,32,110,101,101,100,32,119,97,116,101,114,
  0,129,0,54,54,6,6,17,240,159,140,167,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Turn_On_Pump; // =1 if state is ON, else =0 
  int16_t LDR_val;  // 32767.. +32767 
  int16_t Humidity_val;  // 32767.. +32767 
  int16_t Ultrasonic_val;  // 32767.. +32767 
  int16_t temp_val;  // 32767.. +32767 
  int16_t hum_val;  // 32767.. +32767 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup()
{
  Serial.begin(115200);
  Serial.println("Connecting...");
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
  RemoteXY_Init ();
  pinMode(buzzer, OUTPUT);
  pinMode(Sensor_read, INPUT);
  pinMode(Red_led, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.println("Connected");
}

void loop()
{
  Serial.println("one turn");
  myTime = millis();
  RemoteXY_Handler ();
  
  turn_on_pump_from_app();

  ultrasonic_read();

  LDR_sensor();
  
  weather_temp();
  
  weather_humidity();

  soid_humidity();
  
  Serial.println("***********************");
  delay(1000);

}

void soid_humidity(){
  sensorState = digitalRead(sensorPin);
  Serial.print("Humidity soil: ");
  Serial.println(sensorState);
  if (sensorState == 1) {
    RemoteXY.Humidity_val = 1;
    delay(100);
  }
  else {
    RemoteXY.Humidity_val = 0;
    delay(100);
  }
}

void LDR_sensor(){
  val = analogRead(Sensor_read)/10;
  RemoteXY.LDR_val = val;
  Serial.print("LDR: ");
  Serial.println(val);
}

void ultrasonic_read(){
  int empty = 20;
  int num = 100/empty;
  distance = ultrasonic.read()/num;
  RemoteXY.Ultrasonic_val = distance;
  Serial.print("ultrasonic: ");
  Serial.println(distance*num);
  if (distance >= 80) {
    digitalWrite(Red_led, HIGH);
  }
  else
    digitalWrite(Red_led, LOW);
}

void turn_on_pump_from_app(){
  digitalWrite(relay_pump, (RemoteXY.Turn_On_Pump==0)?LOW:HIGH);
  digitalWrite(buzzer, (RemoteXY.Turn_On_Pump==0)?LOW:HIGH);
  if (RemoteXY.Turn_On_Pump == 1) {
    Serial.println("pump on");
  }
  else {
    Serial.println("pump off");
  }
}

void weather_temp() {
  myvar = dht.getTemperature();
  RemoteXY.temp_val = myvar;
  Serial.print("weather Temp: ");
  Serial.println(myvar);
}

void weather_humidity() {
  myvar = dht.getHumidity();
  RemoteXY.hum_val = myvar;
  Serial.print("weather humidity: ");
  Serial.println(myvar);
}
