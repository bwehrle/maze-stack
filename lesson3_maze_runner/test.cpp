#include "../common/maze_types.h"
#include "../common/maze_utils.h"
#include "../common/test_utils.h"
#include "starter.cpp"
#include <iostream>
#include <vector>

static bool pathsEqual(const std::vector<Position>& a, const std::vector<Position>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    std::cout << "Lesson 3: The Maze Runner (no dead ends)\n==========================================\n\n";

    std::cout << "straight 1x3 corridor\n";
    // A single row, entrance on the left, exit on the right:
    //   +---+---+---+
    //   | S   .   E |
    //   +---+---+---+
    Maze corridor = {
        {NORTH | SOUTH | WEST | ENTRANCE, NORTH | SOUTH, NORTH | SOUTH | EAST | EXIT}
    };
    std::vector<Position> corridorPath = runMaze(corridor, Position{0, 0});
    std::vector<Position> corridorExpected = {
        Position{0, 0}, Position{0, 1}, Position{0, 2}
    };
    check(pathsEqual(corridorPath, corridorExpected),
          "walks straight across a 3-cell corridor to the exit");

    std::cout << "\nwinding 3x3 maze (S-shaped path, no branches)\n";
    // Path snakes: (0,0)->(0,1)->(0,2)->(1,2)->(1,1)->(1,0)->(2,0)->(2,1)->(2,2)
    Maze winding = {
        {NORTH | WEST | SOUTH | ENTRANCE, NORTH | SOUTH, NORTH | EAST},
        {WEST | NORTH, NORTH | SOUTH, EAST | SOUTH},
        {SOUTH | WEST, SOUTH | NORTH, SOUTH | EAST | NORTH | EXIT}
    };
    std::vector<Position> windingPath = runMaze(winding, Position{0, 0});
    std::vector<Position> windingExpected = {
        Position{0, 0}, Position{0, 1}, Position{0, 2},
        Position{1, 2}, Position{1, 1}, Position{1, 0},
        Position{2, 0}, Position{2, 1}, Position{2, 2}
    };
    check(pathsEqual(windingPath, windingExpected),
          "correctly follows a winding S-shaped path to the exit");
    check(!windingPath.empty() &&
              cellIsExit(winding[windingPath.back().row][windingPath.back().col]),
          "the last position visited is the exit cell");

    return reportAndExit();
}
