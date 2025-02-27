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
    int getCurrentAnts();
    void addAnts(int ants);
    int getMaxAnts();
    string getName();
    Chamber* getNextChamber(const vector<int> path, string chamberName);

private:
    string name;
    int currentAnts = 0;
    int maxAnts;
};

#endif