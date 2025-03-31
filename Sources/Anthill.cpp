#include "Headers/Anthill.hpp"

Anthill::Anthill(int numberOfChambers)
{
    chambers.resize(numberOfChambers);
    this->numberOfChambers = numberOfChambers;
    anthill.resize(numberOfChambers);
    for (int i = 0; i < numberOfChambers; i++)
    {
        anthill[i].resize(numberOfChambers);
    }
}

Anthill::~Anthill()
{
    anthill.clear();
}

// Add a tunnel between two chambers
// This function assumes that the chambers are already created and indexed correctly.
void Anthill::addTunnel(int chamberIndex1, int chamberIndex2)
{
    if (chamberIndex1 >= numberOfChambers || chamberIndex2 >= numberOfChambers)
    {
        cout << "Invalid chamber index." << endl;
        return;
    }
    anthill[chamberIndex1][chamberIndex2] = 1;
    anthill[chamberIndex2][chamberIndex1] = 1;
}

// Print the anthill structure
void Anthill::printAnthill()
{
    for (int i = 0; i < numberOfChambers; i++)
    {
        for (int j = 0; j < numberOfChambers; j++)
        {
            cout << anthill[i][j] << " ";
        }
        cout << endl;
    }
}

// Print the names of the chambers and their maximum number of ants
void Anthill::printNumberOfAnts()
{
    for (int i = 0; i < numberOfChambers; i++)
    {
        cout << "Chamber " << chambers[i].getName() << " has " << chambers[i].getMaxAnts() << " max ants." << endl;
    }
}

// Algorithm to find all paths from startChamber to endChamber using BFS
vector<vector<int>> Anthill::findAllPathsBFS(int startChamber, int endChamber)
{
    queue<vector<int>> pathQueue;

    vector<int> initialPath;
    initialPath.push_back(startChamber);
    pathQueue.push(initialPath);

    cout << "Finding all paths from " << chambers[startChamber].getName()
         << " to " << chambers[endChamber].getName() << " using BFS:" << endl;

    while (!pathQueue.empty())
    {
        vector<int> currentPath = pathQueue.front();
        pathQueue.pop();

        int currentChamber = currentPath.back();

        if (currentChamber == endChamber)
        {
            allPaths.push_back(currentPath);
            continue;
        }

        for (int i = 0; i < numberOfChambers; i++)
        {
            if (anthill[currentChamber][i] == 1)
            {
                bool alreadyInPath = false;
                for (size_t j = 0; j < currentPath.size(); j++)
                {
                    if (currentPath[j] == i)
                    {
                        alreadyInPath = true;
                        break;
                    }
                }

                if (!alreadyInPath)
                {
                    vector<int> newPath = currentPath;
                    newPath.push_back(i);
                    pathQueue.push(newPath);
                }
            }
        }
    }

    cout << "Total number of paths found: " << allPaths.size() << endl;

    for (size_t i = 0; i < allPaths.size(); i++)
    {
        cout << "Path " << (i + 1) << ": ";
        for (size_t j = 0; j < allPaths[i].size(); j++)
        {
            cout << chambers[allPaths[i][j]].getName();
            if (j < allPaths[i].size() - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return allPaths;
}

// Get a chamber's name by its index
string Anthill::getChamberNameByIndex(int index) const
{
    if (index >= 0 && index < numberOfChambers)
    {
        return chambers[index].getName();
    }
    return "";
}

// Get a chamber's max ants by its name
int Anthill::getChamberMaxAntsByName(const string &name) const
{
    for (int i = 0; i < numberOfChambers; i++)
    {
        if (chambers[i].getName() == name)
        {
            return chambers[i].getMaxAnts();
        }
    }
    return 0;
}