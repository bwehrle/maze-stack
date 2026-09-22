// Lesson 3: The Maze Runner (no dead ends) -- reference solution.
// Try to solve starter.cpp yourself before reading this!

#include "../common/maze_types.h"
#include "../common/maze_utils.h"
#include <vector>

std::vector<Position> runMaze(const Maze& maze, Position start) {
    std::vector<Position> path;

    Position current = start;
    int cameFromDirection = 0; // no direction yet -- we just started
    path.push_back(current);

    const int directions[4] = {NORTH, EAST, SOUTH, WEST};

    while (!cellIsExit(maze[current.row][current.col])) {
        int cell = maze[current.row][current.col];
        int nextDirection = 0;

        for (int direction : directions) {
            if (direction == cameFromDirection) continue;
            if (!cellHasWall(cell, direction)) {
                nextDirection = direction;
                break;
            }
        }

        current.row += rowDelta(nextDirection);
        current.col += colDelta(nextDirection);
        cameFromDirection = cellOppositeDirection(nextDirection);
        path.push_back(current);
    }

    return path;
}
