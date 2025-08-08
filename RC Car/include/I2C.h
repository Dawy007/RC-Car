
#ifndef I2C_H
#define I2C_H
#include <Pins_Var.h>
#include <Wire.h>
#include <string.h>

// Variables for gripper control
bool ready_pick = false;
bool picked = false;

void receiveEvent(int numBytes) {
  String receivedMessage = "";
  while (Wire.available()) {
    char c = Wire.read();
    receivedMessage += c;
  }

  if (receivedMessage.startsWith("U")) {
    // recives if the ultrasonic detects an object to pick infront of the car
    ready_pick = receivedMessage.charAt(1) == '1';
  } else if (receivedMessage.startsWith("G")) {
    // recives weather the gripper is eaither closed or opened
    picked = receivedMessage.charAt(1) == '1';
  }
}

void requestEvent() {
  // sends weather the car has reached the end of the maze to open the gripper and drops the object
  Wire.write("X");
}

#endif
