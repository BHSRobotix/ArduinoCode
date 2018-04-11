#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#define PIN 6
#define N_LEDS 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

const int buttonPin = 1;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  //COLORS
  uint32_t red = strip.Color(255, 0, 0);
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t purple = strip.Color(255, 0, 255);
  uint32_t pink = strip.Color(244, 66, 241);
  uint32_t white = strip.Color(50, 50, 50);
  uint32_t black = strip.Color(0, 0, 0);

  if (buttonState == HIGH) {
    Serial.println("Blue");
    
    ABBBChase(blue, black, 100);
  }
    else if (buttonState == LOW) {
      Serial.println("Red");
      
      ABBBChase(red, black, 100);
    }

}

static void ABBBChase(uint32_t c1, uint32_t c2, int speed){
// Creates an A-B-B-B pattern.

for(int i=0; i<4; i++){ 
  strip.setPixelColor(i-3,  c1);
  strip.setPixelColor(i-2,  c2);
  strip.setPixelColor(i-1,  c2);
  strip.setPixelColor(i+0,  c2);
  strip.setPixelColor(i+1,  c1);
  strip.setPixelColor(i+2,  c2);
  strip.setPixelColor(i+3,  c2);
  strip.setPixelColor(i+4,  c2);
  strip.setPixelColor(i+5,  c1);
  strip.setPixelColor(i+6,  c2);
  strip.setPixelColor(i+7,  c2);
  strip.setPixelColor(i+8,  c2);
  strip.setPixelColor(i+9,  c1);
  strip.setPixelColor(i+10, c2);
  strip.setPixelColor(i+11, c2);
  strip.setPixelColor(i+12, c2);
  strip.setPixelColor(i+13, c1);
  strip.setPixelColor(i+14, c2);
  strip.setPixelColor(i+15, c2);
  strip.setPixelColor(i+16, c2);
  strip.setPixelColor(i+17, c1);
  strip.setPixelColor(i+18, c2);
  strip.setPixelColor(i+19, c2);
  strip.setPixelColor(i+20, c2);
  strip.setPixelColor(i+21, c1);
  strip.setPixelColor(i+22, c2);
  strip.setPixelColor(i+23, c2);
  strip.setPixelColor(i+24, c2);
  strip.setPixelColor(i+25, c1);
  strip.setPixelColor(i+26, c2);
  strip.setPixelColor(i+27, c2);
  strip.setPixelColor(i+28, c2);
  strip.setPixelColor(i+29, c1);
  
  strip.show();
  delay(speed);
  }
}
