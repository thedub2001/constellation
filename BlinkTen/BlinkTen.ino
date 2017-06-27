// Commons parameters to configure for changing the behaviors of leds

const int TminBlink = 10; // Minimum time interval for erratic mode
const int TmaxBlink = 150; // Maximum time interval for erratic mode
const int TminLong = 2000; // Minimum time interval for HIGH or LOW mode
const int TmaxLong = 5000; // Maximum time interval for HIGH or LOW mode
const int ledStates[8]={0,255,10,40,30,20,60,50}; //authorized states for the led during the erratic period with { led[0]=LOW and led[1]=HIGH }

// Parameters for each led
int lapse[10]={0,200,400,600,800,900,1000,1200,1400,1600}; // Lapse time before changing LED state (Initialy differents to desinchronize the LEDs at startup)
int erratic[10]={0,0,0,0,0,0,0,0,0,0}; // Number of steps before leaving erratic mode
const int ledPin[10] ={2,3,4,5,6,7,8,9,10,11}; // LED pins
unsigned long previousMillis[10] = {0,0,0,0,0,0,0,0,0,0};  // Last time LED was updated

void setup() {
  // set all the digital pins as output:
  for (int i=0;i<10;i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {

    unsigned long currentMillis = millis();
    
    for (int i=0;i<10;i++) { // Loop over the 10 leds
      
      if (currentMillis - previousMillis[i] >= lapse[i]) {
      previousMillis[i] = currentMillis;
  
        if (erratic[i]) { // If erratic mode still have steps to complish
          lapse[i]=random(TminBlink, TmaxBlink);
          int led=random(8);
          analogWrite(ledPin[i], ledStates[led]);
          erratic[i]--;
        } else { // between each erratic mode the LED is HIGH or LOW during a Long period
          lapse[i]=random(TminLong, TmaxLong);
          int led=random(2); // { led[0]=LOW and led[1]=HIGH }
          digitalWrite(ledPin[i], ledStates[led]);
          erratic[i]=random(10,40); // Initialise the number of steps of the next erratic mode
        }
      }
    }
   
}
