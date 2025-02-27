#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
#include "Headers/Ant.hpp"

using namespace std;

class LinkedList {
private:
    Ant* head;

public:
    LinkedList();
    ~LinkedList();
    void addAntAtEnd(int data);
    void deleteByValue(int data);
    void printList();
    Ant& getAnt(int data);
    int size();
};

#endif // LINKEDLIST_HPP