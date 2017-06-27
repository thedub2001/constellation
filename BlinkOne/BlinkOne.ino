const int TminBlink = 10;
const int TmaxBlink = 150;
const int TminLong = 2000;
const int TmaxLong = 5000;
const int ledStates[8]={0,40,10,40,30,20,60,50};
int blinks = 0;
int lapse=100;
int erratic=0;

// constants won't change. Used here to set a pin number :
const int ledPin =  8;      // the number of the LED pin


unsigned long previousMillis = 0;        // will store last time LED was updated

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= lapse) {
    previousMillis = currentMillis;

      if (erratic) {
        lapse=random(TminBlink, TmaxBlink);
        int led=random(8);
      analogWrite(ledPin, ledStates[led]);
        erratic--;
      } else {
        lapse=random(TminLong, TmaxLong);
        int led=random(2);
        digitalWrite(ledPin, ledStates[led]);
        erratic=random(10,40);
      }
      }
}
