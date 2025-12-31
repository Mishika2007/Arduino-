int switchPin=2;
int switchVal;
int dt=250;

void setup() {
  // put your setup code here, to run once:
pinMode(switchPin,INPUT);
digitalWrite(switchPin,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
switchVal=digitalRead(switchPin);
Serial.print("your button is:");
Serial.println(switchVal);
delay(dt);
}
