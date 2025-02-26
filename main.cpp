#include <iostream>
#include "Headers/Anthill.hpp"
#include "Headers/Ant.hpp"
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

    Ant F1;
    Ant F2;
    F1.lookAround();
    F2.lookAround();
    F1.stay();
    F2.stay();
    F1.move("S1");
    F2.move("S2");
    F1.stay();
    F2.stay();
    F1.move("Sd");
    F2.move("Sd");
    F1.stay();
    F2.stay();
    return 0;
}
