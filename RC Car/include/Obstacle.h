
#ifndef Obstacle_H
#define Obstacle_H
#include <Arduino.h>
#include <Pins_Var.h>
#include <Sensors.h>
#include <Motors.h>
#include <Delays.h>
#include <I2C.h>

void Obstacle() {
  sensorsRead();
  if (farLeft && Left && Center && Right && farRight) {
    stopMotors();
    Wire.onRequest(requestEvent);
  }
  // Turn left when a left path is detected.
  else if (farLeft && !goLeft && leftFree) {
    goLeft = true;
    breakLeft();
  }
  // Spin left when no line is detected.
  else if (!farLeft && !Left && !Center && !Right && !farRight && goLeft) {
    spinLeft();
  }
  else if (!farLeft && !Left && !Center && !Right && !farRight && goRight) {
    spinRight();
  }
  // Line centering.
  else if (forwardFree && 
          ((!farLeft && !Left && Center && !Right && !farRight && !goLeft) || 
          (farLeft && Center && !leftFree))) {
    Forward();
  }
  // Slightly right line follower.
  else if (!farLeft && !Left && Right && !farRight && !goLeft && forwardFree) {
    goRight = true;
    turnRight();
  }
  // Slightly left line follower.
  else if (!farLeft && Left && !Right && !farRight && !goLeft && forwardFree) {
    goLeft = true;
    turnLeft();
  }
  // Move forward when forward and right paths are detected.
  else if (!farLeft && Center && farRight && !goLeft) {
    Forward();
  }
  
  else if (rightFree) {
    // move right when only right path is detected.
    if (!farLeft && !Center && farRight && !goLeft) {
      goRight = true;
      breakRight();
    }
    // move right when there are only paths forward and right but the forward lane is blocked.
    else if (!farLeft && farRight && !goLeft && !forwardFree) {
      goRight = true;
      breakRight();
    }
    // move right when only left and right are detected but the left lane is blocked.
    else if (farLeft && farRight && !goLeft && !leftFree) {
      goRight = true;
      breakRight();
    }
    // move right when there is left, forward and right but only right is free.
    else if (farLeft && farRight && !goLeft && !leftFree && !forwardFree) {
      goRight = true;
      breakRight();
    }
  }
  else if (!leftFree && !forwardFree && !rightFree) {
    // turn the car around if there is no free lane.
    if (goRight) {
      spinRight();
    }
    else if (goLeft) {
      spinLeft();
    }
  }
  delays();
}

#endif
