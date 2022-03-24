#include "pitches.h"

int melodyON[] = {
  NOTE_C7,
  NOTE_E7,
};

int noteDurationsON[] = {7,4,};

void Power_UP() {
  for (int thisNoteON = 0; thisNoteON < 2; thisNoteON++) {
    int noteDurationON = 1000 / noteDurationsON[thisNoteON];
    tone(3, melodyON[thisNoteON], noteDurationON);

    int pauseBetweenNotesON = noteDurationON * 1;
    delay(pauseBetweenNotesON);

    noTone(3);
  }
}
