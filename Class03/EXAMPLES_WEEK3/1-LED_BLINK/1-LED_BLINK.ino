#define LED_PIN 13
void setup() {
  // put your setup code here, to run once:

pinMode(LED_PIN,OUTPUT);
}

void loop() {
 
  digitalWrite(LED_PIN,HIGH);  // 5V
  delay(1000);
  digitalWrite(LED_PIN,LOW); //OV
   delay(1000);

}
