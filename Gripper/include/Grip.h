#ifndef GRIP_H
#define GRIP_H

#include <Pins.h>
#include <Arduino.h>
#include <Sensors.h>

void resetGrip() {
    gripServo.write(100); // Open the grip
    gripClosed = false;   // Reset the flag
}

void closeGrip() {
    gripServo.write(0); 
    gripClosed = true;    // Set flag to keep grip closed
}

void checkGrip() {
    if (distance > 1 && distance <= threshold) {
        readSensors();
        delay(2000);
        readSensors();
        
        if (Object) { // White surface detected
            Serial.println("White surface detected");
            if (!gripClosed) {
                resetGrip(); // Keep the grip open
            }
        } 
        else if (!Object) { // Black surface detected
            Serial.println("Black surface detected");
            if (!gripClosed) {
                closeGrip(); // Close grip for black object
            }
        } 
        else {
            Serial.println("No clear color detected");
        }
    }
}

#endif
