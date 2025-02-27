#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <vector>
#include <iostream>
#include <queue>
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
    vector<int> findPathBFS(int startChamber, int endChamber);
    void printPath(const vector<int>& path);

private:
    vector<vector<int>> anthill;
    int numberOfChambers;
};

#endif