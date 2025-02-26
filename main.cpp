#include <iostream>
#include "Headers/Anthill.hpp"
using namespace std;

int main() {
    Anthill anthill(4);

    anthill.chambers[0] = Chamber("Chamber Sv", 5);
    anthill.chambers[1] = Chamber("Chamber 1", 10);
    anthill.chambers[2] = Chamber("Chamber 2", 3);
    anthill.chambers[3] = Chamber("Chamber Sd", 8);

    anthill.addTunnel(0, 1);
    anthill.addTunnel(0, 2);
    anthill.addTunnel(1, 3);
    anthill.addTunnel(2, 3);

    anthill.printAnthill();
    anthill.printNumberOfAnts();

    return 0;
}
