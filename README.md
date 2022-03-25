# Projeto-SDAC

## Objetivo
O objetivo deste projeto é criar um jogo com base num LED RGB que se encontra a mudar de cor (entre: Vermelho, Amarelo, Verde, Ciano, Azul, Magenta e Branco ), ao mesmo tempo 4 utilizadores são definidos por 4 cores definidas por LEDs (Azul, Verde, Vermelho e Roxo) e têm que carregar no seu respetivo botão no momento que o LED central reproduzir a sua cor.

Para isso decidimos utilizar um Arduino Uno, utilizando os seguintes componentes conectados aos seguintes PINs:

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
  
  
<img src="https://github.com/PedroTorrado/Projeto-SDAC/blob/d259d88f4ec4b43909e0990faefa7ffc6630c431/Images/Circuit.png" width="600"/>

</div>

Pode-se aceder a este circuito como simulação (da qual tiveram que ser excluídos os tons do buzzer uma vez que não é possível incluir bibliotecas) em: 


### Código
---

Para começar dividimos o circuito e programa em 5 partes: 
- Músicas / Buzzer
- LED Aleatório (representa um número aleatório de 4 bits, um bit cada LED)
- LED Central (LED que altera de cor)
- Botões e LED de Utilizador (LEDs representativos da cor de cada utilizar e respetivos botões) 

O programa começa por incluir as bibliotecas "Pitches.h", "Power_UP.h", "Rules.h", "Win.h" e "Lose.h" que são bibliotecas criadas para este jogo com o propósito de tocar músicas ou Tons por frequência a partir do Buzzer cujo volume pode ser controlado a partir do potenciómetro.

```C++
#include "Pitches.h"
#include "Rules.h"
#include "Win.h"
#include "Lose.h"
#include "Power_UP.h"
```
Como funcionam estes? 

Por exemplo:

## Músicas / Buzzer

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

Utilizado apenas de forma a que se possam usar vários tipos de LED, no nosso exemplo os pins dos LEDs RGB encontram-se conectados a 5V como saída o que significa que se estes estiverem "HIGH", eles econtram-se desligados, pois não há diferença de potencial, mas se estes estiverem "LOW" há diferença de potencial entre a entrada e a saída de 5V o que liga os mesmos, daí ON ser 0, ou "LOW", e OFF ser 1, ou "HIGH".

## Setup

Após essa configuração temos a função *void setup()* do nosso programa no qual nós identificamos os pins como entrada ou saída, sendo qualquer LED, uma saída (OUTPUT) assim como o Buzzer e qualquer botão como entrada (INPUT).

```C++
void setup()
{
  Serial.begin(9600);
 
  pinMode(BlueLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(PurpleLed, OUTPUT);
```

Para além disso no final desta função chama-se as funções RuleDefining(), com o propósito de selecionar um valor aleatório nos LEDs de Bits e apresentar esse valor, e Power_UP() para através do Buzzer reproduzir um som de início (como explicado antes) para simbolizar o ligar do dispositivo.

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

Utilizamos assim a função random(0, 2) para identificar aleatoriamente valores entre 0 e 1 para cada um dos 4 Bits e uma vez que estes valores são 0 e 1 podem ser utilizados como "HIGH" e "LOW" pelos LEDs e definir assim o número aleatório.

## Led Central

Para termos um LED central com uma cor gerada automáticamente criámos uma função chamada value() que funciona criando um valor aleatório de 0 a 7 com a mesma função random() que na secção anterior contudo esta tem que acontecer de x em x tempo, neste caso escolhe-mos meio segundo ou 500ms.

De forma a que algo aconteça em x em x tempo muitas vezes utiliza-se delays em programas deste género, contudo como o micro-processador tem que se encontrar disponível para ler os INPUTS dos botões não se podem usar delays. Assim, de forma a evitar a interrupção do funcionamento do micro-processador, decidimos utilizar o clock interno do mesmo através da função millis(). 

millis() é uma função que disponibiliza o número de milissegundos que passaram após ligar o micro-processador. Assim pode ser utilizado da seguinte forma:

```C++
int NewMillis = 0;
int val = 7; // used as default valur of switch()

String value(){

  int CurrentMillis = millis();
  int WaitingTime = 500;

  randomSeed(analogRead(0));

  if (CurrentMillis - NewMillis >= WaitingTime){
    val = random(0,7+1);
    NewMillis = CurrentMillis;
  }
```

Para a função de tempo, são criadas três variáveis, uma fora da função repetida, sendo este NewMillis e duas dentro (deste caso de value()), CurrentMillis e Waiting Time.

Assim, NewMillis é definido como 0 (de inicio), e cada vez que value() se repete, CurrentMillis é igualado a millis() (sendo assim o valor de ms do clock do arduino), WaitingTime é ainda definido como 500 (milissegundos ou ms). Após isso é criada uma função if() que verifica se a diferença entre CurrentMillis e NewMillis é maior ou igual ao WaitingTime.

Resumindo quando o micro-processador começa a contar este if() espera até ser 500 (500 - 0 >= 500) (e cria um novo valor aleatório para val), depois de este alcançar 500 NewMillis é igualado a esse valor e assim apenas quando chegar a 1000 (1000 - 500 >= 500) o if() ocorre e assim se repete para cada múltiplo de 500.

