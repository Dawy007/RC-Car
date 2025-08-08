
#ifndef Motors_H
#define Motors_H
#include <Pins_Var.h>
#include <Arduino.h>

const int SPEED = 70; // Setting the speed of the motors

// Function to control motor states
void setMotorState(int leftSpeed, int leftDir, int rightSpeed, int rightDir) {
  analogWrite(RIGHT_MOTOR_SPEED, rightSpeed);
  digitalWrite(RIGHT_MOTOR_FORWARD, rightDir == 1);
  digitalWrite(RIGHT_MOTOR_BACKWARD, rightDir == -1);

  analogWrite(LEFT_MOTOR_SPEED, leftSpeed);
  digitalWrite(LEFT_MOTOR_FORWARD, leftDir == 1);
  digitalWrite(LEFT_MOTOR_BACKWARD, leftDir == -1);
}

// Movement functions for the robot
void Forward() {
  // moves the car forward
  setMotorState(SPEED, 1, SPEED, 1);
}
void Backward() {
  // moves the car backwards
  setMotorState(SPEED, -1, SPEED, -1);
}
void spinLeft() {
  // spin the car around its center to the left
  setMotorState(1.5 * SPEED, -1, 1.5 * SPEED, 1);
}
void spinRight() {
  // spin the car around its center to the right
  setMotorState(1.5 * SPEED, 1, 1.5 * SPEED, -1);
}
void turnLeft() {
  // spin the car arround its left wheel
  setMotorState(0, -1, 1.5 * SPEED, 1);
}
void turnRight() {
  // spin the car arround its right wheel
  setMotorState(1.5 * SPEED, 1, 0, -1);
}
void slightlyLeft() {
  // move forward but slightly left
  setMotorState(SPEED / 2, 1, 2 * SPEED, 1);
}
void slightlyRight() {
  // move forward but slightly right
  setMotorState(2 * SPEED, 1, SPEED / 2, 1);
}
void slightlyLeftBack() {
  // move backward but slightly left
  setMotorState(SPEED / 2, -1, 2 * SPEED, -1);
}
void slightlyRightBack() {
  // move backward but slightly right
  setMotorState(2 * SPEED, -1, SPEED / 2, -1);
}
void breakLeft() {
  // spin around center to the left with max speed for fast turning
  setMotorState(255, -1, 255, 1);
}
void breakRight() {
  // spin around center to the right with max speed for fast turning
  setMotorState(255, 1, 255, -1);
}
void stopMotors() {
  // stop all motors of the car
  setMotorState(0, 0, 0, 0);
}

// Function to test motor movement
void testMotors() {
  Forward();
  delay(2500);
  Backward();
  delay(2500);
  turnLeft();
  delay(2500);
  turnRight();
  delay(2500);
}

#endif
