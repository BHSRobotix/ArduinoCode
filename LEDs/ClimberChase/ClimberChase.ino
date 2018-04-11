#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int chaseOffset = 0;

void setup() {
  Serial.begin(9800);
  strip.begin();
  strip.show(); 

}

void loop() {

String climbing = "true ";

  uint32_t red = strip.Color(255, 0, 0);    //COLORS
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t purple = strip.Color(255, 0, 255);
  uint32_t white = strip.Color(50, 50, 50);
  uint32_t black = strip.Color(0, 0, 0);


  int r = 255;
  int b = 0;
  
  for(int i = 0; i < N_LEDS; i++){       //Resets the full LED strip...
    strip.setPixelColor(i,0,0,0);                   //...by setting each LED to black
  }
  
  if(climbing == "true "){                          //If the robot is climbing, make the LEDs climb upward
    for(int i = chaseOffset; i < N_LEDS; i = i+3){      //Lights up one side with Leds moving down the strip in yellow
        strip.setPixelColor(i,255,255,0);
    }
  }
 strip.show();
 
 if(chaseOffset == 2){ 
    chaseOffset = 0;                               
  }else{
    chaseOffset++;
  }
  delay(100);
  
}

