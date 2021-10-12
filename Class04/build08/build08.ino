const int BUZZER=3;
const int RESISTLAD=A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(BUZZER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(RESISTLAD));
}
