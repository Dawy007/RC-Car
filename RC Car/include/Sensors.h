
#ifndef Sensors_H
#define Sensors_H
#include <Pins_Var.h>
#include <Arduino.h>
// Variables to store sensor readings
bool Left;
bool Center;
bool Right;
bool farLeft;
bool farRight;

// Variables to handle obstacle avoidance
bool leftFree = true;
bool rightFree = true;
bool forwardFree = true;

// Sensor reading states
#define LINE_DETECTED 0
#define LINE_NOT_DETECTED 1

// Obstacle reading states
#define OBJECT_DETECTED 1
#define OBJECT_NOT_DETECTED 0

// Function to read sensor values
int readSensor(int pin) {
  return digitalRead(pin);
}

// Sensor checking functions
bool isLineCentered() {
  // to detect if the car is on the path
  return readSensor(centerSensor) == LINE_DETECTED;
}
bool isLineOnLeft() {
  // to detect if the car is off the path 
  return readSensor(leftSensor) == LINE_DETECTED;
}
bool isLineOnRight() {
  // to detect if the car is off the path
  return readSensor(rightSensor) == LINE_DETECTED;
}
bool isPathOnFarLeft() {
  // foor detecting left path
  return readSensor(farLeftSensor) == LINE_NOT_DETECTED; // Inverted logic
}
bool isPathOnFarRight() {
  // foor detecting right path
  return readSensor(farRightSensor) == LINE_NOT_DETECTED; // Inverted logic
}
bool isLeftFree() {
  // detects if the left lane is free
  return readSensor(IRLeft) == OBJECT_NOT_DETECTED;
}
bool isForwardFree() {
  // detects if the forward lane is free
  return readSensor(IRCenter) == OBJECT_NOT_DETECTED;
}
bool isRightFree() {
  // detects if the right lane is free
  return readSensor(IRRight) == OBJECT_NOT_DETECTED;
}

// Function to read all sensor states.
void sensorsRead() {
  Left = isLineOnLeft();
  Center = isLineCentered();
  Right = isLineOnRight();
  farLeft = isPathOnFarLeft();
  farRight = isPathOnFarRight();
  leftFree = isLeftFree();
  forwardFree = isForwardFree();
  rightFree = isRightFree();
}

// Function to print sensor states (for debugging).
void sensorsPrint() {
  Serial.print("Left: ");
  Serial.println(Left);
  Serial.print("Center: ");
  Serial.println(Center);
  Serial.print("Right: ");
  Serial.println(Right);
  Serial.print("Far Left: ");
  Serial.println(farLeft);
  Serial.print("Far Right: ");
  Serial.println(farRight);
  Serial.print("Left Free: ");
  Serial.println(leftFree);
  Serial.print("Forward Free: ");
  Serial.println(forwardFree);
  Serial.print("Right Free: ");
  Serial.println(rightFree);
  delay(1500);
}

#endif
