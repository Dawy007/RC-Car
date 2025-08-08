#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Pins.h>
#include <Sensors.h>
#include <I2C.h>
#include <Grip.h>

void setup() {
    Wire.begin(); // Initialize I2C communication with the second Arduino
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(IR_PIN, INPUT);
    gripServo.attach(SERVO_PIN); // Attach the servo motor to the defined pin
    resetGrip(); // Initialize the grip state
    Serial.begin(9600); // Start serial communication
}

void loop() {
    readSensors();    // Read sensor data
    checkGrip();      // Adjust grip based on sensor data
    delay(100);       // Adjust delay for stability
    sendData();       // Send data over I2C
    receiveData();    // Receive data over I2C
}
