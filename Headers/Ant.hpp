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
    int actualPathIndex;

    void move(string target);
    void setPosition(string position);
    string getPosition();

private:
    string position;
};

#endif // ANT_HPP