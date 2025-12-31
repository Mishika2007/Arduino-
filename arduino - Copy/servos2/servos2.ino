#include<Servo.h>
int lightVal;
int lightPin=A4;
int servoPin=6;
int dt=250;
Servo myServo;
int angle;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lightPin,INPUT);
pinMode(servoPin,OUTPUT);
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
lightVal=analogRead(lightPin);
Serial.println(lightVal);
delay(dt);
angle=(-160./69.)*lightVal+160.*85./69.;
myServo.write(angle);
}
