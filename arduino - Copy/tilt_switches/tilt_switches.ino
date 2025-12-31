int tiltPin=2;
int tiltVal;
int redPin=5;
int greenPin=6;

void setup() {
  // put your setup code here, to run once:
pinMode(tiltPin,INPUT);
digitalWrite(tiltPin,HIGH);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltVal=digitalRead(tiltPin);
Serial.println(tiltVal);
if(tiltVal==0){
  digitalWrite(greenPin,HIGH);
  digitalWrite(redPin,LOW);
}
else{
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,HIGH);
}
}
