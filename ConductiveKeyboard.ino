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
const int INDICATOR_LED = 13;

//Variables
int dState = 0;
int fState = 0;
int jState = 0;
int kState = 0;

void setup()
{
  //Initialize input
  pinMode(BUTTON_D, INPUT);
  pinMode(BUTTON_F, INPUT);
  pinMode(BUTTON_J, INPUT);
  pinMode(BUTTON_K, INPUT);

  //Initialize output
  pinMode(INDICATOR_LED, OUTPUT);

  Keyboard.begin();
}

void loop()
{
  //Get button state
  dState = digitalRead(BUTTON_D);
  fState = digitalRead(BUTTON_F);
  jState = digitalRead(BUTTON_J);
  kState = digitalRead(BUTTON_K);

  digitalWrite(INDICATOR_LED, HIGH);
    
  //Output
  if(dState == LOW)
  {
    Keyboard.press('d');
  }
  else
  {
    Keyboard.release('d');
  }
    
  if(fState == LOW)
  {
    Keyboard.press('f');
  }
  else
  {
    Keyboard.release('f');
  }
    
  if(jState == LOW)
  {
    Keyboard.press('j');
  }
  else
  {
    Keyboard.release('j');
  }
    
  if(kState == LOW)
  {
    Keyboard.press('k');
  }
  else
  {
    Keyboard.release('k');
  }
}
