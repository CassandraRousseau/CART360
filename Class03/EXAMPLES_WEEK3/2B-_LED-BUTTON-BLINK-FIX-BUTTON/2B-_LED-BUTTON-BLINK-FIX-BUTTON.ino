// 2 : Trigger on with button
#define LED_PIN 11
#define BUTTON_PIN 2
boolean buttonState =false;
boolean prevButtonState =true;

 // NEW:: prevButtonVal test ->
 /* IF we are pressing and if buttonState is true and previously was true: 
  *  - this means we are still pressing
  *  so we don't change the buttonState - rather we leave it.
  *  WHEN the buttonVal is not HIGH we make previous State  == to NOT buttonState (as it should now switch)
  *  when we press Button again */

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  //Serial.begin(9600);
}

void loop()
{
  int buttonVal = digitalRead(BUTTON_PIN); // read value from button
 //Serial.println(buttonVal);
 
  if(buttonVal == HIGH)
  {
   // if we are changing state
   if(buttonState != prevButtonState)
   {
    delay(200);
    buttonState = ! buttonState;
    prevButtonState = buttonState;
   }
    
  }
  // switch the prev state to be the OPPOSITE of button state
  // when buttonVal is LOW...
  else
  {
    prevButtonState =!buttonState;
  }
   

  if(buttonState ==true)
  {
    digitalWrite(LED_PIN,HIGH);
  }
  else
  {
    digitalWrite(LED_PIN,LOW);
  }
  
}
