#ifndef I2C_H
#define I2C_H

#include <Arduino.h>
#include <Pins.h>
#include <Wire.h>
#include <Sensors.h>
#include <Grip.h>

String getMessageUS(float distance) {
    String message = "U"; // Start with 'U' as a command identifier

    if (distance > 7 && distance <= threshold) {
        message += '1'; // Blocked
    } else {
        message += '0'; // Clear
    }
    return message;
}

String getMessageGR() {
    String message = "G"; // Start with 'G' as a command identifier

    if (gripClosed == 1) {
        message += '1'; // Closed
    } else {
        message += '0'; // Open
    }
    return message;
}

void sendData() {
    readSensors();
    String messageUS = getMessageUS(distance);
    String messageGR = getMessageGR();

    // Send messages over I2C
    Wire.beginTransmission(8);
    Wire.write(messageUS.c_str()); // Send obstacle data
    Wire.endTransmission();

    Wire.beginTransmission(8);
    Wire.write(messageGR.c_str()); // Send gripper data
    Wire.endTransmission();
}

void receiveData() {
    Wire.requestFrom(8, 16); // Request 16 bytes from Slave address 8
    while (Wire.available()) {
        char c = Wire.read(); // Receive a byte
        Serial.println(c); // Print it to the Serial Monitor
        if (c == 'X') {
            resetGrip();
        }
    }
}

#endif
