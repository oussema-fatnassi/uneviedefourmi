#ifndef ANTHILLLOADER_HPP
#define ANTHILLLOADER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "Anthill.hpp"

using namespace std;
class AnthillLoader {
public:
    bool loadFromJson(const std::string& jsonFile, Anthill& anthill, int& numAnts) ;
};

#endif
