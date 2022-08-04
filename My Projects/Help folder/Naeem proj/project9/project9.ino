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
//#define REMOTEXY_WIFI_SSID "OPPO Reno Z"
//#define REMOTEXY_WIFI_PASSWORD "nnnnnnnnnn1"

#define REMOTEXY_WIFI_SSID "Airbox_8F80"
#define REMOTEXY_WIFI_PASSWORD "7LY4HBL72L9"

#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "0b3827ed006a68d9750dbd3ae8dc3877"

#include <Ultrasonic.h>
Ultrasonic ultrasonic(D7, D6); //(tigger, echo)  >> echo>D5
int distance;


#include "DHTesp.h"
#define DHTpin 14 //D5
DHTesp dht;

int relay_pump = D2;
int buzzer = D4;
int Sensor_read = A0;
int Red_led = D8;

const int sensorPin = D4;  //D4  soil humidity
int sensorState = 0;

int val, myvar;
String ultraStr = "";
unsigned long myTime;


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 216 bytes
  { 255,10,0,0,0,209,0,16,16,1,129,0,6,30,21,4,178,87,97,116,
  101,114,32,76,101,118,101,0,129,0,6,41,21,4,0,83,111,105,108,32,
  72,117,109,105,100,105,116,121,0,129,0,6,52,17,4,80,83,117,110,32,
  76,105,103,104,116,0,129,0,6,63,23,4,35,84,101,109,112,101,114,97,
  116,117,114,101,0,7,53,33,52,20,5,2,26,2,7,53,33,41,20,5,
  2,26,2,7,53,33,30,20,5,2,26,2,7,53,33,63,20,5,2,26,
  2,129,0,6,73,23,4,254,72,117,109,105,100,105,116,121,0,7,53,33,
  73,20,5,2,26,2,129,0,54,30,5,6,17,37,0,129,0,54,63,6,
  5,17,194,176,67,0,129,0,54,52,5,6,17,37,0,129,0,54,73,5,
  6,17,37,0,129,0,33,46,19,3,36,49,32,110,101,101,100,32,119,97,
  116,101,114,0,129,0,54,40,6,6,17,240,159,140,167,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
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
  RemoteXY_Init ();
  Serial.begin(115200);
  pinMode(relay_pump, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Sensor_read, INPUT);
  pinMode(Red_led, OUTPUT);
  pinMode(sensorPin, INPUT);
  dht.setup(DHTpin, DHTesp::DHT11);
  // TODO you setup code
  myTime = millis();
}

void loop() {
  RemoteXY_Handler ();
//  turn_on_pump_from_app();
  //  if (millis() - myTime == 1000) {
  weather_temp();
  weather_humidity();
  LDR_sensor();
  ultrasonic_read();
  ldr_sensor();
  soid_humidity();
  delay(300);
  //    myTime = millis();
  //  }
}

void soid_humidity() {
  sensorState = digitalRead(sensorPin);
  Serial.print("Humidity soil: ");
  Serial.println(sensorState);
  if (sensorState == 1){
    RemoteXY.Humidity_val = 1;
    digitalWrite(relay_pump, LOW);
    digitalWrite(buzzer, LOW);
  }
  else
    RemoteXY.Humidity_val = 0;
    digitalWrite(relay_pump, HIGH);
    digitalWrite(buzzer, HIGH);
  delay(200);
}

void LDR_sensor() {
  val = analogRead(Sensor_read) / 10;
  delay(200);
  RemoteXY.LDR_val = val;
  Serial.print("LDR: ");
  Serial.println(val);
  delay(200);
}

/*void turn_on_pump_from_app() {
  digitalWrite(relay_pump, (RemoteXY.Turn_On_Pump == 0) ? LOW : HIGH);
  digitalWrite(buzzer, (RemoteXY.Turn_On_Pump == 0) ? LOW : HIGH);
  delay(200);
  if (RemoteXY.Turn_On_Pump == 1) {
    Serial.println("pump on");
  }
  else {
    Serial.println("pump off");
  }
  delay(200);
}*/

void weather_temp() {
  myvar = dht.getTemperature();
  delay(100);
  RemoteXY.temp_val = myvar;
  Serial.print("weather Temp: ");
  Serial.println(myvar);
  delay(200);
}

void weather_humidity() {
  myvar = dht.getHumidity();
  delay(100);
  RemoteXY.hum_val = myvar;
  Serial.print("weather humidity: ");
  Serial.println(myvar);
  delay(200);
}

void ldr_sensor() {
  val = analogRead(Sensor_read) / 10;
  delay(100);
  RemoteXY.LDR_val = val;
  Serial.print("LDR: ");
  Serial.println(val);
  delay(200);
}

void ultrasonic_read() {
  int empty = 20;
  int num = 100 / empty;
  distance = ultrasonic.read() / num;
  int percentage = 100 - (((ultrasonic.read()) * 100) / empty);
  if(percentage < 0)
    percentage = 0;
  delay(200);
  RemoteXY.Ultrasonic_val = percentage;
  Serial.print("ultrasonic: ");
  Serial.println(percentage);
  if (percentage <= 30) {
    digitalWrite(Red_led, HIGH);
  }
  else
    digitalWrite(Red_led, LOW);
  delay(200);
}
