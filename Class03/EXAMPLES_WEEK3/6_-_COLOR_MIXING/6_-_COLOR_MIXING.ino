/*
 * ACTIVE LOW
  SparkFun Inventor's Kit
  Example sketch 03

  RGB LED

  Make an RGB LED display a rainbow of colors!

  Hardware connections:

  An RGB LED is actually three LEDs (red, green, and blue) in
  one package. When you run them at different brightnesses,
  the red, green and blue mix to form new colors.

  Starting at the flattened edge of the flange on the LED,
  the pins are ordered RED, COMMON, GREEN, BLUE.

  Connect RED to a 330 ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 9.

  Connect COMMON pin to GND.

  Connect GREEN to a 330 ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 10.

  Connect BLUE to a 330 ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 11.

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.

  Version 2.0 6/2012 MDG
*/


// First we'll define the pins by name to make the sketch
// easier to follow.

// Here's a new trick: putting the word "const" in front of a
// variable indicates that this is a "constant" value that will
// never change. (You don't have to do this, but if you do, the
// Arduino will give you a friendly warning if you accidentally
// try to change the value, so it's considered good form.)

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// This variable controls how fast we loop through the colors.
// (Try changing this to make the fading faster or slower.)

const int DISPLAY_TIME = 10;  // In milliseconds


void setup()
{
  // Here we'll configure the Arduino pins we're using to
  // drive the LED to be outputs:

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void loop()
{
  

  // We've written a function called mainColors() that steps
  // through all eight of these colors. We're only "calling" the
  // function here (telling it to run). The actual function code
  // is further down in the sketch.
   // The above function turns the individual LEDs full-on and
  // full-off. If you want to generate more than eight colors,
  // you can do so by varying the brightness of the individual
  // LEDs between full-on and full-off.
   // The analogWrite() function lets us do this. This function
  // lets you dim a LED from full-off to full-on over 255 steps.

 mainColors();

 

 

  // We've written a function called showSpectrum() that smoothly
  // steps through all the colors. 

  showSpectrum();
}


/**** mainColors() *******/

void mainColors()
{
  // Off (all LEDs off):




  delay(1000);

  // Red (turn just the red LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Green (turn just the green LED on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Blue (turn just the blue LED on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Yellow (turn red and green on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Cyan (turn green and blue on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Purple (turn red and blue on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // White (turn all the LEDs on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);
}


// Below are two more functions we've written,
// showSpectrum() and showRGB().



// This function steps through all the colors of the RGB LED.
// It does this by stepping a variable from 0 to 768 (the total
// number of colors), and repeatedly calling showRGB() to display
// the individual colors.

/**** showSpectrum() *******/
void showSpectrum()
{


  // Now we'll use a for() loop to make x count from 0 to 767

  for (int x = 0; x < 768; x++)
  {
    showRGB(x);  // Call RGBspectrum() with our new x
    delay(DISPLAY_TIME);   // Delay for 10 ms (1/100th of a second)
  }
}


// showRGB()

// This function translates a number between 0 and 767 into a
// specific color on the RGB LED. If you have this number count
// through the whole range (0 to 767), the LED will smoothly
// change color through the entire spectrum.

// The "base" numbers are:
// 0   = pure red
// 255 = pure green
// 511 = pure blue
// 767 = pure red (again)

// Numbers between the above colors will create blends. For
// example, 640 is midway between 512 (pure blue) and 767
// (pure red). It will give you a 50/50 mix of blue and red,
// resulting in purple.

// If you count up from 0 to 767 and pass that number to this
// function, the LED will smoothly fade between all the colors.
// (Because it starts and ends on pure red, you can start over
// at 0 without any break in the spectrum).


void showRGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  // Here we'll use an "if / else" statement to determine which
  // of the three (R,G,B) zones x falls into. Each of these zones
  // spans 255 because analogWrite() wants a number from 0 to 255.

  // In each of these zones, we'll calculate the brightness
  // for each of the red, green, and blue LEDs within the RGB LED.

  if (color <= 255)          // zone 1
  {
    redIntensity = color;    // red goes from on to off (255-0),255-1,255-2 ...)
    greenIntensity = 255-color;        // green goes from off to on
    blueIntensity = 255;             // blue is always off
  }
  else if (color <= 511)     // zone 2
  {
    redIntensity = 255;                     // red is always off
    greenIntensity =  (color % 256); // green on to off (color%256) == 0,1,2,3,4,5 .... 
    blueIntensity = 255-(color % 256);        // blue off to on 0,1,2, ... 
  }
  else // color >= 512       // zone 3
  {
    redIntensity = 255-(color % 512);         // red off to on (0-255)
    greenIntensity = 255;                   // green is always off
    blueIntensity = (color % 512);  // blue on to off (color%512) == 0,1,2,3,4,5 .... (up to 255 remainder)
  }

  // Now that the brightness values have been set, command the LED
  // to those values

  analogWrite(RED_PIN, redIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
}
