    /*
  YF-S201-Water-Flow-Sensor
  modified on 14 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  https://electropeak.com/learn/

  based on www.hobbytronics.co.uk examples
*/
double flow; //Water flow L/Min 
int flowsensor = 2; 
unsigned long currentTime;
unsigned long lastTime;
unsigned long pulse_freq;
volatile byte pulseCount; 
 
void pulse () // Interrupt function

{
   pulse_freq++;
}

   void setup()
 {
   pinMode(flowsensor, INPUT);
   Serial.begin(9600);
   attachInterrupt(0, pulse, RISING); // Setup Interrupt
   currentTime = millis();
   lastTime = currentTime;
}

   void loop ()
{
   currentTime = millis();
   // Every second, calculate and print L/Min
   if(currentTime >= (lastTime + 1000))
   {
      lastTime = currentTime; 
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      flow = (pulse_freq / 7.5); 
      pulse_freq = 0; // Reset Counter
      Serial.print(flow, DEC); 
      Serial.println(" L/Min");
      
   }
}
