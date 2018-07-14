//
// Created by Ryan Philipps on 08/07/2018.
//

#include "Buzzer.h"

Buzzer::Buzzer(int pin) {
    this->pin = static_cast<uint8_t>(pin);
}

Buzzer::~Buzzer() {
    silence();
}

void Buzzer::play(unsigned pitch) {
    play(pitch, INT8_MAX);
}

void Buzzer::play(unsigned pitch, unsigned int duration) {
    tone(this->pin, pitch, duration);
}

void Buzzer::silence() {
    noTone(this->pin);
}
