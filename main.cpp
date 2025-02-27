#include <iostream>
#include <filesystem>
#include "Headers/AnthillLoader.hpp"
#include "Headers/LinkedList.hpp"

int main() {
    string jsonPath = "../Resources/AnthillConfig.json";
    Anthill anthill(0);

    if (AnthillLoader::loadFromJson(jsonPath, anthill)) {
        // anthill.printAnthill();
        // anthill.printNumberOfAnts();
    }

    vector<vector<int>> allPath = anthill.findAllPathsBFS(0, anthill.getNumberOfChambers() - 1);
    vector<int> path = allPath[0];
    // anthill.printPath(path);

    LinkedList listAnts;
    listAnts.addAntAtEnd(1);
    listAnts.addAntAtEnd(2);
    listAnts.addAntAtEnd(3);
    listAnts.addAntAtEnd(4);
    int cpt = 0;

    while (cpt<10) {
        for (int i = 0; i < listAnts.size(); i++) {
            string position = listAnts.getAnt(i).getPosition();
            Chamber nextChamber = anthill.getNextChamberInPath(path, position);
            if (nextChamber.getName() == "Sd") {
                cout << "Ant " << i << " has reached the end." << endl;
                continue;
            } else {
                listAnts.getAnt(i).checkNextChamber(nextChamber);
            }
        }
        cpt++;
    }
    return 0;
}
