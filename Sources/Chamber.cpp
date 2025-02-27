#include "Headers/Chamber.hpp"

Chamber::Chamber(string name, int maxAnts) {
    this->name = name;
    this->maxAnts = maxAnts;
}

Chamber::~Chamber() {}


void Chamber::removeAnt() {
    if (currentAnts > 0) {
        currentAnts--;
    } else {
        cout << "Chamber " << name << " is empty." << endl;
    }
}

int Chamber::getCurrentAnts() {
    return currentAnts;
}

int Chamber::getMaxAnts() const {
    return maxAnts;
}

string Chamber::getName() const {
    return name;
}

void Chamber::addAnts(int ants) {
    // Allow infinite ants for Sv and Sd
    if (maxAnts == -1) {
        currentAnts += ants;
        return;
    }

    // Regular chamber logic
    if (currentAnts + ants <= maxAnts) {
        currentAnts += ants;
    } else {
        cout << "Chamber " << name << " is full." << endl;
    }
}
