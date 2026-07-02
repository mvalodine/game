# Rock Paper Scissors Tournament Simulator

## Overview
This is a simple C++ console application that simulates a Rock-Paper-Scissors tournament. Users can manage a list of players, build a lineup, and have players compete against each other. The program tracks wins, losses, draws, and win records for each player.

## Features
- **Player Management**: Add new players and view all players with their statistics.
- **Lineup Management**: Add players to a fighting lineup.
- **Tournament Mode**: Fight between the first two players in the lineup using random Rock/Paper/Scissors throws.
- **Statistics Tracking**: Each player maintains wins, losses, draws, and a win percentage.
- **Menu-Driven Interface**: Easy-to-use text menu for all operations.

## How to Compile and Run
1. Ensure you have a C++ compiler (g++ recommended).
2. Compile the files:
   ```bash
   g++ -o rps_tournament main.cpp Player.cpp
