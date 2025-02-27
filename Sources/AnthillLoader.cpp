#include "Headers/AnthillLoader.hpp"

using json = nlohmann::json;

bool AnthillLoader::loadFromJson(const std::string& jsonFile, Anthill& anthill, int& numAnts) {
    std::ifstream file(jsonFile);
    if (!file) {
        std::cerr << "Error: Unable to open JSON file: " << jsonFile << std::endl;
        return false;
    }

    json data;
    file >> data;

    // Ask user which anthill to load
    std::cout << "Select an Anthill Configuration:\n";
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << i + 1 << ". " << data[i]["file"] << std::endl;
    }

    int choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    if (choice < 1 || choice > data.size()) {
        std::cout << "Invalid choice!\n";
        return false;
    }

    json selectedConfig = data[choice - 1];

    // Retrieve the number of ants for the simulation
    numAnts = selectedConfig["f"];

    // Get chamber count and add space for Sv and Sd
    int numChambers = selectedConfig["chambers"].size() + 2; // +2 for Sv and Sd
    anthill = Anthill(numChambers);

    // Add Start Chamber (Sv) with infinite capacity (-1)
    anthill.chambers[0] = Chamber("Sv", -1);

    // Load chambers from JSON
    for (size_t i = 0; i < selectedConfig["chambers"].size(); i++) {
        if (selectedConfig["chambers"][i].is_string()) {
            // Default maxAnts to 1 for intermediate chambers
            anthill.chambers[i + 1] = Chamber(selectedConfig["chambers"][i], 1);
        } else if (selectedConfig["chambers"][i].is_object()) {
            anthill.chambers[i + 1] = Chamber(selectedConfig["chambers"][i]["name"], selectedConfig["chambers"][i]["ants"]);
        }
    }

    // Add Destination Chamber (Sd) with infinite capacity (-1)
    anthill.chambers[numChambers - 1] = Chamber("Sd", -1);

    // Load tunnels
    for (const auto& tunnel : selectedConfig["tunnels"]) {
        std::string chamber1 = tunnel[0];
        std::string chamber2 = tunnel[1];

        int idx1 = -1, idx2 = -1;
        for (size_t i = 0; i < numChambers; i++) {
            if (anthill.chambers[i].getName() == chamber1) idx1 = i;
            if (anthill.chambers[i].getName() == chamber2) idx2 = i;
        }

        if (idx1 != -1 && idx2 != -1) {
            anthill.addTunnel(idx1, idx2);
        }
    }

    std::cout << "Anthill loaded successfully with Sv and Sd having infinite capacity!" << std::endl;
    return true;
}
