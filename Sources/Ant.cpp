#include "Headers/Ant.hpp"

Ant::Ant() {
    position = "Sv";
}

void Ant::lookAround() {
    cout << "I'm looking around." << endl;
}

void Ant::move() {
    cout << "I'm moving." << endl;
}

void Ant::stay() {
    cout << "I'm staying." << endl;
}

void Ant::setPosition(string position) {
    this->position = position;
}

string Ant::getPosition() {
    return position;
}
