// Lesson 4: Backtracking with a Stack -- reference solution.
// Try to solve starter.cpp yourself before reading this!

#include "../common/maze_types.h"
#include "../common/maze_utils.h"
#include "../lesson2_stack/solution.cpp"
#include <vector>

std::vector<Position> solveMazeWithBacktracking(const Maze& maze, Position start) {
    int rows = (int)maze.size();
    int cols = (int)maze[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    const int directions[4] = {NORTH, EAST, SOUTH, WEST};

    Stack<Position> stack;
    stack.push(start);
    visited[start.row][start.col] = true;

    while (!stack.isEmpty()) {
        Position current = stack.peek();
        int cell = maze[current.row][current.col];

        if (cellIsExit(cell)) {
            break;
        }

        bool moved = false;
        for (int direction : directions) {
            if (cellHasWall(cell, direction)) continue;

            Position neighbor{current.row + rowDelta(direction),
                               current.col + colDelta(direction)};
            if (neighbor.row < 0 || neighbor.row >= rows ||
                neighbor.col < 0 || neighbor.col >= cols) {
                continue;
            }
            if (visited[neighbor.row][neighbor.col]) continue;

            visited[neighbor.row][neighbor.col] = true;
            stack.push(neighbor);
            moved = true;
            break;
        }

        if (!moved) {
            stack.pop();
        }
    }

    std::vector<Position> path;
    for (int i = 0; i < stack.size(); ++i) {
        path.push_back(stack.at(i));
    }
    return path;
}
