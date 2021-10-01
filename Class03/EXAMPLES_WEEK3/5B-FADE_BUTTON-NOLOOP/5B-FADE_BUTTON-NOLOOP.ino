#define LED_PIN 11
#define BUTTON_PIN 2
boolean buttonState = false;
int fadeVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin (9600); // show with serial ... the unresponsiveness

}

void loop() {
  int buttonVal = digitalRead(BUTTON_PIN); // read value from button
  Serial.println(buttonVal);

  if (buttonVal == HIGH)
  {

    delay(200);
    buttonState = !buttonState;
  } // END IF HERE ...

  if (buttonState == true)
  {
    fadeIn();
  }
  else
  {
    fadeOut();
  }


  analogWrite(LED_PIN, fadeVal);
  delay(20);


}

void fadeIn()
{
  if (fadeVal < 255) {
    fadeVal++;
    analogWrite(LED_PIN, fadeVal);
    delay(20);
  }
}

void fadeOut()
{
  if (fadeVal>0) {
    fadeVal--;
    analogWrite(LED_PIN, fadeVal);
    delay(20);
  }
}
