//
// Created by Ryan Philipps on 07/07/2018.
//

#ifndef BBOARD_SERVOMOTOR_H
#define BBOARD_SERVOMOTOR_H

#include <Servo.h>

class ServoMotor {
private:
    Servo servo;

public:
    ServoMotor(int pin);
    ~ServoMotor();

    void moveToAngle(int angle);

    int getAngle();
};


#endif //BBOARD_SERVOMOTOR_H
