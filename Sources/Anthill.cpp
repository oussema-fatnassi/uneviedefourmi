#include "Headers/Anthill.hpp"

Anthill::Anthill(int numberOfChambers) {
    chambers.resize(numberOfChambers);
    this->numberOfChambers = numberOfChambers;
    anthill.resize(numberOfChambers);
    for (int i = 0; i < numberOfChambers; i++) {
        anthill[i].resize(numberOfChambers);   
    }
}

Anthill::~Anthill() {
    anthill.clear();
}

void Anthill::addTunnel(int chamberIndex1, int chamberIndex2) {
    if(chamberIndex1 >= numberOfChambers || chamberIndex2 >= numberOfChambers) {
        cout << "Invalid chamber index." << endl;
        return;
    }
    anthill[chamberIndex1][chamberIndex2] = 1;
    anthill[chamberIndex2][chamberIndex1] = 1;
}


void Anthill::printAnthill() {
    for (int i = 0; i < numberOfChambers; i++) {
        for (int j = 0; j < numberOfChambers; j++) {
            cout << anthill[i][j] << " ";
        }
        cout << endl;
    }
}

void Anthill::printNumberOfAnts() {
    for (int i = 0; i < numberOfChambers; i++) {
        cout << "Chamber " << chambers[i].getName() << " has " << chambers[i].getMaxAnts() << " ants." << endl;
    }
}

vector<int> Anthill::findPathBFS(int startChamber, int endChamber) {
    vector<bool> visited(numberOfChambers, false);
    queue<int> q;
    vector<int> parent(numberOfChambers, -1);

    visited[startChamber] = true;
    q.push(startChamber);
    
    bool foundPath = false;
    
    while (!q.empty() && !foundPath) {
        int currentChamber = q.front();
        q.pop();
        
        if (currentChamber == endChamber) {
            foundPath = true;
            break;
        }
        
        for (int i = 0; i < numberOfChambers; i++) {
            if (anthill[currentChamber][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                parent[i] = currentChamber;
            }
        }
    }
    
    if (!foundPath) {
        return vector<int>();
    }
    
    vector<int> path;
    for (int at = endChamber; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    
    reverse(path.begin(), path.end());
    return path;
}

void Anthill::printPath(const vector<int>& path) {
    if (path.empty()) {
        cout << "No path exists." << endl;
        return;
    }
    
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << chambers[path[i]].getName();
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}