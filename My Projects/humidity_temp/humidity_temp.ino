#include "DHTesp.h"
#define DHTpin 13 //D5
DHTesp dht;
void setup() {
  // put your setup code here, to run once:

  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
}

void loop() {
  // put your main code here, to run repeatedly:
int myvar = dht.getTemperature();
  Serial.print("weather Temp: ");
  Serial.println(myvar);

   myvar = dht.getHumidity();
  Serial.print("weather humidity: ");
  Serial.println(myvar);
}
