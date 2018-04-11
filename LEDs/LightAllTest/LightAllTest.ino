
#include <Adafruit_NeoPixel.h>
 
#define PIN      6
#define N_LEDS 30
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.show();
}
 
void loop() {
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t yellow = strip.Color(255, 150, 0);
  
  uint32_t orange = strip.Color(255, 50, 0);
  uint32_t pink = strip.Color(255, 0, 150);
  uint32_t cyan = strip.Color(0, 255, 150);
  uint32_t red = strip.Color(255, 0, 0);
  
  uint32_t white = strip.Color(50, 50, 50);
  uint32_t black = strip.Color(0, 0, 0);
  
  lightAll(red);
  delay(400);
  lightAll(green);
  delay(400);
  lightAll(white);
  delay(400);
}

static void lightAll(uint32_t c){
  for(uint16_t i=0; i<N_LEDS; i++){
    strip.setPixelColor(i, c);
    strip.show();
  }
  
}

