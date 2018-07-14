//
// Created by Ryan Philipps on 08/07/2018.
//
#include <Arduino.h>
#ifndef BBOARD_BUZZER_H
#define BBOARD_BUZZER_H


class Buzzer {

private:
    uint8_t pin;
public:
    explicit Buzzer(int pin);
    ~Buzzer();

    void play(unsigned int pitch);
    void play(unsigned int pitch, unsigned int duration);

    void silence();

};


#endif //BBOARD_BUZZER_H
