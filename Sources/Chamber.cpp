#include "Headers/Chamber.hpp"

Chamber::Chamber(string name, int maxAnts) {
    this->name = name;
    this->maxAnts = maxAnts;
}

Chamber::~Chamber() {}

void Chamber::addAnt() {
    if (currentAnts < maxAnts) {
        currentAnts++;
    } else {
        cout << "Chamber " << name << " is full." << endl;
    }
}

void Chamber::removeAnt() {
    if (currentAnts > 0) {
        currentAnts--;
    } else {
        cout << "Chamber " << name << " is empty." << endl;
    }
}

void Chamber::printChamber() {
    cout << "Chamber " << name << " has " << currentAnts << " ants." << endl;
}

int Chamber::getAnts() {
    return currentAnts;
}

int Chamber::getMaxAnts() {
    return maxAnts;
}

string Chamber::getName() {
    return name;
}