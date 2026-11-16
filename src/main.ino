// C++ code
//
// Piano 7 notes - Arduino UNO

const int boutons[7] = {4,5,6,7,8,9,10};
const int buzzer = 11;
const int leds[7] = {2, 3, 12, 13, A0, A1, A2};

// Do, Ré, Mi, Fa, Sol, La, Si (Hz)
const int notes[7] = {262, 294, 330, 349, 392, 440, 494};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(boutons[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  bool joue = false;

  for (int i = 0; i < 7; i++) {
    if (digitalRead(boutons[i]) == LOW) {   // bouton appuyé
      tone(buzzer, notes[i]);
      digitalWrite(leds[i], HIGH);//alumer led
      joue = true;
      break;                                // une seule note à la fois
    }
  }

  if (!joue) {
    noTone(buzzer);
    
        for (int i = 0; i < 7; i++) {
            digitalWrite(leds[i], LOW);
        }
  }
}