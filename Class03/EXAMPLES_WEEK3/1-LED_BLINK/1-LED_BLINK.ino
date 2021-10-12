
const int LED_PIN=13;
const int PT=3;
int pot= A0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(LED_PIN,OUTPUT);
//pinMode(PT,OUTPUT);
}

void loop() {
int val=analogRead(pot);
analogWrite(PT,val/4);
 Serial.println(val/4);
//  digitalWrite(LED_PIN,HIGH);  // 5V
//  delay(1000);
//   analogWrite(PT,0);
//  digitalWrite(LED_PIN,LOW); //OV
//   delay(1000);

}
