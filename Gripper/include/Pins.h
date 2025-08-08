#ifndef PINS_H
#define PINS_H

#include <Servo.h> // Include the Servo library

// Pin Definitions
#define IR_PIN 7        // IR sensor analog pin
#define TRIG_PIN 4      // Ultrasonic sensor trigger pin
#define ECHO_PIN 5      // Ultrasonic sensor echo pin
#define SERVO_PIN 9     // Servo signal pin

// Global Variables
bool gripClosed = false;
int Object;
const unsigned int threshold = 14; // Distance threshold in cm
Servo gripServo;
String message;
String messageUS;
String messageGR;
float distance;

#endif
