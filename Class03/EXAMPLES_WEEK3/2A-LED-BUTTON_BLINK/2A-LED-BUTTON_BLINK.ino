#define LED_PIN 11
#define BUTTON_PIN 2
boolean buttonState = false;

// we want to TOGGLE ...
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
    buttonState = !buttonState; //switch button state
  }

  if (buttonState == true) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  //small delay  -why?
  delay (200);


}

// what happens if we keep on pressing -- it blinks -- so we need to fix...
