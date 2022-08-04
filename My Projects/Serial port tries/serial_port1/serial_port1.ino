#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 3); // RX, TX

void setup()
{
  Serial.begin(9600);
  while (!Serial) {;}
  Serial.println("3omar.hs");
  mySerial.begin(38400);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  /*if (mySerial.available())
    Serial.write(mySerial.read());*/
  if (mySerial.available()){
    Serial.print(mySerial.read());
    byte b1=mySerial.read();
    //Serial.println(b1);
  }
}
