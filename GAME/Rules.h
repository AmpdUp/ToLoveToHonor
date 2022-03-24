#include "pitches.h"




int melodyRules[] = {
  NOTE_G4, 
  NOTE_A4, 
  NOTE_B4, 
  NOTE_CS5, 
  
  NOTE_G4, 
  NOTE_A4, 
  NOTE_B4,
  NOTE_CS5,

  NOTE_GS4,
  NOTE_AS4,
  NOTE_C5,
  NOTE_D5,

  NOTE_GS4,
  NOTE_AS4,
  NOTE_C5,
  NOTE_D5,

  NOTE_A4,
  NOTE_B4,
  NOTE_CS5,
  NOTE_DS5,

  NOTE_AS4,
  NOTE_C5,
  NOTE_D5,
  NOTE_E5,

 NOTE_AS4,
  NOTE_C5,
  NOTE_D5,
  NOTE_E5,
  
  NOTE_B4,
  NOTE_CS5,
  NOTE_DS5,
  NOTE_F5,

  NOTE_C5,
  NOTE_D5,
  NOTE_E5,
  NOTE_FS5,

  NOTE_CS5,
  NOTE_DS5,
  NOTE_F5,
  NOTE_G5,

  NOTE_D5,
  NOTE_E5,
  NOTE_FS5,
  NOTE_GS5,

  no,
  no,

  NOTE_A5,
  NOTE_AS5,
  NOTE_B5,
  NOTE_C6,

  
};


int noteDurationsRules[] = {
 
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4,4,1,};

int Rules() {
  
  for (int thisNoteRules = 0; thisNoteRules < 50; thisNoteRules++) {

  
    int noteDurationRules = 1000 / noteDurationsRules[thisNoteRules];
    tone(3, melodyRules[thisNoteRules], noteDurationRules);

   
    int pauseBetweenNotesRules = noteDurationRules * 1;
    delay(pauseBetweenNotesRules);
    
    noTone(3);
    
  }
}