
#ifndef RC_Car_H
#define RC_Car_H
#include <Arduino.h>
#include <Motors.h>
#include <Gripper.h>

char btSignal;

// Bluetooth RC car control
void RC_car() {
  // Check if Bluetooth data is available
  if (bluetooth.available()) {
    btSignal = bluetooth.read();
  }

  // If a signal is received, process the command
  if (btSignal != -1) {
    switch (btSignal) {
      case 'W': Forward(); break;           // Move forward
      case 'S': Backward(); break;          // Move backward
      case 'A': spinLeft(); break;          // Move Spin left
      case 'D': spinRight(); break;         // Move Spin right
      case 'X': stopMotors(); break;        // Stop motors
      case 'Q': slightlyLeft(); break;      // Move Slightly left
      case 'E': slightlyRight(); break;     // Move Slightly right
      case 'Z': slightlyLeftBack(); break;  // Move Slightly left back
      case 'C': slightlyRightBack(); break; // Move Slightly right back
      case 'O': Obstacle(); break;          // Obstacle avoidance Mode
      case 'M': LineFollower(); break;      // Line following Mode
      case 'G': gripper(); break;           // Object Picking Mode
    }
  }
}

#endif
