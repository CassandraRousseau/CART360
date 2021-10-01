#define LED_PIN 11
#define POT_PIN A0
void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(9600);

}

void loop() {
  int potVal = analogRead(POT_PIN);
  //range is 0-1023;
  //Serial.println(potVal);
 //val is between 0-255! 8 bit microcontroller
  analogWrite(LED_PIN,potVal/4);
  delay(500);
  analogWrite(LED_PIN,0);
  delay(500);

}
