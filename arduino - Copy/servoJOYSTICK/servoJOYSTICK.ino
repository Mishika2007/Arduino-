#include<Servo.h>
Servo Xservo;
int Xpin=A0;
int Ypin=A1;
int Spin=3;
int XSpin=10;
int buzzPin=7;
int WVx;
int Xval;
int Yval;
int Sval;
int dt=250;
int redPin=11;
int greenPin=12;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Xpin,INPUT);
pinMode(Ypin,INPUT);
pinMode(Spin,INPUT);
pinMode(XSpin,OUTPUT);
pinMode(buzzPin,OUTPUT);
Xservo.attach(XSpin);
digitalWrite(Spin,HIGH);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
}

void loop() {
  Xval=analogRead(Xpin);
  WVx=(180./1023.)*Xval;
  Yval=analogRead(Ypin);
  Sval=digitalRead(Spin);
  Xservo.write(WVx);
  if(Sval==0){
    digitalWrite(buzzPin,HIGH);
  }
  else{
   digitalWrite(buzzPin,LOW); 
  }
  
  delay(dt);
  Serial.print("X value = ");
  Serial.println(Xval);
  Serial.print("Y value = ");
  Serial.println(Yval);
  Serial.print("Switch State is ");
  Serial.println(Sval);
  if(Xval<20){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  if(Xval>1000){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
  }
  // put your main code here, to run repeatedly:

}


