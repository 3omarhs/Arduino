#include <IRremote.h>

/* HOW TO WIRE UP LCD SCREEN LEFT TO RIGHT PIN WITH PINS ON TOP SIDE
 *  
 *  GND - VCC - POT MIDDLE - 12 - GND - 11 - NONE - NONE - NONE - NONE - 5 - 4 - 9 - 2 - VCC - GND
 *  
 *  POT MUST HAVE 5V AND GND ON IT AND CAN ROTATE THE KNOB TO CHANGE LCD CONTRAST
 */
 

int receiverpin = 10;
unsigned long key_value = 0;
IRrecv irrecv(receiverpin);
decode_results results;


void setup() {
  pinMode(receiverpin, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    key_value = results.value, HEX;
    if(key_value != 0xFFFFFFFF)  //4294967295)
      Serial.println(key_value, HEX);
    //Serial.println(results.value, HEX);
    key_value = results.value;
    /*
  if(results.value == 4294967295){   //61D6A05F     //satalite remote power button: 3937909453  EE1AAFE4  //EAB7BACD
    //7E2DD423
//E2C1069D   CBA4D716   3CB3A524


    Serial.print("Power ON/OFF  ");
    Serial.println(results.value);
  }
  else if(key_value == "1D6D827"){
    Serial.print("Video Select  ");
    Serial.println(results.value);
  }
  else if(results.value == '61D658A7'){
    Serial.print("Mode Select  ");
    Serial.println(results.value);
  }
  else if(results.value == '1641455711'){   //61D648B7        //3937909453
    Serial.print("Menu  ");
    Serial.println(results.value);
  }
  else if(results.value == '61D6609F'){
    Serial.print("Right  ");
    Serial.println(results.value);
  }
  else if(results.value == '61D620DF'){
    Serial.print("Left  ");
    Serial.println(results.value);
  }
  else{
    Serial.print("Unknown..  ");
    Serial.println(results.value);
  }
  /*switch(results.value){
    case 4294967295: Serial.println("POWER"); break; irrecv.resume();
    case : Serial.println("Menu"); break; irrecv.resume();
    default: 
      Serial.print(" other button   ");
      Serial.println(results.value);*/
  irrecv.resume();
    delay(150);
  }
}
