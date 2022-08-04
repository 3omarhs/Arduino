const int buttonpin = 2; 
int greenled = 3;
int redled = 4;
int buzzer = 6;
int relay = 5;
int i;
int ThermistorPin = A0;
void setup() {
  pinMode(buttonpin, INPUT);
  pinMode(greenled, OUTPUT);  
  pinMode(redled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}


void turn_on(){
  digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
  digitalWrite(relay, HIGH);
  for(i=0; i<=1; i++){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
}


void time850s(){
  delay(85000);
  //delay(1000);
}


void sensor(){
  int Vo = analogRead(ThermistorPin);
  Vo/=10;
  if (Vo>=100){
    digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
  digitalWrite(relay, LOW);
  for(i=0; i<=5; i++){
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
  }
}


void turn_off(){
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
  digitalWrite(relay, LOW);
  for(i=0; i<=5; i++){
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
}


void loop() { 
int val = digitalRead(buttonpin);
if(val == HIGH){
//turn_on();
digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
  digitalWrite(relay, HIGH);
  for(i=0; i<=1; i++){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  delay(5000);
  //sensor();
 int Vo = analogRead(ThermistorPin);
  Vo/=10;
   Serial.println(Vo);
  while(Vo<103){
    Vo = analogRead(ThermistorPin);
    Vo/=10;
    Serial.println(Vo);
    delay(500);
    digitalWrite(redled, HIGH);
  }
  if (Vo>=100){
    //turn_off();
    digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
  digitalWrite(relay, LOW);
  for(i=0; i<=5; i++){
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
  }
//time850s();
}
else
  digitalWrite(greenled, HIGH);
  int Vo = analogRead(ThermistorPin);
  Vo/=10;
   Serial.println(Vo);
   delay(500);
}
