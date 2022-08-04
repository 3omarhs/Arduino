int counter = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
counter ++;

}

/*
 * in edo1
 * (reciver)
 * char str[4];
 * void setup(){
 * Serial.begin(9600);
 * Serial1.begin(9600);
 * }
 * void loop(){
 * int i = 0;
 * if (Serial1.available()) {
 *  delay(100);
 *  while(Serial1.available() && i<4) {
 *    str[i++] = Serial1.read();
 *   }
 *   str[i++]='\0';
 * }
 * if(i>0) {
 * Serial.println(str,4);
 * }
 * }
 * 
 * 
 * 
 * 
 * in edo2
 * (sender)
 * 
 * char str[4];
 * int value;
 * void setup(){
 * Serial.begin(9600);
 * }
 * void loop(){
 * IF(*********){
 * value = 0000
 * itoa(value, str, 10);
 * Serial.write(str, 4);
 *  }
 * }
 * 
 * //////////////
 * 0000 == WRONG
 * 1111 == TRUE
 * 
 */





 /*
 * in edo1
 * (reciver)
 * char str[1];
 * void setup(){
 * Serial.begin(9600);
 * Serial1.begin(9600);
 * }
 * void loop(){
 * if (Serial1.available()) {
 *  delay(100);
 *  str[1] = Serial1.read();
 * }
 * Serial.println(str,1);
 * }
 * }
 * 
 * 
 * 
 * 
 * in edo2
 * (sender)
 * 
 * char str[1];
 * int value;
 * void setup(){
 * Serial.begin(9600);
 * }
 * void loop(){
 * IF(*********){
 * value = 0
 * itoa(value, str, 10);
 * Serial.write(str, 1);
 *  }
 * }
 * 
 * //////////////
 * 0 == WRONG
 * 1 == TRUE
 * 
 */
