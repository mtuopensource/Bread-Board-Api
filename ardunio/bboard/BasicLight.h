//
// Created by Ryan Philipps on 06/07/2018.
//
#include "Light.h"

#ifndef BBOARD_BASICLIGHT_H
#define BBOARD_BASICLIGHT_H


class BasicLight: public Light {

private:
    uint8_t pin = 0;
public:
    BasicLight(int powerPin);
    ~BasicLight();

    void turnOn() override ;
    void turnOff() override ;

};


#endif //BBOARD_BASICLIGHT_H
