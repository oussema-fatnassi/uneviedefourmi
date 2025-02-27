#include <iostream>
#include <filesystem>
#include "Headers/AnthillLoader.hpp"

int main() {
    string jsonPath = "../Resources/AnthillConfig.json";
    Anthill anthill(0);

    if (AnthillLoader::loadFromJson(jsonPath, anthill)) {
        anthill.printAnthill();
        anthill.printNumberOfAnts();
        anthill.printPath(anthill.findPathBFS(0, anthill.getNumberOfChambers() - 1));
    }

    return 0;
}
