#include "Headers/Anthill.hpp"

Anthill::Anthill(int numberOfChambers) {
    chambers.resize(numberOfChambers);
    this->numberOfChambers = numberOfChambers;
    anthill.resize(numberOfChambers);
    for (int i = 0; i < numberOfChambers; i++) {
        anthill[i].resize(numberOfChambers);   
    }
}

Anthill::~Anthill() {
    anthill.clear();
}

void Anthill::addTunnel(int chamberIndex1, int chamberIndex2) {
    if(chamberIndex1 >= numberOfChambers || chamberIndex2 >= numberOfChambers) {
        cout << "Invalid chamber index." << endl;
        return;
    }
    anthill[chamberIndex1][chamberIndex2] = 1;
    anthill[chamberIndex2][chamberIndex1] = 1;
}


void Anthill::printAnthill() {
    for (int i = 0; i < numberOfChambers; i++) {
        for (int j = 0; j < numberOfChambers; j++) {
            cout << anthill[i][j] << " ";
        }
        cout << endl;
    }
}

void Anthill::printNumberOfAnts() {
    for (int i = 0; i < numberOfChambers; i++) {
        cout << "Chamber " << chambers[i].getName() << " has " << chambers[i].getMaxAnts() << " ants." << endl;
    }
}