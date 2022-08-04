int out1 = 5;
int out2 = 6;
int out3 = 7;


void setup() { 


pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
pinMode(out3, OUTPUT);


} 


void loop() {
    digitalWrite(out1, HIGH);
    delay(300);
    digitalWrite(out1, LOW);
    delay(300);
    digitalWrite(out2, HIGH);
    delay(300);
    digitalWrite(out2, LOW);
    delay(300);
    digitalWrite(out3, HIGH);
    delay(300);
    digitalWrite(out3, LOW);
    delay(300);

                  }