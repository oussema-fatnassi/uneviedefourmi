#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <vector>
#include <iostream>
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

private:
    vector<vector<int>> anthill;
    int numberOfChambers;
};

#endif