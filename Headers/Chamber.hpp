#ifndef CHAMBER_HPP
#define CHAMBER_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chamber {
public:
    Chamber(string name = "", int maxAnts = 0);
    ~Chamber();
    void addAnt();
    void removeAnt();
    void printChamber();
    int getAnts();
    int getMaxAnts();
    string getName();

private:
    string name;
    int currentAnts = 0;
    int maxAnts;
};

#endif