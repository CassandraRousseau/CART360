//pitch shifter test 2

//Buzzer
#define buzzer 9
//Button
#define buttonPin 2

//Flex sensor
#define flexPin A0

//Music loop
bool isBuzzing = false;

//music tone
int currentTone = 100;


//Variable to read the flexion
int flex = 0;
int flexReading = abs(flex);

//Sets flexions
int noFlexion = 0;
//
int lightFlexion = 300;
//
int mediumFlexion = 500;
//
int highFlexion = 900;

//Modes
int mode = 0; //1,2,3; 0==off

// distance and music duration variables will change:
int duration, cm;

//Sets the pins
void setup() {
  Serial.begin(9600);
  // Sets pins
  pinMode(buttonPin, INPUT);
  pinMode(flexPin, INPUT);
  pinMode(buzzer, OUTPUT);

}

//Sets the voids
void loop() {
  Serial.println(flexReading);
  flexReading =  analogRead(flexPin);
  chooseMode();
  selectMode();
}
void chooseMode() {
  //  Changes mode each time the mode button is pressed
  //Goes from mode 0(reset) to mode 1
  if (digitalRead(buttonPin) == HIGH) {
    if (mode == 0) {
      mode = 1;
      delay(100);
    }
    //Goes from mode 1 to mode 0
    else if (mode == 1) {
      mode = 0;
      delay(100);
    }
  }

}
void selectMode()
{
  //  Sets the void used in the modes
  if (mode == 0) {
    reset();
  }
  else if (mode == 1) {
    checkTone();
    checkFlexion();
  }
}

void reset()
//Stops the music loop and sensor to work
{
  if ( flexReading >= noFlexion) {
    noTone(buzzer);
    isBuzzing = false;
    Serial.print("Working ");
  }
}
//Sets tone
void checkTone() {
  if (digitalRead(buttonPin) == HIGH) {
    currentTone += 100;

    if (currentTone >= 1200) {
      currentTone = 50;
    }
  }
}
//Check pressure
void checkFlexion() {
  //Duration depends on flex sensor input
  //Converts distance to music duration
  //Converts tone depending on the flexion applied
  currentTone = map(flexReading, 0, 1023, noFlexion, lightFlexion) * 5;
  //changes pitch based on flexion
  if ( flexReading >= noFlexion && flexReading <= lightFlexion) {
    // Buzz
    tone(buzzer, currentTone);
    isBuzzing = true;
  } else if (flexReading >= lightFlexion && flexReading <= mediumFlexion) {
    // Buzz
    tone(buzzer, currentTone);
    isBuzzing = true;

  } else if (flexReading >= mediumFlexion && flexReading <= highFlexion) {
    // Buzz
    tone(buzzer, currentTone);
    isBuzzing = true;
  }
  else { // Don't buzz
    noTone(buzzer);
    isBuzzing = false;

  }

  // Print the flexion
  Serial.print("Flexion: ");
  Serial.print(flexReading);
  Serial.print("degree");
  Serial.println();

  delay(200);

}
