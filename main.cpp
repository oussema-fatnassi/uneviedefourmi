#include <iostream>
#include "Headers/Anthill.hpp"
#include "Headers/LinkedList.hpp"
using namespace std;

int main() {

    //Anthill 3
    // Anthill anthill(6);

    // anthill.chambers[0] = Chamber("Chamber Sv", 5);
    // anthill.chambers[1] = Chamber("Chamber 1", 10);
    // anthill.chambers[2] = Chamber("Chamber 2", 3);
    // anthill.chambers[3] = Chamber("Chamber 3", 8);
    // anthill.chambers[4] = Chamber("Chamber 4", 6);
    // anthill.chambers[5] = Chamber("Chamber Sd", 4);

    // anthill.addTunnel(0, 1);
    // anthill.addTunnel(1, 2);
    // anthill.addTunnel(4, 5);
    // anthill.addTunnel(1, 4);
    // anthill.addTunnel(2, 3);

    // anthill.printAnthill();
    // anthill.findPathBFS(0, 5);
    // anthill.printPath(anthill.findPathBFS(0, 5));

    //Anthill 5
    Anthill anthill(16);
    anthill.chambers[0] = Chamber("Chamber Sv", 50);
    anthill.chambers[1] = Chamber("Chamber 1", 8);
    anthill.chambers[2] = Chamber("Chamber 2", 4);
    anthill.chambers[3] = Chamber("Chamber 3", 2);
    anthill.chambers[4] = Chamber("Chamber 4", 4);
    anthill.chambers[5] = Chamber("Chamber 5", 2);
    anthill.chambers[6] = Chamber("Chamber 6", 4);
    anthill.chambers[7] = Chamber("Chamber 7", 2);
    anthill.chambers[8] = Chamber("Chamber 8", 5);
    anthill.chambers[9] = Chamber("Chamber 9", 0);
    anthill.chambers[10] = Chamber("Chamber 10", 0);
    anthill.chambers[11] = Chamber("Chamber 11", 0);
    anthill.chambers[12] = Chamber("Chamber 12", 0);
    anthill.chambers[13] = Chamber("Chamber 13", 4);
    anthill.chambers[14] = Chamber("Chamber 14", 2);
    anthill.chambers[15] = Chamber("Chamber Sd", 50);

    anthill.addTunnel(1, 2);
    anthill.addTunnel(2, 3);
    anthill.addTunnel(3, 4);
    anthill.addTunnel(4, 15);
    anthill.addTunnel(0, 1);
    anthill.addTunnel(2, 5);
    anthill.addTunnel(5, 4);
    anthill.addTunnel(13, 15);
    anthill.addTunnel(8, 12);
    anthill.addTunnel(12, 13);
    anthill.addTunnel(6, 7);
    anthill.addTunnel(7, 9);
    anthill.addTunnel(9, 14);
    anthill.addTunnel(14, 15);
    anthill.addTunnel(7, 10);
    anthill.addTunnel(10, 14);
    anthill.addTunnel(1, 6);
    anthill.addTunnel(6, 8);
    anthill.addTunnel(8, 11);
    anthill.addTunnel(11, 13);

    anthill.printAnthill();
    anthill.findPathBFS(0, 15);
    anthill.printPath(anthill.findPathBFS(0, 15));

    // LinkedList listAnts;
    // listAnts.addAntAtEnd(1);
    // listAnts.addAntAtEnd(2);
    // listAnts.addAntAtEnd(3);
    // listAnts.addAntAtEnd(4);

    // listAnts.printList();
    // listAnts.deleteByValue(3);
    // listAnts.printList();

    return 0;
}
