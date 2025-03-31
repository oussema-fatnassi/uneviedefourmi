#include "Headers/Ant.hpp"

Ant::Ant()
{
    position = "Sv";
}

Ant::Ant(int value)
{
    position = "Sv";
    data = value;
}

void Ant::move(string target)
{
    setPosition(target);
}

void Ant::setPosition(string position)
{
    this->position = position;
}

string Ant::getPosition()
{
    return position;
}
