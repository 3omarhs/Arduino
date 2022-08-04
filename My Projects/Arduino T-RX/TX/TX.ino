#include<SoftwareSerial.h>
SoftwareSerial SUART(2, 3); //SRX = DPin-2; STX = DPin-3

char myMsg[] = "141-142 Love Road";
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.flush();
  Serial1.flush();
}

void loop()
{
  Serial.print("Sending to UNO-2 this string: ");
  Serial.println(myMsg);   //show on SM1 of Fig-1 what you are sending to UNO-2
  //--------------------
  Serial1.write(myMsg);   //send ASCII coded string to UNO-2 via SUART Port; goes 1 char at a time
  delay(50);          //1-sec test interval
}
