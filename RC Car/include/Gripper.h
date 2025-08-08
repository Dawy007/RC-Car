
#ifndef Gripper_H
#define Gripper_H
#include <Arduino.h>
#include <LineFollower.h>
#include <Obstacle.h>
#include <I2C.h>

// Gripper control logic
void gripper() {
  sensorsRead(); // takes the readings of the sensors
  Wire.onReceive(receiveEvent); // translates the receives data from the gripper
  Serial.print("ready_pick: "); // prints the values for monitoring
  Serial.println(ready_pick); // prints the values for monitoring
  Serial.print("picked: "); // prints the values for monitoring
  Serial.println(picked); // prints the values for monitoring

  if (!ready_pick && !picked) {
    // the car moves as a line follower until it faces an object
    LineFollower();
    Serial.println("maze"); // prints the value for monitoring
  } else if (ready_pick && !picked) {
    // the car stops when it faces an object
    stopMotors();
    Serial.println("stop"); // prints the value for monitoring
  } else {
    // the car moves in the obstacle avoidance code when it has picked the object
    Obstacle();
    Serial.println("obstacle"); // prints the value for monitoring
  }
}

#endif
