/*
 * Conductive Object Keyboard
 * 
 * Allows button input from any conductive object, 
 * by using the user to complete the circuit
 * 
 * Author: Chad Humphries
 * Date: September 10th, 2019
 * Verson: 1.0
 */

#include <Keyboard.h>

//Constants
const int BUTTON_D = 2;
const int BUTTON_F = 3;
const int BUTTON_J = 4;
const int BUTTON_K = 5;
const int TOGGLE = 6;
const int INDICATOR_LED = 13;

//Variables
int dState = 0;
int fState = 0;
int jState = 0;
int kState = 0;
int toggleState = 0;

void setup()
{
  //Initialize input
  pinMode(BUTTON_D, INPUT);
  pinMode(BUTTON_F, INPUT);
  pinMode(BUTTON_J, INPUT);
  pinMode(BUTTON_K, INPUT);

  //Initialize output
  pinMode(TOGGLE, OUTPUT);

  Keyboard.begin();
}

void loop()
{
  //Get button state
  dState = digitalRead(BUTTON_D);
  fState = digitalRead(BUTTON_F);
  jState = digitalRead(BUTTON_J);
  kState = digitalRead(BUTTON_K);
  toggleState = digitalRead(TOGGLE);

  //Toggle keyboard on and off
  if(toggleState == HIGH)
  {
    digitalWrite(INDICATOR_LED, HIGH);
    
    //Output
    if(dState == HIGH)
    {
      Keyboard.write('d');
    }
    if(fState == HIGH)
    {
      Keyboard.write('f');
    }
    if(jState == HIGH)
    {
      Keyboard.write('j');
    }
    if(kState == HIGH)
    {
      Keyboard.write('k');
    }
  }
  else
  {
    digitalWrite(INDICATOR_LED, LOW);
  }
}
