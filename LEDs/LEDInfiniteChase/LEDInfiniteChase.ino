/*
 * CHASE classes that infinitely chase colors in different orders of colors A and B.
 * "Mid" classes start the chase from the middle of the LED strip and extend outward.
 * AABB
 * ABBB
 * midAABB
 * midABBB
 */

#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9800);
  strip.begin();
  strip.show(); 

}

void loop() {

//COLORS
  uint32_t red = strip.Color(255, 0, 0); 
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t purple = strip.Color(255, 0, 255);
  uint32_t white = strip.Color(50, 50, 50);
  uint32_t black = strip.Color(0, 0, 0);

  Serial.print(purple);
  ABBBChase(blue, black, 85);
}

static void AABBChase(uint32_t c1, uint32_t c2, int speed){
// Creates an A-A-B-B pattern.

for(int i=0; i<4; i++){ 
  strip.setPixelColor(i-3,  c1);
  strip.setPixelColor(i-2,  c1);
  strip.setPixelColor(i-1,  c2);
  strip.setPixelColor(i+0,  c2);
  strip.setPixelColor(i+1,  c1);
  strip.setPixelColor(i+2,  c1);
  strip.setPixelColor(i+3,  c2);
  strip.setPixelColor(i+4,  c2);
  strip.setPixelColor(i+5,  c1);
  strip.setPixelColor(i+6,  c1);
  strip.setPixelColor(i+7,  c2);
  strip.setPixelColor(i+8,  c2);
  strip.setPixelColor(i+9,  c1);
  strip.setPixelColor(i+10, c1);
  strip.setPixelColor(i+11, c2);
  strip.setPixelColor(i+12, c2);
  strip.setPixelColor(i+13, c1);
  strip.setPixelColor(i+14, c1);
  strip.setPixelColor(i+15, c2);
  strip.setPixelColor(i+16, c2);
  strip.setPixelColor(i+17, c1);
  strip.setPixelColor(i+18, c1);
  strip.setPixelColor(i+19, c2);
  strip.setPixelColor(i+20, c2);
  strip.setPixelColor(i+21, c1);
  strip.setPixelColor(i+22, c1);
  strip.setPixelColor(i+23, c2);
  strip.setPixelColor(i+24, c2);
  strip.setPixelColor(i+25, c1);
  strip.setPixelColor(i+26, c1);
  strip.setPixelColor(i+27, c2);
  strip.setPixelColor(i+28, c2);
  strip.setPixelColor(i+29, c1);
  
  strip.show();
  delay(speed); //higher number = lower speed
  }
}

static void ABBBChase(uint32_t c1, uint32_t c2, int speed){
// Creates an A-B-B-B pattern.

for(int i=0; i<4; i++){ 
  strip.setPixelColor(i-3,  c1);
  strip.setPixelColor(i-2,  c2);
  strip.setPixelColor(i-1,  c2);
  strip.setPixelColor(i+0,  c1);
  strip.setPixelColor(i+1,  c2);
  strip.setPixelColor(i+2,  c2);
  strip.setPixelColor(i+3,  c1);
  strip.setPixelColor(i+4,  c2);
  strip.setPixelColor(i+5,  c2);
  strip.setPixelColor(i+6,  c1);
  strip.setPixelColor(i+7,  c2);
  strip.setPixelColor(i+8,  c2);
  strip.setPixelColor(i+9,  c1);
  strip.setPixelColor(i+10, c2);
  strip.setPixelColor(i+11, c2);
  strip.setPixelColor(i+12, c1);
  strip.setPixelColor(i+13, c2);
  strip.setPixelColor(i+14, c2);
  strip.setPixelColor(i+15, c1);
  strip.setPixelColor(i+16, c2);
  strip.setPixelColor(i+17, c2);
  strip.setPixelColor(i+18, c1);
  strip.setPixelColor(i+19, c2);
  strip.setPixelColor(i+20, c2);
  strip.setPixelColor(i+21, c1);
  strip.setPixelColor(i+22, c2);
  strip.setPixelColor(i+23, c2);
  strip.setPixelColor(i+24, c1);
  strip.setPixelColor(i+25, c2);
  strip.setPixelColor(i+26, c2);
  strip.setPixelColor(i+27, c1);
  strip.setPixelColor(i+28, c2);
  strip.setPixelColor(i+29, c2);
  
  strip.show();
  delay(speed);
  }
}

static void midAABBChase(uint32_t c1, uint32_t c2, int speed){
// Creates a center origin AABB pattern.

for(int i=0; i<4; i++){ 
//Set 1
if(i==0){
  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 2
if (i==1){

  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 3
if (i==2){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}
//Set 4
if(i==3){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
    }
  }
}

static void midABBBChase(uint32_t c1, uint32_t c2, int speed){
// Creates a center origin ABBB pattern.

for(int i=0; i<4; i++){ 
//Set 1
if(i==0){
  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 2
if (i==1){

  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 3
if (i==2){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}
//Set 4
if(i==3){
  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
    }
  }
}

static void midShuffleChase(uint32_t c1, uint32_t c2, int speed){
// Creates a center origin AABB pattern.

for(int i=0; i<8; i++){ 
//Set 1
if(i==0){
  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 2
if (i==1){

  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
//Set 3
if (i==2){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}
//Set 4
if(i==3){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c2);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c2);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c2);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c2);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c2);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c2);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
    }
//Set 5
if(i==4){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c1);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c1);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c1);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c1);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c1);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c1);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c1);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c1);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}

//Set 6
if(i==5){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c2);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c2);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c2);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c2);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c2);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c2);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c2);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c2);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}

//Set 7
if(i==6){
  strip.setPixelColor(0,  c1);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c1);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c1);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c1);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c1);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c1);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c1);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c1);
  
  strip.show();
  delay(speed);
}

//Set 8
if(i==7){
  strip.setPixelColor(0,  c2);
  strip.setPixelColor(1,  c2);
  strip.setPixelColor(2,  c1);
  strip.setPixelColor(3,  c1);
  strip.setPixelColor(4,  c2);
  strip.setPixelColor(5,  c2);
  strip.setPixelColor(6,  c1);
  strip.setPixelColor(7,  c1);
  strip.setPixelColor(8,  c2);
  strip.setPixelColor(9,  c2);
  strip.setPixelColor(10, c1);
  strip.setPixelColor(11, c1);
  strip.setPixelColor(12, c2);
  strip.setPixelColor(13, c2);
  strip.setPixelColor(14, c1);
  // --------------ORIGIN------------------
  strip.setPixelColor(15, c1);
  strip.setPixelColor(16, c2);
  strip.setPixelColor(17, c2);
  strip.setPixelColor(18, c1);
  strip.setPixelColor(19, c1);
  strip.setPixelColor(20, c2);
  strip.setPixelColor(21, c2);
  strip.setPixelColor(22, c1);
  strip.setPixelColor(23, c1);
  strip.setPixelColor(24, c2);
  strip.setPixelColor(25, c2);
  strip.setPixelColor(26, c1);
  strip.setPixelColor(27, c1);
  strip.setPixelColor(28, c2);
  strip.setPixelColor(29, c2);
  
  strip.show();
  delay(speed);
}
  }
}
