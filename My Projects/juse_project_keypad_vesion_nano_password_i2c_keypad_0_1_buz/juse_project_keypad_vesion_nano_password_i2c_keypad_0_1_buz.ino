#include <Key.h>
#include <Keypad.h>
#include <Keypad_I2C.h>
#define I2CADDR 0x20
// SDA >> A4,  SCL >> A5 : in Arduino micro pro
int relay = 10;  // old was: 4
int button = 11;
int led = 12;

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [ROWS] = {0, 1, 2, 3}; // Connect to Keyboard Row Pin
byte colPins [COLS] = {4, 5, 6, 7}; // Connect to Pin column of keypad.
Keypad_I2C kpad (makeKeymap (keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

int i = 0;  //for loop
int j = 0;  //digits entred
int val = 0;//Counter
bool active = false;
char enteredPassword[5];
char charKey;
int var;


void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(relay, LOW);
  pinMode(button, INPUT);
  Wire .begin ();
  kpad.begin (makeKeymap (keys));
  Serial.begin (9600);
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

digitalWrite(relay, LOW);

if(active == true){
  var = digitalRead(button);
while(var == HIGH){
  var = digitalRead(button);
  digitalWrite(relay, HIGH);
}
  digitalWrite(led, HIGH);
  if(charKey == 'B'){
    Serial.println("B");
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
  }
  if(charKey == '6'){
    Serial.println("6");
    digitalWrite(relay, HIGH);
    delay(3500);
    digitalWrite(relay, LOW);
  }
  if(charKey == '5'){
    Serial.println("5");
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
  }
  if(charKey == '4'){
    Serial.println("4");
    digitalWrite(relay, HIGH);
    delay(7000);
    digitalWrite(relay, LOW);
  }
  if(charKey == 'C'){
    Serial.println("C");
    digitalWrite(relay, HIGH);
    delay(8500);
    digitalWrite(relay, LOW);
  }
  if(charKey == '9'){
    Serial.println("9");
    digitalWrite(relay, HIGH);
    delay(10500);
    digitalWrite(relay, LOW);
  }
  if(charKey == '8'){
    Serial.println("8");
    digitalWrite(relay, HIGH);
    delay(12500);
    digitalWrite(relay, LOW);
  }
  if(charKey == '7'){
    Serial.println("7");
    digitalWrite(relay, HIGH);
    delay(14000);
    digitalWrite(relay, LOW);
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
