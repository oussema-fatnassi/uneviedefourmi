// main.cpp
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

    vector<vector<int>> allPath = anthill.findAllPathsBFS(0, anthill.getNumberOfChambers() - 1);
    vector<int> path = allPath[0]; // Using first found path
    
    // Print the selected path for debugging
    cout << "Selected path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << anthill.getChamberNameByIndex(path[i]);
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;

    // Create ants
    LinkedList listAnts;
    for (int i = 0; i < 10; i++) {
        listAnts.addAntAtEnd(i);
    }
    
    // Keep track of chamber occupancy
    unordered_map<string, int> chamberOccupancy;
    for (int i = 0; i < anthill.getNumberOfChambers(); i++) {
        chamberOccupancy[anthill.getChamberNameByIndex(i)] = 0;
    }
    
    // All ants start at "Sv" - the starting chamber
    chamberOccupancy["Sv"] = listAnts.size();
    
    // Keep track of ants that have reached the destination
    vector<bool> antsAtDestination(listAnts.size(), false);
    int antsReachedDestination = 0;
    int round = 0;
    int maxRounds = 100; // Safety limit to prevent infinite loops
    
    // Continue until all ants reach the destination chamber or max rounds is reached
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
        
        // For each ant
        for (int i = 0; i < listAnts.size(); i++) {
            // Skip ants that have already reached the destination
            if (antsAtDestination[i]) {
                continue;
            }
            
            string currentPosition = listAnts.getAnt(i).getPosition();
            cout << "Ant " << i << " is at " << currentPosition << endl;
            
            // Check if ant is already at destination
            if (currentPosition == "Sd") {
                antsAtDestination[i] = true;
                antsReachedDestination++;
                cout << "Ant " << i << " has reached the destination!" << endl;
                continue;
            }
            
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
            
            // Check if there is a next chamber
            if (currentIndex + 1 >= path.size()) {
                cout << "Ant " << i << " is at the end of the path!" << endl;
                continue;
            }
            
            // Get the next chamber
            string nextChamberName = anthill.getChamberNameByIndex(path[currentIndex + 1]);
            int nextChamberMaxCapacity = anthill.getChamberMaxAntsByName(nextChamberName);
            
            cout << "Ant " << i << " trying to move from " << currentPosition << " to " << nextChamberName;
            cout << " (Occupancy: " << chamberOccupancy[nextChamberName] << "/" << nextChamberMaxCapacity << ")" << endl;
            
            // Try to move to the next chamber if it's not full
            // Check if the next chamber allows infinite ants
            if (nextChamberMaxCapacity == -1 || chamberOccupancy[nextChamberName] < nextChamberMaxCapacity) {
                // Update chamber occupancy
                chamberOccupancy[currentPosition]--;
                chamberOccupancy[nextChamberName]++;

                // Move ant
                listAnts.getAnt(i).move(nextChamberName);

                cout << "Ant " << i << " moved to " << nextChamberName << endl;

                // Check if ant reached destination
                if (nextChamberName == "Sd") {
                    antsAtDestination[i] = true;
                    antsReachedDestination++;
                    cout << "Ant " << i << " has reached the destination!" << endl;
                }
            } else {
                cout << "Chamber " << nextChamberName << " is full. Ant " << i << " stays at " << currentPosition << endl;
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