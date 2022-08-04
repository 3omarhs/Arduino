/* Yu Hin Hau
 * Easy Transfer Tutorial RX
 * 8/4/2012
 */
 
#include <EasyTransfer.h>
 
EasyTransfer ET;
 
struct DATA_STRUCTURE{
 int int_data;
 char char_data;
};
 
DATA_STRUCTURE myData;
 
void setup()
{
 Serial.begin(9600);
 ET.begin(details(myData), &Serial);
}
 
void loop()
{
 //Extract data if data is received
 if(ET.receiveData())
 {
 Serial.println(myData.char_data);
 //Serial.println(myData.int_data);
 //Serial.write(myData.char_data);
 //Serial.write(myData.int_data);
 delay(250);
 }
 
}
