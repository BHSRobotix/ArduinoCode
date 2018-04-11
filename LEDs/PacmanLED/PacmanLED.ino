#include <Adafruit_NeoPixel.h>
 
#define PIN    6
#define N_LEDS 30 //number of LEDs on strip
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin(); 
  strip.show();  // Initialize all pixels to 'off'

}
 
void loop() {

  uint32_t green = strip.Color(0, 255, 0); // (Red, Green, Blue)
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t yellow = strip.Color(255, 150, 0);
  
  uint32_t orange = strip.Color(255, 50, 0);
  uint32_t pink = strip.Color(255, 0, 150);
  uint32_t cyan = strip.Color(0, 255, 150);
  uint32_t red = strip.Color(255, 0, 0);
  
  uint32_t white = strip.Color(50, 50, 50);
  uint32_t black = strip.Color(0, 0, 0);
  
  for (uint16_t i=0; i<N_LEDS; i++){ //makes entire strip white
    strip.setPixelColor(i, white);
  }
  strip.show();

  chase(yellow, black, black, pink, cyan, orange, red); 
  strip.show();
  
}

static void chase(uint32_t c1, uint32_t c2, uint32_t c3, uint32_t c4, uint32_t c5, uint32_t c6, uint32_t c7){ //Chase code for 7 colored pixels in a row
  for (uint16_t i=0; i<N_LEDS+7; i++) {
    strip.setPixelColor(i, c1);
    strip.setPixelColor(i-1, c2);
    strip.setPixelColor(i-2, c3);
    strip.setPixelColor(i-3, c4);
    strip.setPixelColor(i-4, c5);
    strip.setPixelColor(i-5, c6);
    strip.setPixelColor(i-6, c7);
    
    strip.setPixelColor(i-7, 0); //Makes 8th pixel black
    
    
    if (i!=28 && i!=29 && i!=30 && i!=31 && i!=32 && i!=33 && i!=34 && i!=35 && i!=36) {
       strip.setPixelColor(28, strip.Color(50, 50, 50));
       strip.setPixelColor(29, strip.Color(50, 50, 50));
    }
    strip.show();
    delay(100); //Speed of pixels (high speed = low delay)
  }
  delay(200); //delay after chase loop is finished
  
//  for (uint16_t i=0; i<N_LEDS+1; i++) {
//    strip.setPixelColor(i , c2);
//    strip.setPixelColor(i-1, c1);
//    strip.setPixelColor(i-2, 0);
//    if (i!=28&&i!=29&&i!=30) {
//       strip.setPixelColor(29, 0);
//       strip.setPixelColor(28, 0);
//    }
//    strip.show();
//    delay(200);
//  }

  
//  chase(strip.Color(255, 0, 0)); // Red
//  chase(strip.Color(0, 255, 0)); // Green
//  chase(strip.Color(0, 0, 255)); // Blue
}
 
//static void chase(uint32_t c) {
//  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
//      strip.setPixelColor(i  , c); // Draw new pixel
//      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
//      strip.show();
//      delay(25);
//  }
//}
