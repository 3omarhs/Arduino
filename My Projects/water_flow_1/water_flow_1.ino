    /*
  YF-S201-Water-Flow-Sensor
  modified on 14 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  https://electropeak.com/learn/

  based on www.hobbytronics.co.uk examples
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

double flow; //Water flow L/Min 
int flowsensor = 2; 
unsigned long currentTime;
unsigned long lastTime;
unsigned long pulse_freq;
float vol = 0.0,l_minute;
 
void pulse () // Interrupt function

{
   pulse_freq++;
}

   void setup()
 {
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("3omar.hs");
   pinMode(flowsensor, INPUT);
   Serial.begin(9600);
   attachInterrupt(0, pulse, RISING); // Setup Interrupt
   currentTime = millis();
   lastTime = currentTime;
}

   void loop ()
{

  l_minute = (pulse_freq / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
  l_minute = l_minute / 60;
  vol = vol + l_minute;
  
   currentTime = millis();
   // Every second, calculate and print L/Min
   if(currentTime >= (lastTime + 1000))
   {
      lastTime = currentTime; 
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      flow = (pulse_freq / 7.5); 
      pulse_freq = 0; // Reset Counter
  Serial.print("Vol:");
  Serial.println(vol/100000, DEC);
      Serial.print(flow, DEC); 
      Serial.println(" L/Min");
      lcd.setCursor(0, 0);
      lcd.print("Vol:");
      lcd.setCursor(4, 0);
      lcd.print((vol/10000)*2, DEC);
      lcd.setCursor(0, 1);
      lcd.println("flow:");
      lcd.setCursor(5, 1);
      lcd.print(flow, DEC); 
   }
}
