# Projeto-SDAC

## Objetivo
O objetivo deste projeto é criar um jogo com base num LED RGB que se encontra a mudar de cor (entre: Vermelho, Amarelo, Verde, Cyan, Azul, Magenta e Branco ), ao mesmo tempo 4 utilizadores são definidos por 4 cores definidas por LEDs (Azul, Verde, Vermelho e Roxo) e têm que carregar no seu respetivo botão no momento que o LED central reproduzir a sua cor.

Para isso decidimos utilizar um Arduino Uno, utilizando os seguintes componentes connectados ao seguintes PINs:

<div align="center">
  
| Componente     | Pin Digital |      Uso     |
| :---           |     :---:   |     :---     |
| LED Azul       |      13     | Led Utilizado para indicar jogador "Azul"    |
| LED Verde      |      12     | Led Utilizado para indicar jogador "Verde"   |
| LED Vermelho   |      11     | Led Utilizado para indicar jogador "Vermelho"|
| LED Roxo       |      10     | Led Utilizado para indicar jogador "Roxo"    |
| LED Bit 1      |      9      | Led Utilizado para definir a regra da ronda  |
| LED Bit 3      |      8      | Led Utilizado para definir a regra da ronda  |
| LED Botão 1    |      7      | Botão do Jogador 1 "Azul"                    |
| LED Botão 2    |      6      | Botão do Jogador 1 "Verde"                   |
| LED Botão 3    |      5      | Botão do Jogador 1 "Vermelho"                |
| LED Botão 4    |      4      | Botão do Jogador 1 "Roxo"                    |
| Pot and Buzzer |      3      | Potenciómetro e Buzzer para músicas          |
| LED Bit 4      |      A1     | Led Utilizado para definir a regra da ronda  |
| LED Bit 2      |      A2     | Led Utilizado para definir a regra da ronda  |
| LED Central R  |      A3     | Led Central                                  |
| LED Central B  |      A4     | Led Central                                  |
| LED Central G  |      A5     | Led Central                                  |
  
  
<img src="https://github.com/PedroTorrado/Projeto-SDAC/blob/main/Images/Circuit.png" width="600"/>

</div>

## Código

O programa começa por incluir as bibliotecas "Pitches.h", "Power_UP.h", "Rules.h", "Win.h" e "Lose.h" que são bibliotecas criadas para este jogo com o propósito de tocar músicas ou Tons por frequência a partir do Buzzer cujo volume pode ser controlado a partir do potenciometro.

```C++
#include "Pitches.h"
#include "Rules.h"
#include "Win.h"
#include "Lose.h"
#include "Power_UP.h"
```
Como funcionam estes? 

Por exemplo: 
Começando por introduzir a biblioteca que contem tonas as notas necessárias para produzir as músicas do jogo.
```C++
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
```
*esta não é a biblioteca completa(https://github.com/Cordelios810/Projeto-SDAC/blob/9f65239314f14a2f93a36d43e19352b88c2265a8/GAME/Pitches.h)

Cada um destas linhas de código é composto pelo nome da nota
```C++
NOTE_C4
```
E a frequência atribuída a essa nota
```C++
262
```
Sendo incluindo a biblioteca das notas no código agora é possível programar as músicas que serão tocadas no buzzer.

Por exemplo:
```C++
int melodyRules[] = {
  NOTE_C7,
  NOTE_E7,
  
};

int noteDurationsON[] = {8,8,};

void setup() {
  
  for (int thisNoteON = 0; thisNoteON < 50; thisNoteON++) {
  
    int noteDurationON = 1000 / noteDurationsON[thisNoteON];
    tone(3, melodyON[thisNoteON], noteDurationON);

    int pauseBetweenNotesON = noteDurationON * 1;
    delay(pauseBetweenNotesON);
    
    noTone(3);
    
  }
}
```
Este código está organizado desta seguinte forma: 

-Notas que irão ser utilizadas.
```C++
int melodyRules[] = {
  NOTE_C7,
  NOTE_E7,
```

-Duração das notas.
```C++
int noteDurationsON[] = {8,8,};
```

-Numero de notas a serem tocadas.
```C++
for (int thisNoteON = 0; thisNoteON < 50; thisNoteON++) 
```


-Calculo para obter o tempo que a nota vai durar.
```C++
int noteDurationON = 1000 / noteDurationsON[thisNoteON];
    tone(3, melodyON[thisNoteON], noteDurationON);
```


-Pausa entre notas.
```C++
int pauseBetweenNotesON = noteDurationON * 1;
    delay(pauseBetweenNotesON);
```


-Pin do buzzer.
```C++
noTone(3);
```

Após isso o programa começa por definir os componentes e os respetivos Pins como descritos na tabela anterior.

```C++
#define BlueLed 13
#define GreenLed 12
#define RedLed 11
#define PurpleLed 10

#define LedGame0 A1
#define LedGame1 8
#define LedGame2 A2
#define LedGame3 9

#define BlueButton 7
#define GreenButton 6
#define RedButton 5
#define PurpleButton 4

#define RLed A3
#define BLed A4
#define GLed A5
```
