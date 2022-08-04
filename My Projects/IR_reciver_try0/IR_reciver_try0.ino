#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

unsigned long key_value = 0;

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  //if (irrecv.decode()) {//&results
    /*Serial.println(results.value, HEX);
    // Receive the next value
    //Serial.println(key_value);
     
     if (results.value == 0xED126B86){
      Serial.println("power");
     }

     if (results.value == 0xE41B6B86){
      Serial.println("video select");
     }

     if (results.value == 0xFA056B86){
      Serial.println("menue");
     }

     if (results.value == 0xE51A6B86){
      Serial.println("mode sselect");
     }

     if (results.value == 0xF9066B86){
      Serial.println("right");
     }

     if (results.value == 0xFB046B86){
      Serial.println("left");
     }
     IrReceiver.printIRResultAsCVariables(&Serial);
  */

  if (IrReceiver.decode()) {
        if (!(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW)) {
            IrReceiver.printIRResultAsCVariables(&Serial);  // Output address and data as source code variables
            //Serial.println(
            //Serial.println(decodedIRData.decodedRawData, HEX);
            IrReceiver.initDecodedIRData();
            //IrReceiver.initDecodedIRData(&decodedIRData);
            Serial.print("....");
            Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
            Serial.println(IrReceiver.decodedIRData.rawDataPtr->rawbuf[0xED126B86], HEX);
            if ((IrReceiver.decodedIRData.decodedRawData == 0xED126B86)||(IrReceiver.decodedIRData.decodedRawData == 0xFA056B86)){
              Serial.println("power");
            }
           /* Serial.print(F("uint32_t data = 0x"));
        Serial.print(decodedIRData.decodedRawData, HEX);
        Serial.println(';');
        Serial.println();*/
        }
        //IrReceiver.resume();
  irrecv.resume();
  }
  delay(100);
}
