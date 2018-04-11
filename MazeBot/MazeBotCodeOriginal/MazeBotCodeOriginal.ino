#include <Servo.h>

Servo servoL;
Servo servoR;
//Front Sonar is pin 2
//Right Sonar is pin 4
const int pingPinF = 2;
const int pingPinR = 4;

int turnTimer = 0;
int turnDuration = 34;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  servoL.attach(7);
  servoR.attach(0);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long frontDuration, rightDuration, inchesF, inchesR;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPinF, OUTPUT);
  digitalWrite(pingPinF, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinF, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinF, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPinF, INPUT);
  frontDuration = pulseIn(pingPinF, HIGH);

  // convert the time into a distance
  inchesF = microsecondsToInches(frontDuration);

//  Serial.print(inchesF);
//  Serial.println(" Front inches");

  delay(10);

  if(turnTimer > 0) {
    turnTimer--;
  }
  else if(inchesF > 5) {
    
    Serial.print(inchesF);
    Serial.println(" Front inches");
    servoR.write(0);
    servoL.write(140);
    
  }
  else if(inchesF <= 5) {
      pinMode(pingPinR, OUTPUT);
      digitalWrite(pingPinR, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPinR, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPinR, LOW);

      pinMode(pingPinR, INPUT);
      rightDuration = pulseIn(pingPinR, HIGH);
      inchesR = microsecondsToInches(rightDuration);
      Serial.print(inchesR);
      Serial.println(" Right inches");

      if (inchesR > 3) {
        turnTimer = 35;
          servoR.write(180);
          servoL.write(140);
      }
          else {
            turnTimer = 35;
              servoR.write(0);
              servoL.write(0);
//            servoR.write(90);
//            servoL.write(85);

          }
      
  }
  
}

long microsecondsToInches(long microseconds) {
  //According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
