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
    std::cout << "Lesson 4: Backtracking with a Stack\n=====================================\n\n";

    // A 3x3 maze with two dead-end branches:
    //   (0,0)-(0,1)-(0,2)   <- dead-end branch off the entrance
    //   (1,0)-(1,1)-(1,2)   <- another dead-end branch
    //   (0,0)-(1,0)-(2,0)-(2,1)-(2,2)  <- the real path to the exit
    //
    // Checking directions in order NORTH, EAST, SOUTH, WEST means a naive
    // walker heads EAST out of (0,0) first and wanders all the way into
    // the (0,1)->(0,2) dead end, then backtracks, then heads into the
    // (1,0)->(1,1)->(1,2) dead end too, before finally backtracking onto
    // the real path down column 0 and across row 2 to the exit. If
    // backtracking isn't implemented correctly, this maze will expose it.
    Maze maze = {
        {NORTH | WEST | ENTRANCE, NORTH | SOUTH,   NORTH | EAST | SOUTH},
        {WEST,                    NORTH | SOUTH,   NORTH | EAST | SOUTH},
        {SOUTH | WEST,            NORTH | SOUTH,   NORTH | EAST | SOUTH | EXIT}
    };

    std::vector<Position> path = solveMazeWithBacktracking(maze, Position{0, 0});

    std::vector<Position> expected = {
        Position{0, 0}, Position{1, 0}, Position{2, 0}, Position{2, 1}, Position{2, 2}
    };

    check(!path.empty(), "solveMazeWithBacktracking returns a non-empty path");
    check(path.empty() || path.front() == Position{0, 0}, "path starts at the entrance");
    check(path.empty() || cellIsExit(maze[path.back().row][path.back().col]),
          "path ends at the exit");
    check(pathsEqual(path, expected),
          "path is exactly the solved route, with dead-end detours removed");

    return reportAndExit();
}
