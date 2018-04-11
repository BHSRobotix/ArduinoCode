#include <Servo.h>

Servo servoL;
Servo servoR;
//Front Sonar is pin 2
//Right Sonar is pin 4
const int pingPinF = 2;
const int pingPinR = 4;
const int pingPinL = 6;

double savedInches;

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
  double frontDuration, rightDuration, leftDuration;
  double inchesF, inchesR, inchesL;

  pinMode(pingPinF, OUTPUT);
  digitalWrite(pingPinF, LOW);
  delayMicroseconds(1);
  digitalWrite(pingPinF, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinF, LOW);
  pinMode(pingPinF, INPUT);
  frontDuration = pulseIn(pingPinF, HIGH);
  inchesF = microsecondsToInches(frontDuration);
  delay(10);

  Serial.print("Front Inches = ");
  Serial.println(inchesF);

  if (inchesF > 3) {
    servoR.write(71;
    servoL.write(100);
  }
  else if (inchesF <= 3) {
    savedInches = inchesF;
    Serial.print("savedInches = ");
    Serial.println(savedInches);

    pinMode(pingPinR, OUTPUT);
    digitalWrite(pingPinR, LOW);
    delayMicroseconds(1);
    digitalWrite(pingPinR, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPinR, LOW);

    pinMode(pingPinR, INPUT);
    rightDuration = pulseIn(pingPinR, HIGH);
    inchesR = microsecondsToInches(rightDuration);
    delay(10);

    Serial.print("Right Inches = ");
    Serial.println(inchesR);

    if (inchesR > 4.5) {
      pinMode(pingPinL, OUTPUT);
      digitalWrite(pingPinL, LOW);
      delayMicroseconds(1);
      digitalWrite(pingPinL, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPinL, LOW);
      pinMode(pingPinL, INPUT);
      leftDuration = pulseIn(pingPinL, HIGH);
      inchesL = microsecondsToInches(leftDuration);
      delay(10);

        Serial.print("Left Inches = ");
        Serial.println(inchesL);

      while (inchesL >= savedInches - .4) {
        pinMode(pingPinL, OUTPUT);
        digitalWrite(pingPinL, LOW);
        delayMicroseconds(1);
        digitalWrite(pingPinL, HIGH);
        delayMicroseconds(5);
        digitalWrite(pingPinL, LOW);
        pinMode(pingPinL, INPUT);
        leftDuration = pulseIn(pingPinL, HIGH);
        inchesL = microsecondsToInches(leftDuration);
        delay(10);

        Serial.print("Left Inches = ");
        Serial.println(inchesL);

        servoR.write(92);
        servoL.write(92);
      }
    }

    else if (inchesR <= 4.5) {
      savedInches = inchesF;

      pinMode(pingPinR, OUTPUT);
      digitalWrite(pingPinR, LOW);
      delayMicroseconds(1);
      digitalWrite(pingPinR, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPinR, LOW);
      pinMode(pingPinR, INPUT);
      rightDuration = pulseIn(pingPinR, HIGH);
      inchesR = microsecondsToInches(rightDuration);
      delay(10);

      Serial.print("Right Inches = ");
      Serial.println(inchesR);

      while (inchesR >= savedInches + .25) {
        pinMode(pingPinR, OUTPUT);
        digitalWrite(pingPinR, LOW);
        delayMicroseconds(1);
        digitalWrite(pingPinR, HIGH);
        delayMicroseconds(5);
        digitalWrite(pingPinR, LOW);
        pinMode(pingPinR, INPUT);
        rightDuration = pulseIn(pingPinR, HIGH);
        inchesR = microsecondsToInches(rightDuration);
        delay(10);

        Serial.print("Right Inches = ");
        Serial.println(inchesR);

        servoR.write(70);
        servoL.write(70);
      }

    }
  }
}

double microsecondsToInches(double microseconds) {
  //According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

