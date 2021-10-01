/* thank you spark fun experiment */

#define BUZZER_PIN 2
#define SONG_LENGTH 18
#define BUTTON_ARR_SIZE 4
#define NUM_NOTES 4


int button_pins[BUTTON_ARR_SIZE] = {7,8,9,10}; // to hold pin numbers
int frequencies[NUM_NOTES] = { 392, 440, 494, 523 };//possible freqs
int duration =32;


void setup() {

  pinMode(BUZZER_PIN, OUTPUT);
  //go through each button pin and set mode
  for(int i=0; i< BUTTON_ARR_SIZE; i++){
      pinMode(button_pins[i], INPUT);
  }
  Serial.begin(9600);
  

}

void loop() {

  for(int i=0;i<BUTTON_ARR_SIZE;i++){
    
    if(digitalRead(button_pins[i])==HIGH){
      tone(BUZZER_PIN,frequencies[i],duration);
     // Serial.println(i);
      
    }
  }
  

}
