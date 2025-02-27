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
    void removeAnt();
    int getCurrentAnts();
    void addAnts(int ants);
    int getMaxAnts() const;
    string getName() const;
    Chamber* getNextChamber(const vector<int> path, string chamberName);

private:
    string name;
    int currentAnts = 0;
    int maxAnts;
};

#endif