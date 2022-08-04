const int buttonpin = 2; 
int greenled = 3;
int redled = 4;
int buzzer = 6;
int relay = 5;
int i;
void setup() {
  pinMode(buttonpin, INPUT);
  pinMode(greenled, OUTPUT);  
  pinMode(redled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
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
  delay(60000);
  //delay(1000);
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
turn_on();
time850s();
turn_off();
}
else
  digitalWrite(greenled, HIGH);
}
