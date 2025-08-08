
#include <Arduino.h>
#include <RC_Car.h>

void setup() {
  // Set motor control pins as output
  pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
  pinMode(LEFT_MOTOR_SPEED, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);

  // Set sensor pins as input
  pinMode(farLeftSensor, INPUT);
  pinMode(farRightSensor, INPUT);
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Set obstacle detection IR pins as input
  pinMode(IRLeft, INPUT);
  pinMode(IRCenter, INPUT);
  pinMode(IRRight, INPUT);

  // Start serial communication for debugging and Bluetooth
  Serial.begin(9600);
  bluetooth.begin(9600);

  // Start I2C communication with address 8
  Wire.begin(8);
}

void loop() {
  // Execute the RC car control function
  RC_car();
}
