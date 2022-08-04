/* Yu Hin Hau
 * Easy Transfer Tutorial (Transfer)
 * 8/4/2012
 */
 
#include <EasyTransfer.h>
 
EasyTransfer ET;
 
//Declare Data Structure for the EasyTransfer Library
//Note: Data Structure must be same on TX and RX...
 
struct DATA_STRUCTURE{
 int int_data;
 char char_data;
};
 
DATA_STRUCTURE myData;
 
int counter;

char charr;
 
void setup()
{
 //Initalizing EasyTransfer Serial Ports
 Serial.begin(9600);
 ET.begin(details(myData), &Serial);
 
counter = 0;
}
 
void loop()
{
  charr = Serial.read();
 //Setting Values to Variables
 myData.char_data = charr;
 //myData.int_data = counter++;
 
//Sending Data
 ET.sendData();
 delay(1000);
}
