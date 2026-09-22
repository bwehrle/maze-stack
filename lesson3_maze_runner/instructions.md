# Lesson 3: The Maze Runner (no dead ends)

## The idea

Now that you can read walls (Lesson 1), let's actually walk through a
maze. This lesson's mazes are the "easy" kind: there are no dead ends and
no branches. That means every cell (except the entrance and exit) has
*exactly two* openings -- the one you just walked in through, and exactly
one other. So the whole algorithm is:

1. Start at the entrance.
2. Look at the current cell. If it's the exit, you're done!
3. Otherwise, find the one open direction that ISN'T the way you just came
   from, and step through it.
4. Go back to step 2.

Since there's only ever one "other" direction available, you never have to
make a real choice, and you'll never need to backtrack. (That's coming in
Lesson 4, once mazes get harder.)

## Tools you have available

From `common/maze_utils.h` (already included for you):

- `cellHasWall(cell, direction)` -- true if that side is walled off.
- `cellOppositeDirection(direction)` -- e.g. `SOUTH` is opposite of `NORTH`.
- `cellIsExit(cell)` -- true once you've reached the exit.

From `common/maze_types.h`:

- The four directions: `NORTH`, `EAST`, `SOUTH`, `WEST`.
- `rowDelta(direction)` / `colDelta(direction)` -- how row/col change if you
  step in that direction. e.g. stepping `NORTH` means `row + rowDelta(NORTH)`.

**Important:** when you check the four directions, always check them in
this order: `NORTH`, `EAST`, `SOUTH`, `WEST`. The test expects an exact
path, and checking in a consistent order keeps your answer predictable.

## Your job

Open `starter.cpp` and implement:

```cpp
std::vector<Position> runMaze(const Maze& maze, Position start);
```

It should return every position visited, in order, starting with `start`
and ending on the exit cell.

**Hint for tracking "the way you came from":** keep a variable for the
direction you just moved *in*. The direction that leads back the way you
came is `cellOppositeDirection(thatDirection)` -- skip that one when
choosing where to go next.

## Running the test

```
./run.sh
```

or:

```
g++ -std=c++17 -Wall -Wextra -o test_lesson3 test.cpp
./test_lesson3
```

The test runs your function on a straight 1x3 corridor first, then on a
trickier winding 3x3 maze, and checks that the exact path matches.

## Stuck?

`solution.cpp` has a complete, working version -- try hard before you peek!
You can also drop a call to `printMaze(maze)` (from `common/maze_print.h`)
into a scratch `main()` to see the maze drawn out as ASCII art.
