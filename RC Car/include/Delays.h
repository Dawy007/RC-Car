
#ifndef Delays_H
#define Delays_H
#include <Pins_Var.h>
#include <Arduino.h>

// Delay time for the timer function
const unsigned long delayTime = 150; 

// Variables for delay control
bool delayed1 = false;
bool delayed2 = false;

// Variables for delay functions (timerClock 1, 2)
unsigned long timeMillis1 = 0;
unsigned long timeMillis2 = 0;

// Variables for movement direction
bool goLeft = false;
bool goRight = false;

// Timer functions for creating delays for turning
void timerClockLeft(unsigned long &previousMillis) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;
    delayed1 = !delayed1;
  }
}

void timerClockRight(unsigned long &previousMillis) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;
    delayed2 = !delayed2;
  }
}

void delays() {
  // Delay logic for turning left
  if (goLeft) {
    timerClockLeft(timeMillis1);
    if (delayed1) {
      goLeft = false;
    }
  }

  // Delay logic for turning right
  if (goRight) {
    timerClockRight(timeMillis2);
    if (delayed2) {
      goRight = false;
    }
  }
}

#endif
