// Lesson 1: Bitmasks -- reference solution.
// Try to solve starter.cpp yourself before reading this!

#include "../common/maze_types.h"

bool hasWall(int cell, int direction) {
    return (cell & direction) != 0;
}

int addWall(int cell, int direction) {
    return cell | direction;
}

int removeWall(int cell, int direction) {
    return cell & ~direction;
}

bool isEntrance(int cell) {
    return (cell & ENTRANCE) != 0;
}

bool isExit(int cell) {
    return (cell & EXIT) != 0;
}

int opposite(int direction) {
    switch (direction) {
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST:  return WEST;
        case WEST:  return EAST;
    }
    return 0;
}
