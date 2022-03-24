#include "pitches.h"

int melodyWin[] = {
  NOTE_G4,    //1
  NOTE_C5,    //2
  NOTE_E5,    //3
  NOTE_G5,    //4
  NOTE_C6,    //5
  NOTE_E6,    //6
  
  NOTE_G6,    //7L
  NOTE_E6,    //8L

  NOTE_GS4,   //9
  NOTE_C5,    //10
  NOTE_DS5,   //11
  NOTE_GS5,   //12
  NOTE_C6,    //13
  NOTE_DS6,   //14
  
  NOTE_GS6,   //15L
  NOTE_DS6,   //16L

  NOTE_AS4,   //17
  NOTE_D5,    //18
  NOTE_F5,    //19
  NOTE_AS5,   //20
  NOTE_D6,    //21
  NOTE_F6,    //22
  
  NOTE_AS6,   //23L
  NOTE_AS5,   //24
  NOTE_AS6,   //25
  NOTE_AS5,   //26

  NOTE_C6, //27L

};


int noteDurationsWin[] = {
 
8,8,8,8,8,8,3,3,8,8,8,8,8,8,3,3,8,8,8,8,8,8,3,8,8,8,2,};

int Win(){
  
  for (int thisNote = 0; thisNote < 27; thisNote++) {

    int noteDurationWin = 1000 / noteDurationsWin[thisNote];
    tone(3, melodyWin[thisNote], noteDurationWin);

   
    int pauseBetweenNotes = noteDurationWin * 1;
    delay(pauseBetweenNotes);
    
    noTone(3);
    
  }
}