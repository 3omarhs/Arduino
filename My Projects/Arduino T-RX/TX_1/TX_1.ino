void setup(){
  Serial.begin(9600);
}
//String num;
void loop()
{
    /*char letter = Serial.read();
    Serial.write(letter);
    Serial.write(letter);
    Serial.println(letter);
    delay(500);*/
    
    for(int i=0;i<=20;i++){
      Serial.print(i);
    }
    
    
    //Serial.write('5');
}
