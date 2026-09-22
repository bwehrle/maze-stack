#pragma once
// Optional bonus: draws a maze (and optionally a path through it) as ASCII
// art. Not required by any test -- just handy if you want to visualize what
// your maze runner is doing. Try calling printMaze(maze) or
// printMaze(maze, path) from a scratch main() while debugging.
//
// You don't need to edit this file.

#include "maze_types.h"
#include "maze_utils.h"
#include <iostream>
#include <vector>

inline void printMaze(const Maze& maze, const std::vector<Position>& path = {}) {
    int rows = (int)maze.size();
    if (rows == 0) return;
    int cols = (int)maze[0].size();

    auto onPath = [&](int r, int c) {
        for (const auto& p : path) {
            if (p.row == r && p.col == c) return true;
        }
        return false;
    };

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << '+' << (cellHasWall(maze[r][c], NORTH) ? "---" : "   ");
        }
        std::cout << "+\n";

        for (int c = 0; c < cols; ++c) {
            std::cout << (cellHasWall(maze[r][c], WEST) ? '|' : ' ');
            char mark = ' ';
            if (cellIsEntrance(maze[r][c])) mark = 'S';
            else if (cellIsExit(maze[r][c])) mark = 'E';
            else if (onPath(r, c)) mark = '*';
            std::cout << ' ' << mark << ' ';
        }
        std::cout << (cellHasWall(maze[r][cols - 1], EAST) ? "|\n" : " \n");
    }

    for (int c = 0; c < cols; ++c) {
        std::cout << '+' << (cellHasWall(maze[rows - 1][c], SOUTH) ? "---" : "   ");
    }
    std::cout << "+\n";
}
