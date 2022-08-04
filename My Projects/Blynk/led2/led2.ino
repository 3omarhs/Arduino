// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings


#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_DEVICE_NAME "YOUR DEVICE NAME"
#define BLYNK_AUTH_TOKEN "YOUR AUTH TOKEN"


// Comment this out to disable prints and save space
#define BLYNK_PRINT SerialUSB
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>

int led = D5;


char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Airbox_8f80";
char pass[] = "7LY4HBL72L9";
BlynkTimer timer;
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0){
 int pinValue = param.asInt();
 digitalWrite(led, pinValue);
}
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
 // Change Web Link Button message to "Congratulations!"
 Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
 Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
 Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
// This function sends Arduino's uptime every second to Virtual Pin 2.
void setup()
{
 // Debug console
 SerialUSB.begin(115200);
 Blynk.begin(auth, ssid, pass);
 // You can also specify server:
 //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
 //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
 pinMode(led, OUTPUT);
 // Setup a function to be called every second
}
void loop()
{
 Blynk.run();
 timer.run();
 // You can inject your own code or combine it with other sketches.
 // Check other examples on how to communicate with Blynk. Remember
 // to avoid delay() function!
}
