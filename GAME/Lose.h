//notas da musica
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

//tempo de duração de cada nota
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
//Numero de notas a serem tocadas
  for (int thisNote = 0; thisNote < 12; thisNote++) {

   //Calculo para obter o tempo que a nota vai durar
    int noteDurationLose = 1000 / noteDurationsLose[thisNote];
    tone(3, melodyLose[thisNote], noteDurationLose);

    //Pausa entre notas
    int pauseBetweenNotes = noteDurationLose * 1;
    delay(pauseBetweenNotes);
    //Pin do buzzer
    noTone(3);
  }
}
