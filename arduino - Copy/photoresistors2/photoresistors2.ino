int lightPin=A0;
int buzzPin=8;
int lightVal;
int delayT;

void setup() {
  pinMode(A0,INPUT);
  pinMode(buzzPin,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  lightVal=analogRead(lightPin);
  delayT=(9./550.)*lightVal-(9.*200./550.)+1.;
  Serial.println(lightVal);
  digitalWrite(buzzPin,HIGH);
  delay(delayT);
  digitalWrite(buzzPin,LOW);
  delay(delayT);
  // put your main code here, to run repeatedly:

}
