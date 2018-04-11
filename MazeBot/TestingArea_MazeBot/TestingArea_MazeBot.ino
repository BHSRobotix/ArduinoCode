#include <Servo.h>

Servo servoL;
Servo servoR;
//Front Sonar is pin 2
//Right Sonar is pin 4
const int pingPinF = 2;
const int pingPinR = 4;
const int pingPinL = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  servoL.attach(7);
  servoR.attach(0);

}

void loop() {
        servoR.write(180);
        servoL.write(140);
  // put your main code here, to run repeatedly:

}
