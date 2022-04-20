#include "Pitches.h"
#include "Rules.h"
#include "Win.h"
#include "Lose.h"
#include "Power_UP.h"

//defining LEDs for Users
#define PurpleLed 13
#define RedLed 12
#define GreenLed 11
#define BlueLed 10

//Defining LEDs for RuleDefining
#define LedGame0 A1
#define LedGame1 8
#define LedGame2 A2
#define LedGame3 9

//Defining ButtonInputs
#define PurpleButton 7
#define RedButton 6
#define GreenButton 5
#define BlueButton 4

//Defining Colors for CenterLED
#define RLed A3
#define BLed A4
#define GLed A5

//ON and OFF values varies to some LEDs depending if they are connected to GROUND or 5v
int ON = 1;
int OFF = 0;

void setup() {
  //Serial Started to Monitor the processes
  Serial.begin(9600);

  //Pins defined as INPUT or OUTPUT
  pinMode(BlueLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(PurpleLed, OUTPUT);

  pinMode(RLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  pinMode(GLed, OUTPUT);

  pinMode(BlueButton, INPUT);
  pinMode(GreenButton, INPUT);
  pinMode(RedButton, INPUT);
  pinMode(PurpleButton, INPUT);

  pinMode(LedGame0, OUTPUT);
  pinMode(LedGame1, OUTPUT);
  pinMode(LedGame2, OUTPUT);
  pinMode(LedGame3, OUTPUT);

  digitalWrite(BlueLed, ON);
  digitalWrite(GreenLed, ON);
  digitalWrite(RedLed, ON);
  digitalWrite(PurpleLed, ON);

  //Sounds from libraries played to represent powering the device
  int Power_UP();
  Power_UP();
  int RuleDefining();
  RuleDefining();
}

void loop() {
  //Boolean values defined for the User LEDs
  bool Blue = digitalRead(BlueButton);
  bool Green = digitalRead(GreenButton);
  bool Red = digitalRead(RedButton);
  bool Purple = digitalRead(PurpleButton);
  
  //Defined Musics for Victory and Defeat
  int DancyDance();
  int Cry();
  
  //function for the Center LED
  value();
  String ColorState = value();
  //Serial.println(ColorState);//Used for Troubleshooting
  
  //If center color is the same as User color
  if (Blue == 1) {
    //Victory
    if (ColorState == "Blue") {
      Serial.println("Win");
      delay(500);
      DancyDance();
    //Defeat
    } else {
      Serial.println("Lose");
      delay(500);
      Cry();
    }
  }

  else if (Green == 1) {
    if (ColorState == "Green") {
      Serial.println("Win");
      delay(500);
      DancyDance();
    } else {
      Serial.println("Lose");
      delay(500);
      Cry();
    }
  }

  else if (Red == 1) {
    if (ColorState == "Red") {
      Serial.println("Win");
      delay(500);
      DancyDance();
    } else {
      Serial.println("Lose");
      delay(500);
      Cry();
    }
  }

  else if (Purple == 1) {
    if (ColorState == "Purple") {
      Serial.println("Win");
      delay(500);
      DancyDance();
    } else {
      Serial.println("Lose");
      delay(500);
      Cry();
    }
  }
}

//Variables used for the millis function
int NewMillis = 0;
int val = 0;

String value() {
  
  //CurrentMillis = Amount of milliseconds passed since the powered
  int CurrentMillis = millis();
  int WaitingTime = 500;
  
  //random seed pulled from A0 whose value is random since this is disconnected
  randomSeed(analogRead(0));
  
  //if the amount of seconds minus NewMillis greater or equal to 500ms
  if (CurrentMillis - NewMillis >= WaitingTime) {
    //Generate new random value
    val = random(0, 6);
    NewMillis = CurrentMillis;
    //Serial.println(val);//Used for troubleshooting
  }

  String Color;
  
  //Random Value Switch
  switch (val) {
    //If random value is 0 Red is the color shown
    case 0:
      Color = "Red";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, OFF);
      digitalWrite(BLed, OFF);
      break;

    case 1:
      Color = "Purple";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, OFF);
      digitalWrite(BLed, ON);
      break;

    case 2:
      Color = "Blue";
      digitalWrite(RLed, OFF);
      digitalWrite(GLed, OFF);
      digitalWrite(BLed, ON);
      break;

    case 3:
      Color = "Cyan";
      digitalWrite(RLed, OFF);
      digitalWrite(GLed, ON);
      digitalWrite(BLed, ON);
      break;
    case 4:
      Color = "Green";
      digitalWrite(RLed, OFF);
      digitalWrite(GLed, ON);
      digitalWrite(BLed, OFF);
      break;

    case 5:
      Color = "Yellow";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, ON);
      digitalWrite(BLed, OFF);
      break;

    case 6:
      Color = "White";
      digitalWrite(RLed, ON);
      digitalWrite(GLed, ON);
      digitalWrite(BLed, ON);
      break;

    default:
      Color = "Value not Supported";
      break;
  }
  return Color;
}

