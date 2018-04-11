
const int buttonPin = 1;
int buttonState = 0;

void setup() {
  Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println(buttonState);
  }
    else (buttonState == LOW); {
      Serial.println(buttonState);
 
    }

}
