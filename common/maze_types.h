#pragma once
// Shared types used by every lesson. You don't need to edit this file.

// Direction bitmask constants. Each cell in the maze is a single int, and
// these bits tell you which sides of that cell have a wall.
//
//        NORTH
//          1
//   WEST  cell  EAST
//    8           2
//        SOUTH
//          4
//
// A cell value of (NORTH | EAST) means "this cell has walls on its north
// and east sides, but is open to the south and west."
constexpr int NORTH = 1; // 0001
constexpr int EAST  = 2; // 0010
constexpr int SOUTH = 4; // 0100
constexpr int WEST  = 8; // 1000

// A cell can ALSO be flagged as the maze's entrance or exit. These use
// higher bits so they don't collide with the wall bits above.
constexpr int ENTRANCE = 16; // 010000
constexpr int EXIT     = 32; // 100000

// A single (row, col) location in the maze.
struct Position {
    int row;
    int col;
};

inline bool operator==(const Position& a, const Position& b) {
    return a.row == b.row && a.col == b.col;
}
inline bool operator!=(const Position& a, const Position& b) {
    return !(a == b);
}

// The maze itself: a grid of cells, each cell an int bitmask as above.
#include <vector>
using Maze = std::vector<std::vector<int>>;

// How row/col change if you take one step in `direction`.
inline int rowDelta(int direction) {
    if (direction == NORTH) return -1;
    if (direction == SOUTH) return 1;
    return 0;
}
inline int colDelta(int direction) {
    if (direction == EAST) return 1;
    if (direction == WEST) return -1;
    return 0;
}
