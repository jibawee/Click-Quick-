#include <AsyncDelay.h>
#include <Adafruit_CircuitPlayground.h>


int count = 60;
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
  Serial.println('\n');
}


void loop(void)
  {

  if(buttFlag){
    delay(5);
    ++points;
    Serial.print(points);
    Serial.println(" points!");
    Serial.println('\n');
    Serial.print(count);
    Serial.println(" seconds");
    Serial.println('\n');
    buttFlag=0;
  }
    if(switchFlag)
    {
      delay(5);
      switchVal = digitalRead(switchPin);
      delay_1s.start(1000, AsyncDelay::MILLIS);
      switchFlag = 0;
      points = 0;
      count = 60;
      CircuitPlayground.clearPixels();
      delay_1s.repeat();
    }
  
  if (delay_1s.isExpired() && !switchVal)
    { --count;
      Serial.print(count);
      Serial.println(" seconds");
      Serial.println('\n');
      
      delay_1s.repeat(); // Count from when the delay expired, not now
      }
      if (count < 0){
      delay_1s.start(1000, AsyncDelay::MILLIS);
      Serial.println("Time's up!");
      Serial.println('\n');
      count = 0;
      CircuitPlayground.clearPixels();
      }
      if (points == 72){
        CircuitPlayground.playTone(300, 100);
        for (int i = 0; i < 1; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 40){
        CircuitPlayground.playTone(350, 100);
        for (int i = 0; i < 2; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 80){
        CircuitPlayground.playTone(400, 100);
        for (int i = 0; i < 3; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 120){
        CircuitPlayground.playTone(450, 100);
        for (int i = 0; i < 4; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 160){
        CircuitPlayground.playTone(500, 100);
        for (int i = 0; i < 5; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
            if (points == 200){
        CircuitPlayground.playTone(550, 100);
        for (int i = 0; i < 6; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
       if (points == 240){
        CircuitPlayground.playTone(600, 100);
        for (int i = 0; i < 7; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 280){
        CircuitPlayground.playTone(650, 100);
        for (int i = 0; i < 8; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
       if (points == 320){
        CircuitPlayground.playTone(700, 100);
        for (int i = 0; i < 9; i++) {
        CircuitPlayground.setPixelColor(i, 255, 0, 255);
        }
        CircuitPlayground.playTone(0, 0);
      }
      if (points == 360){
        CircuitPlayground.playTone(300, 200);
        CircuitPlayground.playTone(300, 100);
        CircuitPlayground.playTone(300, 100);
        CircuitPlayground.playTone(450, 200);
        for(int i=0; i<10; i++) {
    CircuitPlayground.strip.setPixelColor(random(10), CircuitPlayground.strip.Color(random(255), 0, 255));
    CircuitPlayground.strip.show();
    delay(50);
    points = 0;
      }

    }

  }


void slideswitch()
{
  switchFlag = 1;// or true
  //state = !state;
}

void leftbutt(){
  buttFlag = 1;// or true
}
