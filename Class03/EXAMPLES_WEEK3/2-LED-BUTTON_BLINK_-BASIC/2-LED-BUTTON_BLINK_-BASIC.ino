#define LED_PIN 11
#define BUTTON_PIN 2


// JUST PRESS BUTTON  - > WHILE PRESSED On ELSE off
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonVal = digitalRead(BUTTON_PIN);
  //Serial.println(buttonVal);
  if (buttonVal == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}

// what happens if we keep on pressing -- it blinks -- so we need to fix...
