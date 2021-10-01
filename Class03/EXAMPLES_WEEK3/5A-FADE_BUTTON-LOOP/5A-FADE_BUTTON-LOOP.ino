#define LED_PIN 11
#define BUTTON_PIN 2
boolean buttonState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin (9600); // show with serial ... the unresponsiveness

}

void loop() {
  int buttonVal = digitalRead(BUTTON_PIN); // read value from button
  Serial.println(buttonVal);

  //chack button state first..
  if (buttonVal == HIGH) {
    //ALL OF THIS COMES WHEN BUTTON IS PRESSED
    buttonState = !buttonState; //switch button state

    if (buttonState == true)
    {
      fadeIn();
    }
    else
    {
      fadeOut();
    }
  }//***if button state == high

}

void fadeIn()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(LED_PIN, i);   //write val to LED
    delay(20);

  }
}

void fadeOut()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(LED_PIN, i);   //write val to LED
    delay(20);

  }
}
