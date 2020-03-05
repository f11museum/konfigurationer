/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int button01 = 2;
const int button02 = 3;
const int button03 = 4;
const int button04 = 5;

const int button11 = 6;
const int button12 = 7;
const int button13 = 8;
const int button14 = 9;
const int button15 = 10;
const int button16 = 14;

const int button17 = 15;

bool pressed[25];

void setup() {
  // make the pushButton pin an input:
  pinMode(button01, INPUT_PULLUP);
  pinMode(button02, INPUT_PULLUP);
  pinMode(button03, INPUT_PULLUP);
  pinMode(button04, INPUT_PULLUP);

  pinMode(button11, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
  pinMode(button13, INPUT_PULLUP);
  pinMode(button14, INPUT_PULLUP);
  pinMode(button15, INPUT_PULLUP);
  pinMode(button16, INPUT_PULLUP);
  
  pinMode(button17, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void checkbutton(int button, int key) {
  if (!digitalRead(button) ) {
    if (!pressed[button]) {
      Keyboard.write(key);
      pressed[button] = true;
      delay(500);
    }
  }else {
    if (pressed[button]) {
      delay(100);
    }
    pressed[button] = false;
    
  }
}
void loop() {
  checkbutton(button01, KEY_F1);
  checkbutton(button02, KEY_F2);
  checkbutton(button03, KEY_F10);
  checkbutton(button04, KEY_F9);
  
  checkbutton(button11, KEY_F8);
  checkbutton(button12, KEY_F7);
  checkbutton(button13, KEY_F6);

  checkbutton(button14, KEY_F5);
  checkbutton(button15, KEY_F1);
  checkbutton(button16, KEY_F2);

  checkbutton(button17, KEY_F3);
}
