unsigned long myTime;
bool on = false, f1 = false;


int led = 13;
int val;
const int button = 2;

void setup() {
Serial.begin(9600);
pinMode(button, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  
if(digitalRead(button) == HIGH){
  myTime = millis();
  Serial.println("first click");
while(digitalRead(button) == HIGH){
  if(((millis() - myTime) >= 1000)&&(f1 == false)){
    if(on == false){
      digitalWrite(led, HIGH);
      on = true;
    }
    else{
      digitalWrite(led,LOW);
      on = false;
    }
    f1 = true;
  }
  if(digitalRead(button) == LOW)
    break;
}
f1 = false;
}
}
