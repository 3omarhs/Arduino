#define LDRpin A0
#define LED 12
long myTime, onTime;
int LDRValue = 0;
long calculate_time;
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  myTime = millis();
}

void loop() {
  if(millis() >= myTime + 1){  //read every ... time
    LDRValue = analogRead(LDRpin);
    Serial.println(LDRValue);
    myTime = millis();
    
    if(LDRValue >= 100){
      digitalWrite(LED, HIGH);
      onTime = millis();
      if(calculate_time != 0){
        Serial.print("calculate time: ");
        long x = millis() - calculate_time;
        Serial.println(x);
        calculate_time = 0;
      }
      calculate_time = millis();
    }
    if(millis() > onTime + 500)    //if flash off for ... seconds turn light off
      digitalWrite(LED, LOW);
  }
    
  }
