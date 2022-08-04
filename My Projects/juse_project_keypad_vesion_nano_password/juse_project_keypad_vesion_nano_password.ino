#include <Keypad.h> 

const byte rows = 4;//rows
const byte columns = 4;//columns
char charKey;//Key on keypad 
int i = 0;  //for loop
int j = 0;  //digits entred
int val = 0;//Counter
bool active = false;
char enteredPassword[5];
char keypad[4][4] =//Keypad array
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowsPins[4] = {A0, A1, A2, A3};//Rows pins
byte columnspPins[4] = {A4, A5, 2, 3};//Columns pins

Keypad kpad = Keypad(makeKeymap(keypad),
rowsPins, columnspPins, 4, 4);//Keypad map


int led = 12;
int relay = 4;
int button = 11;
int var;

void setup() {
  // put your setup code here, to run once:
pinMode(relay, OUTPUT);
pinMode(led, OUTPUT);
digitalWrite(relay, HIGH);
pinMode(button, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
/*val = digitalRead(button);
if(val == HIGH){
  digitalWrite(relay, LOW);
  delay(10000);
  digitalWrite(relay, HIGH);
}*/
charKey = kpad.getKey();

digitalWrite(relay, HIGH);

if(active == true){
  var = digitalRead(button);
while(var == HIGH){
  var = digitalRead(button);
  digitalWrite(relay, LOW);
}
  digitalWrite(led, HIGH);
  if(charKey == 'B'){
    Serial.println("B");
    digitalWrite(relay, LOW);
    delay(2000);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '6'){
    Serial.println("6");
    digitalWrite(relay, LOW);
    delay(3500);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '5'){
    Serial.println("5");
    digitalWrite(relay, LOW);
    delay(5000);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '4'){
    Serial.println("4");
    digitalWrite(relay, LOW);
    delay(7000);
    digitalWrite(relay, HIGH);
  }
  if(charKey == 'C'){
    Serial.println("C");
    digitalWrite(relay, LOW);
    delay(8500);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '9'){
    Serial.println("9");
    digitalWrite(relay, LOW);
    delay(10500);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '8'){
    Serial.println("8");
    digitalWrite(relay, LOW);
    delay(12500);
    digitalWrite(relay, HIGH);
  }
  if(charKey == '7'){
    Serial.println("7");
    digitalWrite(relay, LOW);
    delay(14000);
    digitalWrite(relay, HIGH);
  }
}
if(active == false){
  digitalWrite(led, LOW);
}
if((charKey == '#')||(charKey == '0')||(charKey == '*')){
  Serial.print("pass:");
  enteredPassword[j++] = charKey;
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  //Serial.print("j=");
  //Serial.println(j);
}
if(charKey == 'D'){
  j = 0;
  for(int i=0; i<=3; i++){
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(50);
  }
  active = false;
  Serial.print("unactive");
}
if (j == 5){
  char correctPassword[8] = {'*', '*', '#', '#', '0'};//Correct password
  if ((strncmp(enteredPassword, correctPassword, 5)==  0)){
    j = 0;
    active = true;
    Serial.print("active");
  }
  else{
    j = 0;
    Serial.println("wrong pass");
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
}
if (charKey != NO_KEY){
  Serial.println(charKey);
}

}
