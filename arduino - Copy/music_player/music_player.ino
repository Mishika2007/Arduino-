int buzz=8;
int play=2;
int next=3;
int potPin=A0;

int tune=0;
bool Playing=false;

int tune1[]= {16, 294, 330, 349, 392, 440, 494, 523};
int tune2[]= {523, 494, 440, 392, 349, 330, 294, 262};
int notes=8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(play, INPUT);
  pinMode(next, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(play) == LOW && !Playing) {
    playtune(tune);
    Playing = true;
  }

   if (digitalRead(next) == LOW) {
    tune = (tune + 1) % 2; 
    delay(300);
   }

   if (digitalRead(play) == HIGH) {
    Playing = false;
  }
}

void playtune(int tuneNumber) {
  int *melody = (tuneNumber == 0) ? tune1 : tune2;

  for (int i = 0; i < notes; i++) {
    int potVal = analogRead(potPin);              
    int tempo = map(potVal, 0, 1023, 100, 800);     

    Serial.print("Tempo: ");
    Serial.println(tempo);

    tone(buzz, tune);
    delay(tempo);
    noTone(buzz);
    delay(tempo / 5);  
  }
}
