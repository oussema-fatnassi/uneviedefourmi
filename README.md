# uneviedefourmi

A C++ simulation of ant colony movement through an anthill structure, where ants navigate from a source chamber to a destination chamber through interconnected tunnels while respecting chamber capacity constraints.

## Overview

This project simulates ants moving through an anthill network. Each anthill consists of:
- **Chambers**: Nodes in the network with capacity limits
- **Tunnels**: Connections between chambers
- **Ants**: Entities that move from chamber to chamber

Special chambers include:
- **Sv**: The source/entry chamber where all ants start
- **Sd**: The destination/exit chamber where ants aim to reach

## Features

- **Dynamic Anthill Loading**: Load different anthill configurations from JSON files
- **Capacity Management**: Each chamber has a maximum capacity of ants it can hold
- **Path Finding**: BFS algorithm to find all possible paths from source to destination
- **Intelligent Movement**: Ants can switch paths when their route is blocked by a full chamber
- **Simulation Control**: Configurable number of rounds and ants

## Project Structure

- **Ant**: Represents an individual ant with a position in the anthill
- **Chamber**: Represents a location in the anthill with capacity constraints
- **Anthill**: Models the entire anthill structure with chambers and tunnels
- **AnthillLoader**: Loads anthill configurations from JSON files
- **LinkedList**: Manages the collection of ants
- **GameController**: Orchestrates the simulation process

## Simulation Rules

1. All ants start at the source chamber "Sv"
2. In each round, ants try to move to the next chamber on their path
3. If a chamber is full, ants try alternative paths
4. The simulation ends when all ants reach the destination "Sd" or after a maximum number of rounds

## Getting Started

### Prerequisites

- C++ compiler with C++17 support
- CMake (3.16 or higher)
- nlohmann/json library (for JSON parsing)

### Building

```bash
mkdir build
cd build
cmake ..
make
```

### Running

```bash
./ANTHILL
```

The program will prompt you to select an anthill configuration from the loaded JSON file.

## Available Anthill Configurations

The project includes several predefined anthill configurations:

1. **anthill_0.txt**: A simple diamond-shaped anthill with 2 chambers
2. **anthill_1.txt**: A linear path with 2 chambers
3. **anthill_2.txt**: A cycle with 2 chambers
4. **anthill_3.txt**: A network with 4 chambers
5. **anthill_4.txt**: A more complex network with 6 chambers and capacity constraints
6. **anthill_5.txt**: A large network with 14 chambers and various capacity constraints


## Credits

-  This project is created by [Oussema Fatnassi, Baptiste Appriou and Ali Abakar]