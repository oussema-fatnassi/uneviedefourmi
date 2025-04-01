#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#include "Headers/Chamber.hpp"

class Anthill {
public:
    Anthill(int numberOfChambers);
    ~Anthill();
    void addTunnel(int chamberIndex1, int chamberIndex2);
    void printAnthill();
    void printNumberOfAnts();
    vector<Chamber> chambers;
    vector<vector<int>> findAllPathsBFS(int startChamber, int endChamber);
    int getNumberOfChambers() { return numberOfChambers; }

    string getChamberNameByIndex(int index) const;
    int getChamberMaxAntsByName(const string& name) const;

private:
    vector<vector<int>> allPaths;
    vector<vector<int>> anthill;
    int numberOfChambers;
};

#endif