#pragma once
// Reference bitmask helpers used INTERNALLY by the Lesson 3 and 4 tests and
// solutions. These are the "already correct" versions of the functions you
// write yourself in Lesson 1 -- that way, if your Lesson 1 code still has a
// bug, it won't stop Lesson 3 or 4 from working. They're named differently
// (cellHasWall vs. hasWall) on purpose so there's no mix-up.
//
// You don't need to edit this file.

#include "maze_types.h"

inline bool cellHasWall(int cell, int direction) {
    return (cell & direction) != 0;
}

inline int cellOppositeDirection(int direction) {
    switch (direction) {
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST:  return WEST;
        case WEST:  return EAST;
    }
    return 0;
}

inline bool cellIsEntrance(int cell) { return (cell & ENTRANCE) != 0; }
inline bool cellIsExit(int cell)     { return (cell & EXIT) != 0; }
