#include "../common/maze_types.h"
#include "../common/test_utils.h"
#include "starter.cpp"
#include <iostream>

int main() {
    std::cout << "Lesson 1: Bitmasks\n===================\n\n";

    std::cout << "hasWall()\n";
    int cell = NORTH | SOUTH; // walls to the north and south only
    check(hasWall(cell, NORTH) == true, "cell with NORTH|SOUTH has a north wall");
    check(hasWall(cell, SOUTH) == true, "cell with NORTH|SOUTH has a south wall");
    check(hasWall(cell, EAST) == false, "cell with NORTH|SOUTH has no east wall");
    check(hasWall(cell, WEST) == false, "cell with NORTH|SOUTH has no west wall");

    std::cout << "\naddWall()\n";
    int c2 = 0;
    c2 = addWall(c2, EAST);
    check(hasWall(c2, EAST) == true, "addWall(EAST) sets the east wall");
    check(hasWall(c2, NORTH) == false, "addWall(EAST) leaves north untouched");
    c2 = addWall(c2, EAST); // adding a wall that's already there shouldn't break
    check(hasWall(c2, EAST) == true, "addWall is safe to call twice");

    std::cout << "\nremoveWall()\n";
    int c3 = NORTH | EAST | SOUTH | WEST;
    c3 = removeWall(c3, WEST);
    check(hasWall(c3, WEST) == false, "removeWall(WEST) clears the west wall");
    check(hasWall(c3, NORTH) == true, "removeWall(WEST) leaves north untouched");
    check(hasWall(c3, EAST) == true, "removeWall(WEST) leaves east untouched");
    check(hasWall(c3, SOUTH) == true, "removeWall(WEST) leaves south untouched");

    std::cout << "\nisEntrance() / isExit()\n";
    int start = ENTRANCE | EAST;
    int end = EXIT | WEST;
    int plain = NORTH | SOUTH;
    check(isEntrance(start) == true, "cell flagged ENTRANCE is recognized");
    check(isEntrance(plain) == false, "plain cell is not an entrance");
    check(isExit(end) == true, "cell flagged EXIT is recognized");
    check(isExit(plain) == false, "plain cell is not an exit");
    check(isEntrance(end) == false, "exit cell is not also an entrance");

    std::cout << "\nopposite()\n";
    check(opposite(NORTH) == SOUTH, "opposite(NORTH) == SOUTH");
    check(opposite(SOUTH) == NORTH, "opposite(SOUTH) == NORTH");
    check(opposite(EAST) == WEST, "opposite(EAST) == WEST");
    check(opposite(WEST) == EAST, "opposite(WEST) == EAST");

    return reportAndExit();
}
