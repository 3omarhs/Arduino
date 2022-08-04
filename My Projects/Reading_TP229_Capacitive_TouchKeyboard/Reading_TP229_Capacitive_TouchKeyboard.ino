
/*
  Reading a TTP229 based capacitive touch Keyboard 
  to enable 16-Key Mode short TP2 with a 820kOhms (up to 1MOhms) 
  Resistor to GROUND or close Jumper 3 on TP229 Module
  
  hardware required TTP229 Module with
    * SCL connected to PIN8
    * SDD connected to PIN9
    
  created 1 Mar 2015
  by Thomas Schmitz (thomas.schmitz@tschmitz.com)

  This example code is part of the public domain  
*/

#define CLOCK_PIN 8
#define DATA_PIN 9

void setup() 
{
  Serial.begin(9600);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);
  digitalWrite(CLOCK_PIN, HIGH);
}

void loop() {

  for (int button = 1; button < 17; button++)
  {
    //set clock
      digitalWrite(CLOCK_PIN, LOW);
      
    //read bit
      int databit = digitalRead(DATA_PIN);
      Serial.print(databit);
      
    //reset clock
      digitalWrite(CLOCK_PIN, HIGH);   
  };
  Serial.println();
}
