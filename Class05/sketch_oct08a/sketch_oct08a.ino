int const MAX_SAMPLE=128;
int const PC_PINS[]={0,1,2,3,4,5};

void setup() {
    Serial.begin(57600);
}
long average(int pina){
  long _t=-1;
  for(int i=0; i<MAX_SAMPLE;i++){
    _t+=analogRead(pina);
    delay(2);}
    _t=(_t/MAX_SAMPLE);
  return (_t);}
void loop() {
  long reading = average(PC_PINS[0]);
  analogWrite(11, reading/4);
  float voltage =(reading/1024.0)*5.0;
  Serial.println(voltage);
}
