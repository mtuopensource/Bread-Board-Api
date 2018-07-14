//
// Created by Ryan Philipps on 07/07/2018.
//

#include "ServoMotor.h"


ServoMotor::ServoMotor(int pin) {
    servo.attach(pin);
}

ServoMotor::~ServoMotor() {
    servo.detach();
}

void ServoMotor::moveToAngle(int angle) {
    if (angle > 180)
        servo.write(180);
    else if (angle < 0)
        servo.write(0);
    else
        servo.write(angle);
}

int ServoMotor::getAngle() {
    return servo.read();
}