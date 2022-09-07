const int motorPin = 13;
const int buttonPin = 2;
unsigned long currentTime = 0;
unsigned long periodStart = 0;
unsigned long pulseTime = 500000;
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
  if(buttonState == HIGH) {
      if((currentTime - periodStart) >= 1000000) {
    
          digitalWrite(motorPin, HIGH);
          periodStart = currentTime;
    
      }
        
      if((currentTime - periodStart) >= pulseTime) {
    
          digitalWrite(motorPin, LOW);
        
      }
  } else {
   
      digitalWrite(motorPin, LOW);
  
  }
}
