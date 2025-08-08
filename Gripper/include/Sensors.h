#ifndef SENSORS_H
#define SENSORS_H

#include <Pins.h>
#include <Arduino.h>

// Function to measure distance using the ultrasonic sensor
float measureDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.034) / 2; // Convert to cm
    return distance;
}

// Function to read sensor data
void readSensors() {
    distance = measureDistance(); // Get the current distance
    Object = digitalRead(IR_PIN); // Read the IR sensor state
}

#endif
