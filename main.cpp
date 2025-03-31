#include <iostream>
#include <filesystem>
#include "Headers/AnthillLoader.hpp"
#include "Headers/LinkedList.hpp"
#include <unordered_map>
#include "Headers/GameController.hpp"

int main() {
    GameController game("../Resources/AnthillConfig.json");
    game.run();
    return 0;
}
