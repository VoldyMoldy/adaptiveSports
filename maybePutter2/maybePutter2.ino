const int buttonPin = 2;
const int motorPin = 13;
boolean buttonPressed = false;
int pulseStart = 0;
const int pulseLength = 3;
const int pulsePower = 1.55;
unsigned long currentTime = 0;
unsigned long pressedTime = 0;
boolean firstTime = true;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  //update current time
  currentTime = millis();
  //check if button is pressed and reset initial press state is not
  if(digitalRead(buttonPin) == HIGH) {
    buttonPressed = true;
  } else {
    buttonPressed = false;
    firstTime = true;
  }
  //if button is currently pressed turn on motor until let go then stop motor power
  if(buttonPressed) {
    if(firstTime) {
      pulseStart = currentTime;
    }
    if((currentTime - pulseStart) >= pulseLength) {
      digitalWrite(motorPin, HIGH);
      pulseStart = currentTime;
    }
    if((currentTime - pulseStart) >= 1.5) {
      digitalWrite(motorPin, LOW);
    }
  } else {
    digitalWrite(motorPin, LOW);
  }
}
