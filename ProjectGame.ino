#include <Adafruit_CircuitPlayground.h>

int score = 0;
int value;
int touch;
int j=0;
int g=0;
int k=0;
int h=0;
int litLed = 0;
int litLed2 = 0;
int litLed3 =0;
int litLed4 =0;
int leftButton = 4;
volatile bool buttonFlag = false;
const int tThreshold = 1015;
float midi[127];
int A_four = 440;

const uint8_t spYOU_WIN[]           PROGMEM ={0x26,0x2B,0x82,0x54,0x76,0x4B,0xA7,0x76,0x04,0x14,0xB6,0xBA,0x5D,0xBA,0x9E,0x48,0x30,0xEA,0xD6,0x69,0x6A,0x73,0x01,0xF7,0xB7,0xA7,0x6A,0xAD,0x0C,0x0C,0xFB,0x8F,0x2C,0x5A,0x55,0x2D,0xFD,0x52,0x62,0x6E,0xBA,0x06,0xA5,0x59,0x8E,0x72,0x1C,0x13,0x97,0x31,0xF7,0x61,0x2C,0x4D,0x5B,0x6E,0x64,0x8E,0x19,0x66,0x3D,0x55,0x16,0x9E,0x56,0xD8,0xF5,0xD4,0x35,0xA6,0x6A,0xC8,0x9A,0xDB,0xDC,0xF6,0xB6,0xB7,0x4D,0x9D,0xB4,0x66,0xEE,0xDE,0xD8,0xB7,0xAA,0xA5,0xC1,0xC2,0xB2,0x22,0xAB,0x86,0x7A,0x2F,0x8D,0x91,0x2D,0x6A,0x94,0x23,0x3D,0xDB,0x8E,0xA8,0xB0,0xCB,0x4E,0x2B,0x39,0x0F,0x00,0x00};



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
        delay(125);
        CircuitPlayground.clearPixels();
        h++;
      }
    }else{
      CircuitPlayground.playTone(midi[104], 200);
      Serial.println("You lose. Your score was");
      Serial.println(score);
      score = 0; 
    }
  if (buttonFlag && litLed4 == 8 && touch >= tThreshold){
      score = 4;
      CircuitPlayground.speaker.say(spYOU_WIN);
      delay(10);
      CircuitPlayground.playTone(midi[64], 200);
      delay(1);

      CircuitPlayground.playTone(midi[56], 200);
      delay(1);

      CircuitPlayground.playTone(midi[59], 200);
      delay(1);

      CircuitPlayground.playTone(midi[64], 200);
      delay(1);

      CircuitPlayground.playTone(midi[64], 200);
      delay(1);

      CircuitPlayground.playTone(midi[67], 200);
      delay(1);

      CircuitPlayground.playTone(midi[68], 200);
      delay(1);

      CircuitPlayground.playTone(midi[65], 200);
      delay(1);

      CircuitPlayground.playTone(midi[64], 200);
      delay(1);

      CircuitPlayground.playTone(midi[64], 200);
      delay(1);

      CircuitPlayground.playTone(midi[62], 200);
      delay(1);

      CircuitPlayground.playTone(midi[63], 200);
      delay(1);

      CircuitPlayground.playTone(midi[60], 200);
      delay(1);
      Serial.println("You won here is your score:");
      Serial.println(score);
    }else{
      CircuitPlayground.playTone(midi[104], 200);
      Serial.println("You lose. Your score was");
      Serial.println(score);
      score = 0;
    }

j = 0;
g = 0;
k = 0;
h = 0;
buttonFlag = false;
litLed = 0;
litLed2 = 0;
litLed3 =0;
litLed = 0;
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
litLed4 = h-1;
}
