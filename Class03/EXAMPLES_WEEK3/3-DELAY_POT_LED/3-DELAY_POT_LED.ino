#define LED_PIN 11 // SCHEMATIC SAYS 13 - ENSURE EVERYONE TO CHANGE TO 11
#define POT_PIN A0
void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(9600);

}

void loop() {
  int potVal = analogRead(POT_PIN);
  //range is 0-1023;
  //Serial.println(potVal);
 
  digitalWrite(LED_PIN,HIGH);
  delay(potVal);
  digitalWrite(LED_PIN,LOW);
  delay(potVal);

}
