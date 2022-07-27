int ledState = LOW;
#include <Servo.h>

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(0, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(2)){
    swingClub(1, 100);
    swingClub(2, 250);
    swingClub(1, 40);    
  }
    
}


 void swingClub(int direction, unsigned long time){
  String swingDir = "Backward";
  if (direction > 1.5) {
    swingDir = "Forward";
  }
  
  unsigned long start = millis();

  while((millis() - start) < time) {
      Serial.print(swingDir + " swing...");
      digitalWrite(13, HIGH);
      delay(direction);// 1 msec is reverse
      digitalWrite(13,LOW);
      delay(3-direction); // reversing for 1 msec  
      
  }

}
