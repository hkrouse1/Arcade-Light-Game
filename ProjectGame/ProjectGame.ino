#include <Adafruit_CircuitPlayground.h>

int score = 0;
int value;
int touch;
int j=0;
int g=0;
int k=0;
int litLed = 0;
int litLed2 = 0;
int litLed3 =0;
int leftButton = 4;
volatile bool buttonFlag = false;
const int tThreshold = 1015;
float midi[127];
int A_four = 440;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
CircuitPlayground.begin();
CircuitPlayground.readCap(6);
pinMode(leftButton, INPUT_PULLDOWN);
attachInterrupt(digitalPinToInterrupt(leftButton), Button, RISING);
generateMIDI();
}

void loop() {
  // put your main code here, to run repeatedly:
gameloop();


}

void gameloop(){
  CircuitPlayground.clearPixels();
  touch = CircuitPlayground.readCap(6);

  for (int i=0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 255);
    delay(1000);
    CircuitPlayground.clearPixels();
    j++; 
  }
  if (buttonFlag && litLed == 8 && touch >= tThreshold){
      CircuitPlayground.playTone(midi[64], 200);
      score = 1;
      litLed = 0;
      for (int i=0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
      delay(500);
      CircuitPlayground.clearPixels();
      g++;
      }
    }else{
      CircuitPlayground.playTone(midi[104], 200);
      delay(10);
      Serial.println("You lose. Your score was");
      Serial.println(score);
      score = 0;
    }
  if (buttonFlag && litLed2 == 8 && touch >= tThreshold){
        CircuitPlayground.playTone(midi[64], 200);
        score = 2;
        litLed2 = 0;
        for (int i=0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
        delay(250);
        CircuitPlayground.clearPixels();
        k++;
      }
    }else{
      CircuitPlayground.playTone(midi[104], 200);
      Serial.println("You lose. Your score was");
      Serial.println(score);
      score = 0;
    }

  if (buttonFlag && litLed3 == 8 && touch >= tThreshold){
        CircuitPlayground.playTone(midi[64], 200);
        score = 3;
        litLed3 = 0;
        for (int i=0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 0, 255);
        delay(100);
        CircuitPlayground.clearPixels();
      }
    }else{
      CircuitPlayground.playTone(midi[104], 200);
      Serial.println("You lose. Your score was");
      Serial.println(score);
      score = 0; 
    }


j = 0;
g = 0;
k = 0;
buttonFlag = false;
litLed = 0;
litLed2 = 0;
litLed3 =0;
}


void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}


void Button(){
buttonFlag = true;
litLed = j-1;
litLed2 = g-1; 
litLed3 = k-1;
}