int DancyDance() {
  
  // All User LEDs go off
  digitalWrite(BlueLed, OFF);
  digitalWrite(GreenLed, OFF);
  digitalWrite(RedLed, OFF);
  digitalWrite(PurpleLed, OFF);

  //Used to read Used LEDs state
  bool state = 0;
  int end = 1;
  int Win();
  Win();

  while (end != 0) {

    int CurrentMillis = millis();
    int WaitingTime = 500;

    if (CurrentMillis - NewMillis >= WaitingTime) {
      if (state == 1) {
        digitalWrite(BlueLed, ON);
        digitalWrite(GreenLed, ON);
        digitalWrite(RedLed, ON);
        digitalWrite(PurpleLed, ON);
        state = 0;
        Serial.println("ON");
      } else {
        digitalWrite(BlueLed, OFF);
        digitalWrite(GreenLed, OFF);
        digitalWrite(RedLed, OFF);
        digitalWrite(PurpleLed, OFF);
        state = 1;
        Serial.println("OFF");
      }
      NewMillis = CurrentMillis;
    }

    bool Blue = digitalRead(BlueButton);
    bool Green = digitalRead(GreenButton);
    bool Red = digitalRead(RedButton);
    bool Purple = digitalRead(PurpleButton);

    if (
      //Any of the buttons is pressed
      Blue == 1 or Green == 1 or Red == 1 or Purple == 1) {
      //Game Ends
      end = 0;
      Serial.println("Resume");
      delay(500);
      //All User LEDs turn ON
      digitalWrite(BlueLed, ON);
      digitalWrite(GreenLed, ON);
      digitalWrite(RedLed, ON);
      digitalWrite(PurpleLed, ON);
    } else {
      end = 1;
    }
  }
  //Rules Change as its gingle plays
  int Rules();
  Rules();
  RuleDefining();
}

int Cry() {
  digitalWrite(BlueLed, OFF);
  digitalWrite(GreenLed, OFF);
  digitalWrite(RedLed, OFF);
  digitalWrite(PurpleLed, OFF);

  bool state = 0;
  int end = 1;
  int Lose();
  Lose();

  while (end != 0) {

    int CurrentMillis = millis();
    int WaitingTime = 1000;

    if (CurrentMillis - NewMillis >= WaitingTime) {
      if (state == 1) {
        digitalWrite(BlueLed, ON);
        digitalWrite(GreenLed, ON);
        digitalWrite(RedLed, ON);
        digitalWrite(PurpleLed, ON);
        state = 0;
        Serial.println("ON");
      } else {
        digitalWrite(BlueLed, OFF);
        digitalWrite(GreenLed, OFF);
        digitalWrite(RedLed, OFF);
        digitalWrite(PurpleLed, OFF);
        state = 1;
        Serial.println("OFF");
      }
      NewMillis = CurrentMillis;
    }

    bool Blue = digitalRead(BlueButton);
    bool Green = digitalRead(GreenButton);
    bool Red = digitalRead(RedButton);
    bool Purple = digitalRead(PurpleButton);

    if (
      Blue == 1 or Green == 1 or Red == 1 or Purple == 1) {
      end = 0;
      Serial.println("Resume");
      delay(500);
      digitalWrite(BlueLed, ON);
      digitalWrite(GreenLed, ON);
      digitalWrite(RedLed, ON);
      digitalWrite(PurpleLed, ON);
    } else {
      end = 1;
    }
  }
  int Rules();
  Rules();
  RuleDefining();
}

int RuleDefining() {

  randomSeed(analogRead(0));

  Serial.println();

  int bit0 = random(0, 2);
  int bit1 = random(0, 2);
  int bit2 = random(0, 2);
  int bit3 = random(0, 2);
  
  Serial.println(bit0);
  Serial.println(bit1);
  Serial.println(bit2);
  Serial.println(bit3);
  
  digitalWrite(LedGame1, bit1);
  digitalWrite(LedGame2, bit2);
  digitalWrite(LedGame3, bit3);
  digitalWrite(LedGame0, bit0);

}
