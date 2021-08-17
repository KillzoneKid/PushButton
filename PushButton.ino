/*
 Name:		PushButton.ino
 Created:	4/12/2021 9:47:15 AM
 Author:	KK
*/

#include "PushButton.h"

#define button1pin 1 // change
#define button2pin 2 // change

// state 0 - released
// state 1 - pressed
// state 2 - pressed and held

PushButton button1 = PushButton(button1pin, [](ButtonState state, PushButton* button) { Serial.print("Button1 state: "); Serial.println(state); });
PushButton button2 = PushButton(button2pin, [](ButtonState state, PushButton* button) { Serial.print("Button2 state: "); Serial.println(state); });


void setup() 
{
	Serial.begin(9600);
}

void loop() 
{
  button1.Simulate();
  button2.Simulate();
}
