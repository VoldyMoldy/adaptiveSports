const int motorPin = 13;
const int buttonPin = 2;
unsigned long currentTime = 0;
unsigned long periodStart = 0;
unsigned long pulseTime = 1650;
int buttonState = 0;
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
  Serial.print(buttonState);
}
