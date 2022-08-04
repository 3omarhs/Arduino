//read usb on analog pin
// Green >> A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("pin A0 read: ");
  Serial.println(analogRead(A0));
//  Serial.print("pin A1 read: ");
//  Serial.println(analogRead(A1));
}
