#include <Keypad.h>

char charKey;
char keypad[4][4] =//Keypad array
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowsPins[4] = {A0, A1, A2, A3};//Rows pins
byte columnspPins[4] = {A4, A5, 2, 3};//Columns pins

Keypad kpad = Keypad(makeKeymap(keypad),rowsPins, columnspPins, 4, 4);//Keypad map
bool d0 = false, D_pressed = false, is_y = false, detected_opperation = false;
int position = 1, x = -1, y = -1, z = 0;
char operation;

void setup() {

}

void loop() {
  charKey = kpad.getKey();
  
  while(position == 1){
    position1_control();
  }
  
  while(position == 2){
    position2_calculator();
  }
  
}

void position1_control(){
  charKey = kpad.getKey();
  if(charKey == '1'){
    Serial.print("1 is pressed in control unit.");
  }
  else if(charKey == '2'){
    Serial.print("2 is pressed in control unit.");
  }
  else if(charKey == '3'){
    Serial.print("3 is pressed in control unit.");
  }
  else if(charKey == '4'){
    Serial.print("4 is pressed in control unit.");
  }
  else if(charKey == '5'){
    Serial.print("5 is pressed in control unit.");
  }
  else if(charKey == '6'){
    Serial.print("6 is pressed in control unit.");
  }
  else if(charKey == '7'){
    Serial.print("7 is pressed in control unit.");
  }
  else if(charKey == '8'){
    Serial.print("8 is pressed in control unit.");
  }
  else if(charKey == '9'){
    Serial.print("9 is pressed in control unit.");
  }
  else if(charKey == '0'){
    Serial.print("0 is pressed in control unit.");
  }
  else if(charKey == 'A'){
    Serial.print("A is pressed in control unit.");
  }
  else if(charKey == 'B'){
    Serial.print("B is pressed in control unit.");
  }
  else if(charKey == 'C'){
    Serial.print("C is pressed in control unit.");
  }
  
  double_click();
  if(D_pressed == true){
    D_pressed = false;
    position++
  }
}

void position2_calculator(){
  charKey = kpad.getKey();
  if(is_y == false)&&(detected_opperation == false){
    if((charKey == '0')||(charKey == '1')||(charKey == '2')||(charKey == '3')||(charKey == '4')||(charKey == '5')||(charKey == '6')||(charKey == '7')||(charKey == '8')||(charKey == '9')){
      Serial.print(charKey);
      if(x != -1)
        x+ = charKey.toInt();
      else
        x = charKey.toInt();
      Serial.print("x = ");
      Serial.print(x);
    }
  }
  else if((charKey == 'A')||(charKey == 'B')||(charKey == 'C')||(charKey == '*')||(charKey == '#')){
    if(charKey == 'A'){
      opperation = '+';
    }
    if(charKey == 'B'){
      opperation = '-';
    }
    if(charKey == '*'){
      opperation = '*';
    }
    if(charKey == '#'){
      opperation = '/';
    }
    if(charKey == 'C'){
      opperation = '=';
    }
    detected_opperation = true;
    Serial.print(opperation);
    is_y = true;
  }
  
  else if(is_y == true)&&(detected_opperation == true){
    if((charKey == '0')||(charKey == '1')||(charKey == '2')||(charKey == '3')||(charKey == '4')||(charKey == '5')||(charKey == '6')||(charKey == '7')||(charKey == '8')||(charKey == '9')){
      Serial.print(charKey);
      if(y != -1)
        y+ = charKey.toInt();
      else
        y = charKey.toInt();
      Serial.print("y = ");
      Serial.print(y);
      is_y = false;
    }
  }

  else if(opperation == '='){
    Serial.println(z);
  }

  else if((is_y == false)&&(detected_opperation == true)){
    detected_opperation = false;
    if(opperation == '+')
      z = x+y;
    else if(opperation == '-')
      z = x-y;
    else if(opperation == '*')
      z = x*y;
    else if(opperation == '/')
      z = x/y;
  }

  double_click();
  if(D_pressed == true){
    D_pressed = false;
    position--
  }
}

void double_click(){
  if((charKey == 'D')&&(d0 == true)){
    d0 = false;
    D_pressed = true;
  }
  if((charKey == 'D')&&(d0 == false)){
    d0 = true;
  }
  //double_click();
  //D_pressed == true >> position2
}
