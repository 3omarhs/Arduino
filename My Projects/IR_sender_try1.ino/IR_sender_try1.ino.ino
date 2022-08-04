#include <IRremote.h>
IRsend irsend = 3;

void setup() {

}
void loop()
{

delay(50);
irsend.sendRC5(0xEE1AAFE4, 32);
delay(1000);
delay(50);
irsend.sendRC5(0xE0E040BF, 32);
delay(1000);
delay(50);
irsend.sendRC5(0xEAB7BACD, 32);
delay(1000);
delay(50);
irsend.sendRC5(0x7B33B312, 32);
delay(1000);
delay(50);
irsend.sendRC5(0xD9435459, 32);
delay(1000);

}
