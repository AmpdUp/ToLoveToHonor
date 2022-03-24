//notas da musica
int melodyON[] = {
  NOTE_C7,
  NOTE_E7,
};
//tempo de duração de cada nota
int noteDurationsON[] = {7,4,};


void Power_UP() {
  //Numero de notas a serem tocadas
  for (int thisNoteON = 0; thisNoteON < 2; thisNoteON++) {
    //Calculo para obter o tempo que a nota vai durar
    int noteDurationON = 1000 / noteDurationsON[thisNoteON];
    tone(3, melodyON[thisNoteON], noteDurationON);
    int pauseBetweenNotesON = noteDurationON * 1;
    
    //Pausa entre notas
    delay(pauseBetweenNotesON);
    //Pin no buzzer
    noTone(3);
  }
}
