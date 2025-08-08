
#ifndef LineFollower_H
#define LineFollower_H
#include <Pins_Var.h>
#include <Arduino.h>
#include <Delays.h>
#include <Sensors.h>
#include <Motors.h>

// Maze solver code
void LineFollower() {
  sensorsRead();
  // Stop the car when it reaches the end of the maze
  if (farLeft && Left && Center && Right && farRight) {
    stopMotors();
  } 
  // Turn left when there is a left path detected
  else if (farLeft && !goLeft) {
    goLeft = true;
    breakLeft();
  } 
  // Spin left when no line is detected
  else if (!farLeft && !Left && !Center && !Right && !farRight && goLeft) {
    spinLeft();
  } 
  else if (!farLeft && !Left && !Center && !Right && !farRight && goRight) {
    spinRight();
  }
  // Line centering
  else if (!farLeft && !Left && Center && !Right && !farRight && !goLeft) {
    Forward();
    goRight = true;
  } 
  // Turn slightly right line follower
  else if (!farLeft && !Left && Right && !farRight && !goLeft) {
    goRight = true;
    turnRight();
  } 
  // Turn slightly left line follower
  else if (!farLeft && Left && !Right && !farRight && !goLeft) {
    goLeft = true;
    turnLeft();
  } 
  // Move forward when forward and right are detected
  else if (!farLeft && Center && farRight && !goLeft) {
    Forward();
  } 
  // Turn right if there is only a right path
  else if (!farLeft && !Left && !Center && !Right && farRight && !goLeft) {
    goRight = true;
    breakRight();
  }
  // adjust the delays for the turning 
  delays();
}

#endif
