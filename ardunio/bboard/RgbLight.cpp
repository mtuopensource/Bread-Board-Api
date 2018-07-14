//
// Created by Ryan Philipps on 06/07/2018.
//
#include <Arduino.h>
#include "RgbLight.h"


RgbLight::RgbLight(int red, int green, int blue) {
    this->redPin   = static_cast<uint8_t>(red);
    this->greenPin = static_cast<uint8_t>(green);
    this->bluePin  = static_cast<uint8_t>(blue);

    pinMode(this->redPin, OUTPUT);
    pinMode(this->greenPin, OUTPUT);
    pinMode(this->bluePin, OUTPUT);
}

RgbLight::~RgbLight(){
    turnOff();
}


void RgbLight::turnOn() {
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}

void RgbLight::turnOff() {
    analogWrite(redPin, LOW);
    analogWrite(greenPin, LOW);
    analogWrite(bluePin, LOW);
}

void RgbLight::changeColor(int red, int green, int blue) {
    this->redValue = adjustValue(red);
    this->greenValue = adjustValue(green);
    this->blueValue = adjustValue(blue);
    turnOn();
}


int RgbLight::adjustValue(int value) {
    if (value > 255)
        return 255;
    else if (value < 0)
        return 0;
    else
        return value;
}