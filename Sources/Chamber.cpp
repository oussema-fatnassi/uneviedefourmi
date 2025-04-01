#include "Headers/Chamber.hpp"

Chamber::Chamber(string name, int maxAnts)
{
    this->name = name;
    this->maxAnts = maxAnts;
}

Chamber::~Chamber() {}

// Remove an ant from the chamber
void Chamber::removeAnt()
{
    if (currentAnts > 0)
    {
        currentAnts--;
    }
    else
    {
        cout << "Chamber " << name << " is empty." << endl;
    }
}

// Getters for current and max ants, and chamber name
int Chamber::getCurrentAnts()
{
    return currentAnts;
}

int Chamber::getMaxAnts() const
{
    return maxAnts;
}

string Chamber::getName() const
{
    return name;
}

// Add ants to the chamber, respecting the maximum capacity
void Chamber::addAnts(int ants)
{
    // Allow infinite ants for Sv and Sd
    if (maxAnts == -1)
    {
        currentAnts += ants;
        return;
    }

    // Regular chamber logic
    if (currentAnts + ants <= maxAnts)
    {
        currentAnts += ants;
    }
    else
    {
        cout << "Chamber " << name << " is full." << endl;
    }
}
