// Lesson 1: Bitmasks
// Read instructions.md before starting!

#include "../common/maze_types.h"

// TODO 1: Return true if `cell` has a wall in `direction`.
// Hint: use & to check if a bit is set.
bool hasWall(int cell, int direction) {
    // your code here
    return false;
}

// TODO 2: Return a NEW cell value with a wall ADDED in `direction`.
// Hint: use | to turn a bit on. Don't modify `cell` itself -- return the result.
int addWall(int cell, int direction) {
    return cell; // your code here
}

// TODO 3: Return a NEW cell value with the wall in `direction` REMOVED.
// Hint: use & together with ~ to turn a bit off.
int removeWall(int cell, int direction) {
    return cell; // your code here
}

// TODO 4: Return true if this cell is marked as the maze's entrance.
bool isEntrance(int cell) {
    return false; // your code here
}

// TODO 5: Return true if this cell is marked as the maze's exit.
bool isExit(int cell) {
    return false; // your code here
}

// TODO 6: Given one of NORTH/EAST/SOUTH/WEST, return the opposite direction.
// e.g. opposite(NORTH) should return SOUTH.
int opposite(int direction) {
    return direction; // your code here
}
