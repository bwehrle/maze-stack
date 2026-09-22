// Lesson 4: Backtracking with a Stack
// Read instructions.md before starting!

#include "../common/maze_types.h"
#include "../common/maze_utils.h"
#include "../lesson2_stack/starter.cpp"
#include <vector>

// TODO: Solve the maze using your Stack from Lesson 2 to backtrack out of
// dead ends. This maze may contain branches and dead ends, so "always take
// the other opening" (Lesson 3) is not enough.
//
// Algorithm:
//   1. Push `start` onto the stack and mark it visited.
//   2. Loop:
//        - Look at the position on TOP of the stack (peek()).
//        - If it's the exit, stop -- the stack now holds the solved path.
//        - Otherwise, look for an unvisited neighbor with no wall in the
//          way (check NORTH, EAST, SOUTH, WEST in that order).
//            - Found one? Mark it visited and push it.
//            - Found nothing? Dead end -- pop() to backtrack.
//   3. Copy the stack's contents (bottom to top, using at()) into a
//      std::vector<Position> and return it.
//
// Hints:
//   - cellHasWall(cell, direction), rowDelta(direction), colDelta(direction)
//   - Use a std::vector<std::vector<bool>> the same size as the maze to
//     track which cells you've visited.
//   - stack.at(i) gives you the i-th element counting from the BOTTOM.
std::vector<Position> solveMazeWithBacktracking(const Maze& maze, Position start) {
    std::vector<Position> path;
    // your code here
    return path;
}
