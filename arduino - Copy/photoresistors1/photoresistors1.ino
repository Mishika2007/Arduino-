int lightPin=A0;
int lightVal;
int dv=250;
int greenPin=3;
int redPin=5;

void setup() {
  // put your setup code here, to run once:
 pinMode(lightPin,INPUT);
 Serial.begin(9600);
 pinMode(greenPin,OUTPUT);
 pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
lightVal=analogRead(lightPin);
Serial.println(lightVal);
delay(dv);

if(lightVal>20){
  digitalWrite(greenPin,HIGH);
  digitalWrite(redPin,LOW);
}

if(lightVal<20){
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,HIGH);
}
}
