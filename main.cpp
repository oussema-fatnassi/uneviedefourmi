#include <iostream>
#include <filesystem>
#include "Headers/AnthillLoader.hpp"
#include "Headers/LinkedList.hpp"

int main() {
    string jsonPath = "../Resources/AnthillConfig.json";
    Anthill anthill(0);

    if (AnthillLoader::loadFromJson(jsonPath, anthill)) {
        anthill.printAnthill();
        anthill.printNumberOfAnts();
        anthill.findAllPathsBFS(0, 15);
    }

    // vector<int> path = anthill.findPathBFS(0, 15);
    // anthill.printPath(path);

    LinkedList listAnts;
    listAnts.addAntAtEnd(1);
    listAnts.addAntAtEnd(2);
    listAnts.addAntAtEnd(3);
    listAnts.addAntAtEnd(4);
    int cpt = 0;

    while (cpt<20) {
        for (int i = 0; i < listAnts.size(); i++) {
            // listAnts.getAnt(i).checkNextChamber(getNextChamber(path,listAnts.getAnt(i).getPosition()));
        }
        cpt++;
    }
    return 0;
}
