#include "Headers/Ant.hpp"

Ant::Ant() {
    position = "Chamber Sv";
}

Ant::Ant(int value) {
    position = "Sv";
    data = value;
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

void Ant::checkNextChamber(Chamber& chamber) {
    if (chamber.getCurrentAnts() < chamber.getMaxAnts()) {
        chamber.addAnt();
        move(chamber.getName());
        stay();
    } else {
        cout << "Chamber " << chamber.getName() << " is full." << endl;
        stay();
    }
}

