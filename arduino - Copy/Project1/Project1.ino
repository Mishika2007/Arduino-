int ledPins[] = {3, 4, 5, 6, 7, 8, 9};  // LEDs for dice dots
int joyBtn = 2;
int buzzer = 10;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(joyBtn, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A0));  // For better randomness
}

void loop() {
  if (digitalRead(joyBtn) == LOW) {
    int number = random(1, 7);  // Get a number from 1 to 6
    showDice(number);
    tone(buzzer, 1000, 200);  // Beep (optional)
    delay(500);               // Delay to prevent double roll
  }
}

void showDice(int num) {
  // Turn off all LEDs first
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  switch (num) {
    case 1:
      digitalWrite(ledPins[4], HIGH);
      break;
    case 2:
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[5], HIGH);
      break;
    case 3:
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[6], HIGH);
      break;
    case 4:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[5], HIGH);
      break;
    case 5:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[5], HIGH);
      digitalWrite(ledPins[6], HIGH);
      break;
    case 6:
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH);
      digitalWrite(ledPins[3], HIGH);
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], HIGH);
      break;
  }
}