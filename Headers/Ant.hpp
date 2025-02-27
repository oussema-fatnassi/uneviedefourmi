#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <string>
#include "Chamber.hpp"
using namespace std;

class Ant {
public:
    Ant();
    Ant(int value);
    int data;
    Ant* next;

    void lookAround();
    void move(string target);
    void stay();
    void setPosition(string position);
    string getPosition();
    void checkNextChamber(Chamber& chamber);

private:
    string position;
};

#endif // ANT_HPP