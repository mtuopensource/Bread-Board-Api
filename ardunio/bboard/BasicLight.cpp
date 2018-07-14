//
// Created by Ryan Philipps on 06/07/2018.
//
#include <Arduino.h>
#include "BasicLight.h"


BasicLight::BasicLight(int powerPin){
    this->pin = static_cast<uint8_t >(powerPin);
    pinMode(pin, OUTPUT);
}

BasicLight::~BasicLight(){
    turnOff();
}

void BasicLight::turnOn() {
    digitalWrite(pin, HIGH);
}

void BasicLight::turnOff() {
    digitalWrite(pin, LOW);
}


