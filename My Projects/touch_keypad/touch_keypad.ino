/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/    
 * www.osoyoo.com water drop sensor
 * program tutorial :http://osoyoo.com/2016/07/11/capacitive-touchpad-16channel/
 *  Copyright John Yu
 */
int SCLPin = 6, SDOPin = 7;
unsigned int DATA = 0, old_DATA = 0, DATA1 = 0, count = 0;
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
  return DATA&0xFFFF;
}

void loop()
{
  DATA = ttp229();
  if (DATA != old_DATA)
  {
//    Serial.println(DATA, BIN);
    DATA1 = DATA;
    count = 0;
    while(DATA1 !=1){
      DATA1/=2;
      count++;
    }
//    Serial.println(DATA);
    Serial.println(count+1);
    //old_DATA = DATA;
    delay(100);
  }
}