Uma vez que o valor val é alterada a cada 500 ms, é criada uma função switch() que a cada valor aleatório entre 0 e 7, ele reproduz um valor de cor para uma string chamada Color.

```C++
  String Color;
  
  switch(val){

    case 1 :  
      Color = "Red";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, OFF);
      digitalWrite(BLed, OFF);
      break;

    case 2 :  
      Color = "Purple";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, OFF);
      digitalWrite(BLed, ON);
      break;
```

Após isto termina a função value fazendo return do valor de Color.

## Botões e LED de utilizador

Para que o jogo funcione é necessário verificar assim os INPUTS dos utilizadores/jogadores e verificar se o LED central se encontra ou não na cor pretendida e após isso resultar na vitória ou derrota do jogador e reproduzir as ações necessárias para demonstrar isso.

Isto foi feito dentro do void loop() da seguinte forma:

```C++

void loop()
{     
  bool Blue = digitalRead(BlueButton);
  bool Green = digitalRead(GreenButton);
  bool Red = digitalRead(RedButton);
  bool Purple = digitalRead(PurpleButton);

```

Aqui ps botões são definidos como valores booleanos (0 ou 1).

```C++
value();
  String ColorState = value();
```

É chamada a função value() para que os LED que define a cor central seja demonstrado como pertendido (aleatórios) e é criada uma variável, ColorState, com esse mesmo valor.

```C++
if (Blue == 1){
      if(ColorState == "Blue"){
        Serial.println("Win");
        delay(500);
        DancyDance();
      }
      else{
        Serial.println("Lose");
        delay(500);
        Cry();
      }
  }
```

Cada vez que um botão é definido como 1, é verificado se este, é igual à cor do central, como apresentado acima. Caso seja, é reproduzida a função DancyDance, caso não seja é reproduzida a função Cry(). E isto é repetido a partir de vários if(), else if() ou else de forma a verificar todos os botões para cada uma das cores. 

*Agora, como funcionam as funções DancyDance() e Cry()?* 

```C++
int DancyDance(){
    
  digitalWrite(BlueLed, OFF);
  digitalWrite(GreenLed, OFF);
  digitalWrite(RedLed, OFF);
  digitalWrite(PurpleLed, OFF);
```

Para começar todos os LEDS dos utilizadores são desligados.

```C++
  bool state = 0;
  int end = 1;
  int Win();
  Win();
```

São criadas as variáveis state e end e é chamada a função Win() da biblioteca Win.h de forma a reproduzir a música de vitória.

```C++
  while(end != 0){
       
    int CurrentMillis = millis();
    int WaitingTime = 500;

    if(CurrentMillis - NewMillis >= WaitingTime){
      if(state == 1){
        digitalWrite(BlueLed, ON);
        digitalWrite(GreenLed, ON);
        digitalWrite(RedLed, ON);
        digitalWrite(PurpleLed, ON);
        state = 0;
        Serial.println("ON");
      }
      else{
        digitalWrite(BlueLed, OFF);
        digitalWrite(GreenLed, OFF);
        digitalWrite(RedLed, OFF);
        digitalWrite(PurpleLed, OFF);
        state = 1;
        Serial.println("OFF");
      }
      NewMillis = CurrentMillis;
  	}
```

Enquanto a variável end for diferente de 0, este espera de 500 a 500 ms e verifica se os LEDs dos utilizadores se encontram HIGH ou LOW, se forem HIGH define como LOW e se for LOW, define como HIGH, esta verificação é feita a partir da variável state, que verifica a alteração dos LEDs após cada um dos casos.

```C++
  if(
        Blue == 1 or
        Green == 1 or
        Red == 1 or
        Purple == 1
      ){
        end = 0;
        Serial.println("Resume");
        delay(500);
        digitalWrite(BlueLed, ON);
        digitalWrite(GreenLed, ON);
        digitalWrite(RedLed, ON);
        digitalWrite(PurpleLed, ON);
      }
      else{end = 1;}
    }
```

Os botões são lidos e caso algum deles se encontre pressionado o jogo resume-se voltando à função loop(), igualando end a 1, para além disso liga todos os LEDs de utilizador. 

```C++ 
  RuleDefining();
  int Rules();
  Rules();
```

Esta função termina chamando RuleDefining, para alterar os LEDs representativos das regras para um novo valor e a função Rules() da biblioteca Rules.h, reproduzindo o som de aleatoriedade das regras. 

### Conclusão
---

Juntando tudo isto é possível reproduzir-mos um programa que obedece às regras do jogo como pretendido e assim é possível utilizar este sistema para aplicar uma grande quantidade de regras, 16 de vitória de 16 de derrota, para ser mais específico. 

Para utilização deste programa foi desenvolvido o seguinte PCB:

<div align="center">

<img src="https://github.com/PedroTorrado/Projeto-SDAC/blob/d259d88f4ec4b43909e0990faefa7ffc6630c431/Images/PCB.png" width="600"/>
  
</dic>
