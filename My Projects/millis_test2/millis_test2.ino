// Interval is how long we wait
// add const if this should never change
int interval=6000;
int H, M, S;
// Tracks the time since last event fired
unsigned long previousMillis=0;
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   // Get snapshot of time
   unsigned long currentMillis = millis();
 
   // How much time has passed, accounting for rollover with subtraction!
   if ((unsigned long)(currentMillis - previousMillis) <= interval) {
      S = currentMillis;
   }
   if ((unsigned long)(currentMillis - previousMillis) >= interval) {
      // It's time to do something!
      M++;
      Serial.print("++m");
   }
      // Use the snapshot to set track time until next event
      previousMillis = currentMillis;
      Serial.print("Time: ");
      Serial.print(H);
      Serial.print(":");
      Serial.print(M);
      Serial.print(":");
      Serial.println(S);
   delay(1000);
}
