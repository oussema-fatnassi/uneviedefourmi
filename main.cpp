#include <iostream>
#include <filesystem>
#include "Headers/AnthillLoader.hpp"
#include "Headers/LinkedList.hpp"
#include <unordered_map>

int main() {
    string jsonPath = "../Resources/AnthillConfig.json";
    Anthill anthill(0);

    AnthillLoader loader;
    int numAnts;
    if (!loader.loadFromJson(jsonPath, anthill, numAnts)) {
        cout << "Failed to load anthill configuration from JSON!" << endl;
        return 1;
    }

    vector<vector<int>> allPaths = anthill.findAllPathsBFS(0, anthill.getNumberOfChambers() - 1);
    
    if (allPaths.empty()) {
        cout << "No valid paths found!" << endl;
        return 1;
    }

    // Create ants
    LinkedList listAnts;
    for (int i = 0; i < numAnts; i++) {
        listAnts.addAntAtEnd(i);
    }
    
    // Keep track of chamber occupancy
    unordered_map<string, int> chamberOccupancy;
    for (int i = 0; i < anthill.getNumberOfChambers(); i++) {
        chamberOccupancy[anthill.getChamberNameByIndex(i)] = 0;
    }
    
    // All ants start at "Sv"
    chamberOccupancy["Sv"] = listAnts.size();
    
    // Keep track of ants that have reached the destination
    vector<bool> antsAtDestination(listAnts.size(), false);
    vector<int> antPathIndex(listAnts.size(), 0); // Track which path each ant is using
    int antsReachedDestination = 0;
    int round = 0;
    int maxRounds = 100; // Safety limit to prevent infinite loops
    
    while (antsReachedDestination < listAnts.size() && round < maxRounds) {
        cout << "===== Round " << ++round << " =====" << endl;
        
        // Print current chamber occupancy
        cout << "Current chamber occupancy: ";
        for (const auto& pair : chamberOccupancy) {
            if (pair.second > 0) {
                cout << pair.first << ":" << pair.second << " ";
            }
        }
        cout << endl;
        
        for (int i = 0; i < listAnts.size(); i++) {
            if (antsAtDestination[i]) continue;

            string currentPosition = listAnts.getAnt(i).getPosition();
            cout << "Ant " << i << " is at " << currentPosition << endl;

            if (currentPosition == "Sd") {
                antsAtDestination[i] = true;
                antsReachedDestination++;
                cout << "Ant " << i << " has reached the destination!" << endl;
                continue;
            }

            int pathIndex = antPathIndex[i]; // Get the current path index
            vector<int>& path = allPaths[pathIndex]; // Retrieve the assigned path

            // Find the current position in the path
            int currentIndex = -1;
            for (size_t j = 0; j < path.size(); j++) {
                if (anthill.getChamberNameByIndex(path[j]) == currentPosition) {
                    currentIndex = j;
                    break;
                }
            }

            if (currentIndex == -1) {
                cout << "Ant " << i << " is not on the path!" << endl;
                continue;
            }

            if (currentIndex + 1 >= path.size()) {
                cout << "Ant " << i << " is at the end of the path!" << endl;
                continue;
            }

            string nextChamberName = anthill.getChamberNameByIndex(path[currentIndex + 1]);
            int nextChamberMaxCapacity = anthill.getChamberMaxAntsByName(nextChamberName);

            cout << "Ant " << i << " trying to move from " << currentPosition << " to " << nextChamberName;
            cout << " (Occupancy: " << chamberOccupancy[nextChamberName] << "/" << nextChamberMaxCapacity << ")" << endl;

            // If the current path is blocked, switch to another available path
            if (nextChamberMaxCapacity != -1 && chamberOccupancy[nextChamberName] >= nextChamberMaxCapacity) {
                cout << "Chamber " << nextChamberName << " is full. Trying another path..." << endl;

                // Attempt to find an alternate path for this ant
                bool foundAlternativePath = false;
                for (size_t p = 0; p < allPaths.size(); p++) {
                    if (p == pathIndex) continue; // Skip the current path
                    vector<int>& alternatePath = allPaths[p];

                    int altCurrentIndex = -1;
                    for (size_t j = 0; j < alternatePath.size(); j++) {
                        if (anthill.getChamberNameByIndex(alternatePath[j]) == currentPosition) {
                            altCurrentIndex = j;
                            break;
                        }
                    }

                    if (altCurrentIndex != -1 && altCurrentIndex + 1 < alternatePath.size()) {
                        string altNextChamberName = anthill.getChamberNameByIndex(alternatePath[altCurrentIndex + 1]);
                        int altNextChamberMaxCapacity = anthill.getChamberMaxAntsByName(altNextChamberName);

                        if (altNextChamberMaxCapacity == -1 || chamberOccupancy[altNextChamberName] < altNextChamberMaxCapacity) {
                            antPathIndex[i] = p; // Switch to this path
                            nextChamberName = altNextChamberName;
                            foundAlternativePath = true;
                            cout << "Ant " << i << " switched to an alternate path via " << nextChamberName << endl;
                            break;
                        }
                    }
                }

                if (!foundAlternativePath) {
                    cout << "No alternate paths available. Ant " << i << " stays at " << currentPosition << endl;
                    continue;
                }
            }

            // Move the ant
            chamberOccupancy[currentPosition]--;
            chamberOccupancy[nextChamberName]++;
            listAnts.getAnt(i).move(nextChamberName);
            cout << "Ant " << i << " moved to " << nextChamberName << endl;

            if (nextChamberName == "Sd") {
                antsAtDestination[i] = true;
                antsReachedDestination++;
                cout << "Ant " << i << " has reached the destination!" << endl;
            }
        }

        cout << "Ants at destination: " << antsReachedDestination << "/" << listAnts.size() << endl;
    }

    if (round >= maxRounds) {
        cout << "Simulation stopped after " << maxRounds << " rounds!" << endl;
    } else {
        cout << "All ants have reached the destination in " << round << " rounds!" << endl;
    }

    return 0;
}
