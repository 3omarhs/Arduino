#include <Keypad.h>
//#include <LiquidCrystal.h>
//#include <Servo.h>
//Servo //servo;//Servo
const int inn = 11;
const int inn2 = 12;
const int buttonPin = 7;
const int buttonPinb = 10;
int motor = 8;
int reverse = 9;
int greenLed = 5;//Green led
int redLed = 6;//Red led
int buzzer = 4;//Buzzer
int reset = 13;

//LiquidCrystal lcd(12, 11, 10, 9, 8, 7);//LCD

const byte rows = 4;//rows
const byte columns = 4;//columns
char correctPassword[10] = {'1', '3', '7', '9'}; //Correct password
char enteredPassword[10];//Entered password on keypad
char charKey;//Key on keypad
int i = 0;
int val = 0;//Counter
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

void setup()
{
  // servo.attach(13);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(inn, INPUT);
  pinMode(inn2, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinb, INPUT);
  pinMode(reset, OUTPUT);
  /*
    //lcd.setCursor(0, 0);
    //lcd.print("Keypad Door Lock");
    //delay(2000);
    //lcd.clear();
    //lcd.setCursor(0, 0);
    //lcd.print("Password: ");
    //Serial.begin(9600);
    //Serial.println("Keypad Door Lock"); */
}

void loop()
{

  if (charKey == '#')

  {
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(reverse, HIGH);
    delay(400);
    digitalWrite(greenLed, LOW);
    delay(100);
    digitalWrite(reverse, LOW);
    delay(500);
  }
  else
  { digitalWrite(motor, LOW);
  }





  if (charKey == 'D')

  {
    enteredPassword[i = 0] = charKey;

    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
  }
  else {
    digitalWrite(motor, LOW);

  }


  if (charKey == 'C')
  {
    if (i > 0) {
      enteredPassword[i--] = charKey;
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
    }
  }
  else {
    digitalWrite(motor, LOW);

  }



  if (charKey == '*')

  {
    digitalWrite(reset, HIGH);
    for (i = 1; i <= 3; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
    digitalWrite(reset, LOW);
    delay(300);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(100);
    delay(300);
    for (i = 1; i <= 3; i++)
    { digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
    delay(600);
    for (i = 1; i <= 3; i++)
    { digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
    delay(300);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(100);
    delay(300);
    for (i = 1; i <= 3; i++)
    { digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
  }
  else {
    digitalWrite(motor, LOW);
  }
  val = digitalRead(buttonPinb);// cloase
  if (val == HIGH)
  {
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(reverse, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(100);
    digitalWrite(reverse, LOW);
    delay(500);
  }
  else {
    digitalWrite(motor, LOW);
  }
  val = digitalRead(buttonPin);// cloase
  if (val == HIGH)
  {
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(motor, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(100);
  }
  else {
    digitalWrite(motor, LOW);
  }
  val = digitalRead(inn);// cloase
  if (val == HIGH)
  {
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(motor, HIGH);
    delay(400);
    digitalWrite(greenLed, LOW);
    delay(1000);
  }
  else {
    digitalWrite(motor, LOW);
  }
  val = digitalRead(inn2);// cloase
  if (val == HIGH)
  {
    digitalWrite(redLed, HIGH);
    // /*
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(100);
    //  /*
    digitalWrite(reverse, HIGH);
    delay(400);
    digitalWrite(redLed, LOW);
    delay(100);
    digitalWrite(reverse, LOW);
  }
  else {
    digitalWrite(motor, LOW);
  }
  {
    //servo.write(0);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    charKey = kpad.getKey();
    if (charKey && charKey != '#' && charKey != '*' && charKey != 'D' && charKey != 'C')
    {
      enteredPassword[i++] = charKey;
      //lcd.setCursor(i, 1);
      //lcd.print("*");
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
    }
    if ( i == 4) {
      delay(200);
      char correctPassword[4] = {'7', '9', '5', '9'}; //Correct password
      if ((strncmp(enteredPassword, correctPassword, 4) ==  0))
      {
        /*lcd.clear();
          lcd.setCursor(0, 0);
          servo.write(90);
          lcd.print("Access Granted!!!"); */
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        digitalWrite(motor, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(1000);
        digitalWrite(motor, LOW);
        //lcd.clear();
        //lcd.setCursor(0, 0);
        //lcd.print("Password: ");
        i = 0;
      }
    }
    if ( i == 9) {
      delay(200);
      char correctPassword[9] = {'2', '0', '1', '9', '1', '0', '1', '5', '5'}; //Correct password
      if ((strncmp(enteredPassword, correctPassword, 9) ==  0))
      {
        /*   lcd.clear();
          lcd.setCursor(0, 0);
          servo.write(90);
          lcd.print("Access Granted!!!"); */
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        digitalWrite(motor, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(1000);
        digitalWrite(motor, LOW);
        //lcd.clear();
        //lcd.setCursor(0, 0);
        //lcd.print("Password: ");
        i = 0;
      }
    }
    else if (i == 8)
    {
      delay(200);
      char correctPassword[8] = {'A', 'B', 'A', 'B', '1', '2', '1', '2'}; //Correct password
      if ((strncmp(enteredPassword, correctPassword, 8) ==  0))
      {
        /*   lcd.clear();
          lcd.setCursor(0, 0);
          servo.write(90);
          lcd.print("Access Granted!!!"); */
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        digitalWrite(motor, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(1000);
        digitalWrite(motor, LOW);
        //lcd.clear();
        //lcd.setCursor(0, 0);
        //lcd.print("Password: ");
        i = 0;
      }
      //from here0
      else if (i == 8)
      {
        delay(200);
        char correctPassword[8] = {'7', '7', '9', '9', '5', '5', '9', '9'}; //Correct password
        if ((strncmp(enteredPassword, correctPassword, 8) ==  0))
        {
          /*   lcd.clear();
            lcd.setCursor(0, 0);
            servo.write(90);
            lcd.print("Access Granted!!!"); */
          digitalWrite(greenLed, HIGH);
          digitalWrite(redLed, LOW);
          digitalWrite(motor, HIGH);
          digitalWrite(buzzer, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          delay(100);
          digitalWrite(buzzer, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          delay(1000);
          digitalWrite(motor, LOW);
          //lcd.clear();
          //lcd.setCursor(0, 0);
          //lcd.print("Password: ");
          i = 0;
        }
        //tell here0
        else
        {
          //lcd.clear();
          //lcd.setCursor(0, 0);
          //lcd.print("Access Denied!!!");
          digitalWrite(greenLed, LOW);
          digitalWrite(redLed, HIGH);
          digitalWrite(reverse, HIGH);
          digitalWrite(buzzer, HIGH);
          delay(1000);
          digitalWrite(buzzer, LOW);
          delay(1000);
          digitalWrite(reverse, LOW);
          //lcd.clear();
          //lcd.setCursor(0, 0);
          //lcd.print("Password: ");
          i = 0;
        }
      }
    }
  }
}
