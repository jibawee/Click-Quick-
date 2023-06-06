#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>


int count = 0;
int switchPin = 7;
volatile bool switchFlag = 0;
bool switchVal = 0;
bool slideSwitch;
int points = 0;

volatile bool buttFlag = 0;
volatile byte state = LOW;


AsyncDelay delay_1s;
 

void setup(void)
{
  CircuitPlayground.begin();
  pinMode(switchPin,INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(4), leftbutt, RISING);
  attachInterrupt(digitalPinToInterrupt(7), slideswitch , CHANGE);


  delay_1s.start(1000, AsyncDelay::MILLIS);
  Serial.begin(9600);
  while(!Serial)
  Serial.println("Starting timers");
}


void loop(void)
  {

  if(buttFlag){
    delay(5);
    Serial.println(points);
    Serial.print("points!");
    delay_1s.start(1000, AsyncDelay::MILLIS);
    buttFlag=0;
  }
    if(switchFlag)
    {
      delay(5);
      switchVal = digitalRead(switchPin);
      delay_1s.start(1000, AsyncDelay::MILLIS);
      switchFlag = 0;
    }
  
  if (delay_1s.isExpired() && !switchVal)
    {
      Serial.println(count);
      Serial.print(" seconds left:");
      count++;
      delay_1s.repeat(); // Count from when the delay expired, not now
    }
    if (count > 60){
    delay_1s.start(1000, AsyncDelay::MILLIS);
    Serial.println("Time's up!");
    count = 0;

    }
  }


void slideswitch()
{
  switchFlag = 1;// or true
  //state = !state;
}

void leftbutt(){
  buttFlag = 1;
}
