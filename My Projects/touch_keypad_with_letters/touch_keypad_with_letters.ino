/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____
   / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \
  | |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
   \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
                    (____/
   www.osoyoo.com water drop sensor
   program tutorial :http://osoyoo.com/2016/07/11/capacitive-touchpad-16channel/
    Copyright John Yu
*/
int SCLPin = A4, SDOPin = A5;
unsigned int DATA = 0, old_DATA = 0, DATA1 = 0, count = 0;
char c;
void setup()
{
  Serial.begin(9600);
  pinMode(SCLPin , OUTPUT);   //时钟端输出
}

unsigned int ttp229()     //一次读完TTP229所有按键
{
  unsigned int DATA = 0;
  pinMode(SDOPin , OUTPUT);
  digitalWrite(SDOPin, HIGH);
  delayMicroseconds(93);
  digitalWrite(SDOPin, LOW);
  delayMicroseconds(10);
  pinMode(SDOPin , INPUT);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(SCLPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(SCLPin, LOW);
    DATA |= digitalRead(SDOPin) << i;
  }
  delay(2);
  return DATA & 0xFFFF;
}

void loop()
{
  DATA = ttp229();
  if (DATA != old_DATA)
  {
    //    Serial.println(DATA, BIN);
    DATA1 = DATA;
    count = 0;
    while (DATA1 != 1) {
      DATA1 /= 2;
      count++;
    }
    //    Serial.println(DATA);
    int num = count + 1;
    //    Serial.println(num);
    if (num == 1)
      c = '1';
    else if (num == 2)
      c = '2';
    else if (num == 3)
      c = '3';
    else if (num == 4)
      c = 'A';
    else if (num == 5)
      c = '5';
    else if (num == 6)
      c = '6';
    else if (num == 7)
      c = '7';
    else if (num == 8)
      c = 'B';
    else if (num == 9)
      c = '9';
    else if (num == 10)
      c = 'a';
    else if (num == 11)
      c = 'b';
    else if (num == 12)
      c = 'C';
    //        c = 'c';
    else if (num == 13)
      c = '*';
    else if (num == 14)
      c = '0';
    else if (num == 15)
      c = '#';
    else if (num == 16)
      c = 'D';
    //        c = 'g';
    else
      c = '-';
    //old_DATA = DATA;
    delay(100);
    Serial.println(c);
//    Serial.println(DATA);
  }
}
