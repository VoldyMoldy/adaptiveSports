const int motorPin = 13;
const int buttonPin = 2;
unsigned long currentTime = 0;
unsigned long periodStart = 0;
unsigned long pulseTime = 1650;
int buttonState = 0;
bool buttonPressed = false;
int buttonPressedTime = 0;
bool ignoreButton = false;
void setup() {
  // put your setup code here, to run once:
  currentTime = micros();
  periodStart = currentTime;

  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = micros();
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && ignoreButton == false) {
    if(not buttonPressed) {
      buttonPressedTime = currentTime;
      buttonPressed = true;
    } if((currentTime - periodStart) >= 50000) {
      digitalWrite(motorPin, HIGH);
      periodStart = currentTime;
    } if((currentTime - periodStart) >= pulseTime) {
      digitalWrite(motorPin, LOW);
    } if((currentTime - buttonPressedTime) >= 2000000) {
      ignoreButton = true;
      buttonPressedTime = currentTime;
    }
  } if(ignoreButton) {
    if((currentTime - buttonPressedTime) >= 1500000) {
      ignoreButton = false;
      buttonPressedTime = 0;
    } if((currentTime - periodStart) >= 50000) {
      digitalWrite(motorPin, HIGH);
    } if((currentTime - periodStart) >= 1250) {
      digitalWrite(motorPin, LOW);
    }
  }
}
