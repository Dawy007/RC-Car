#ifndef Pins_Var_H
#define Pins_Var_H
#include <SoftwareSerial.h>
#include <Arduino.h>

// Bluetooth pins and variables
SoftwareSerial bluetooth(2, 3); // RX Pin on 2, TX Pin on 3

// Motor control pins
#define RIGHT_MOTOR_SPEED 11 // controls the speed on the right motors
// controls the direction of the right motors
#define RIGHT_MOTOR_BACKWARD 10
#define RIGHT_MOTOR_FORWARD 9

#define LEFT_MOTOR_SPEED 6 // controls the speed on the left motors
// controls the direction of the leftt motors
#define LEFT_MOTOR_FORWARD 8
#define LEFT_MOTOR_BACKWARD 7

// Sensor pins for detecting the path
#define centerSensor A2    // Center line sensor
#define rightSensor A1     // Right line sensor
#define leftSensor A3      // Left line sensor
#define farLeftSensor A0   // Far left line sensor
#define farRightSensor 4   // Far right line sensor

// IR Obstacle detection pins
#define IRLeft 5 // Obstacle detection on left
#define IRCenter 13 // Obstacle detection on center
#define IRRight 12 // Obstacle detection on right

#endif
