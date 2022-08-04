
/*Modified by

 * Technical team,REES52

 */

//////////////////////////////////////////////

//        RemoteXY include library          //

//////////////////////////////////////////////


// RemoteXY select connection mode and include library  

#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT

#include <ESP8266WiFi.h>


#include <RemoteXY.h>


// RemoteXY connection settings  

#define REMOTEXY_WIFI_SSID "RemoteXY"

#define REMOTEXY_WIFI_PASSWORD "12345678"

#define REMOTEXY_SERVER_PORT 6377



// RemoteXY configurate  

#pragma pack(push, 1)

uint8_t RemoteXY_CONF[] =

  { 255,1,0,0,0,20,0,8,13,0,

  2,0,22,17,51,24,2,26,31,31,

  79,78,0,79,70,70,0 };

   

// this structure defines all the variables of your control interface  

struct {


    // input variable

  uint8_t switch_1; // =1 if switch ON and =0 if OFF


    // other variable

  uint8_t connect_flag;  // =1 if wire connected, else =0


} RemoteXY;

#pragma pack(pop)


/////////////////////////////////////////////

//           END RemoteXY include          //

/////////////////////////////////////////////


#define PIN_SWITCH_1 D5



void setup()  

{

  RemoteXY_Init ();  

   

  pinMode (PIN_SWITCH_1, OUTPUT);

   

  // TODO you setup code

   

}


void loop()  

{  

  RemoteXY_Handler ();

   

  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);

   

  // TODO you loop code

  // use the RemoteXY structure for data transfer



}
