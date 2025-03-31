#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Anthill.hpp"
#include "AnthillLoader.hpp"
#include "LinkedList.hpp"

class GameController {
public:
    GameController(const std::string& configPath);
    void run();
private:
    std::string jsonPath;
    Anthill anthill;
    AnthillLoader loader;
    LinkedList listAnts;
    std::vector<std::vector<int>> allPaths;
    std::unordered_map<std::string, int> chamberOccupancy;

    void initialize();
    void simulationLoop();
};

#endif // GAMECONTROLLER_HPP