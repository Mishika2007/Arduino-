int potVal;
int buzzPin=8;
String msg="please input your number";
int potPin=A3;

void setup() {
 Serial.begin(9600);
 pinMode(buzzPin,OUTPUT);
 pinMode(potPin,INPUT);
  
}
void loop(){
potVal=analogRead(potPin);
Serial.println(potVal);
if (potVal>1000){
  digitalWrite(buzzPin,HIGH);
  delay(500);
  digitalWrite(buzzPin,LOW);
}c:\Users\singh\OneDrive\Desktop\arduino\buzzerpotentiometer

}
