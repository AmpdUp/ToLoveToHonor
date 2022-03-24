# Projeto-SDAC

## Objetivo
O objetivo deste projeto é criar um jogo com base num LED RGB que se encontra a mudar de cor (entre: Vermelho, Amarelo, Verde, Cyan, Azul, Magenta e Branco ), ao mesmo tempo 4 utilizadores são definidos por 4 cores definidas por LEDs (Azul, Verde, Vermelho e Roxo) e têm que carregar no seu respetivo botão no momento que o LED central reproduzir a sua cor.

Para isso decidimos utilizar um Arduino Uno, utilizando os seguintes componentes connectados ao seguintes PINs:

<div align="center">
  
| Componente         | Pin Digital |                      Uso                     |
| :---               |     :---:   |                     :---                     |
| LED RGB Azul       |      13     | Led Utilizado para indicar jogador "Azul"    |
| LED RGB Verde      |      12     | Led Utilizado para indicar jogador "Verde"   |
| LED RGB  Vermelho  |      11     | Led Utilizado para indicar jogador "Vermelho"|
| LED RGB Roxo       |      10     | Led Utilizado para indicar jogador "Roxo"    |
| LED Bit 1          |      9      | Led Utilizado para definir a regra da ronda  |
| LED Bit 3          |      8      | Led Utilizado para definir a regra da ronda  |
| Botão 1            |      7      | Botão do Jogador 1 "Azul"                    |
| Botão 2            |      6      | Botão do Jogador 1 "Verde"                   |
| Botão 3            |      5      | Botão do Jogador 1 "Vermelho"                |
| Botão 4            |      4      | Botão do Jogador 1 "Roxo"                    |
| Pot and Buzzer     |      3      | Potenciómetro e Buzzer para músicas          |
| LED Bit 4          |      A1     | Led Utilizado para definir a regra da ronda  |
| LED Bit 2          |      A2     | Led Utilizado para definir a regra da ronda  |
| LED Central RGB R  |      A3     | Led Central                                  |
| LED Central RGB B  |      A4     | Led Central                                  |
| LED Central RGB G  |      A5     | Led Central                                  |
  
  
<img src="https://github.com/PedroTorrado/Projeto-SDAC/blob/main/Images/Circuit.png" width="600"/>

</div>

Pode-se aceder a este circuito como simulação (da qual teve que ser expluída os tons do buzzer uma vez que não é possível incluir bibliotecas) em: 


### Código
---

Para começar dividimos o circuito e programa em 5 partes: 
- Músicas / Buzzer
- LED Aleatório (representa um número aleatório de 4 bits, um bit cada LED)
- LED Central (LED que altera de cor)
- Butões e LED de Utilizador (LEDs representativos da cor de cada utilizar e respetivos butões) 

O programa começa por incluir as bibliotecas "Pitches.h", "Power_UP.h", "Rules.h", "Win.h" e "Lose.h" que são bibliotecas criadas para este jogo com o propósito de tocar músicas ou Tons por frequência a partir do Buzzer cujo volume pode ser controlado a partir do potenciometro.

```C++
#include "Pitches.h"
#include "Rules.h"
#include "Win.h"
#include "Lose.h"
#include "Power_UP.h"
```
Como funcionam estes? 
## Músicas / Buzzer

Por exemplo: 

## Definir os pin

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

E ainda: 

```C++
int ON = 0;
int OFF = 1;
```

Utilizado apenas de forma a que se possam usar vários tipos de LED, no nosso exemplo os pins dos LEDs RGB encontram-se connectados a 5V como saída o que significa que se estes estiverem "HIGH", eles econtram-se desligados pois não há diferença de potêncial, mas se estes estiverem "LOW" há diferença de potêncial entre a entrada e a saída de 5V o que liga os mesmos, daí ON ser 0, ou "LOW", e OFF ser 1, ou "HIGH".

## Setup

Após essa configuração temos a função *void setup()* do nosso programa no qual nós identificamos os pins como entrada ou saída, sendo qualquer LED, uma saída (OUTPUT) assim como o Buzzer e qualquer butão como entrada (INPUT).

```C++
void setup()
{
  Serial.begin(9600);
 
  pinMode(BlueLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(PurpleLed, OUTPUT);
```

Para além disso no final desta função chama-se as funções RuleDefining(), com o propósito de selecional um valor aleatório nos LEDs de Bits e apresentar esse valor, e Power_UP() para através do Buzzer reproduzir um som de início (como explicado antes) para simbolizar o ligar do dispositivo.

```C++
  int Power_UP();
  Power_UP();
  int RuleDefining();
  RuleDefining();
}
```

## LED Aleatório

Para o definir de regras utilizámos 4 LEDs de forma a representar 4 bits e assim até 15 números.

Para esse efeito criámos a função RuleDefining(): 

```C++
int RuleDefining(){

  randomSeed(analogRead(0));
  
  int bit0 = random(0, 2);
  int bit1 = random(0, 2);
  int bit2 = random(0, 2);
  int bit3 = random(0, 2);

  digitalWrite(LedGame0, bit0);
  digitalWrite(LedGame1, bit1);
  digitalWrite(LedGame2, bit2);
  digitalWrite(LedGame3, bit3);
}
```

Utilizamos assim a funçãi random(0, 2) para identificar aleatóriamente valores entre 0 e 1 para cada um dos 4 Bits e uma vez que estes valores são 0 e 1 podem ser utilizados como "HIGH" e "LOW" pelos LEDs e definir assim o número aleatório.

