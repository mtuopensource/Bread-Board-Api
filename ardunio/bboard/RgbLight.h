//
// Created by Ryan Philipps on 06/07/2018.
//
#include "Light.h"
#include <cstdlib>

#ifndef BBOARD_RGBLIGHT_H
#define BBOARD_RGBLIGHT_H


class RgbLight: public Light {
private:
    uint8_t redPin = 0, greenPin = 0 , bluePin = 0;

    int redValue = 255, greenValue = 255, blueValue = 255; // default ot white color

public:
    RgbLight(int red, int green, int blue);
    ~RgbLight();

    void turnOn();
    void turnOff();

    void changeColor(int red, int green, int blue);

private:
    int adjustValue(int value);
};


#endif //BBOARD_RGBLIGHT_H
