#include "Headers/Ant.hpp"

Ant::Ant() {
    position = "Sv";
}

void Ant::lookAround() {
    cout << "I'm looking around." << endl;
}

void Ant::move(string target) {
    cout << "I'm moving to " << target << endl;
    setPosition(target);
}

void Ant::stay() {
    cout << "I'm staying at " << this->position << endl;
}

void Ant::setPosition(string position) {
    this->position = position;
}

string Ant::getPosition() {
    return position;
}
