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

void Chamber::printChamber() {
    cout << "Chamber " << name << " has " << currentAnts << " ants." << endl;
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

// Chamber* Chamber::getNextChamber(const vector<int> path, string chamberName) {
//     for (size_t i = 0; i < path.size(); i++) {
//         if (path[i]->getName() == chamberName) {
//             if (i + 1 < path.size()) {
//                 return path[i + 1];
//             } else {
//                 return nullptr; // No next chamber, return nullptr
//             }
//         }
//     }
//     return nullptr; // Chamber not found, return nullptr
// }
