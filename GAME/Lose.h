int melodyLose[] = {
  NOTE_C5,  //1
  NOTE_G4,  //2
  NOTE_E4,  //3
  NOTE_A4,  //4
  NOTE_B4,  //5
  NOTE_A4,  //6

  NOTE_GS4,  //7L
  NOTE_AS4,  //8L
  NOTE_GS4,  //9

  NOTE_G4,   //10C
  NOTE_FS4,  //11
  NOTE_G4,   //12L

};


int noteDurationsLose[] = {

  4,
  4,
  4,
  4,
  4,
  4,
  3,
  3,
  4,
  5,
  5,
  2,
};

int Lose() {

  for (int thisNote = 0; thisNote < 12; thisNote++) {


    int noteDurationLose = 1000 / noteDurationsLose[thisNote];
    tone(3, melodyLose[thisNote], noteDurationLose);


    int pauseBetweenNotes = noteDurationLose * 1;
    delay(pauseBetweenNotes);

    noTone(3);
  }
}
