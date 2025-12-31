#include <Servo.h>
int servoPin=9;
int servoPos=90;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println("what angle for the servo?");
  while (Serial.available()==0){

  }
  servoPos=Serial.parseInt();
  myServo.write(servoPos);
  // put your main code here, to run repeatedly:

}
