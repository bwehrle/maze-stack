# Lesson 1: Bitmasks

## The idea

A maze is a grid of cells. Each cell needs to remember several yes/no facts:
"is there a wall to the north?", "to the east?", "is this the entrance?",
and so on. You *could* store each fact in its own variable, but there's a
neat trick that real maze (and graphics, and networking) code uses instead:
pack all those yes/no facts into the individual bits of a single integer.
This is called a **bitmask**.

An `int` has lots of bits. We only need a few of them:

```
        NORTH
          1
   WEST  cell  EAST
    8           2
        SOUTH
          4
```

If a cell's value is `NORTH | SOUTH` (that's `1 | 4` = `5`, i.e. binary
`0101`), it means "this cell has walls to the north and south, but is open
to the east and west."

These constants are already defined for you in `common/maze_types.h`:

```cpp
constexpr int NORTH = 1;   // binary 0001
constexpr int EAST  = 2;   // binary 0010
constexpr int SOUTH = 4;   // binary 0100
constexpr int WEST  = 8;   // binary 1000

constexpr int ENTRANCE = 16; // binary 010000
constexpr int EXIT     = 32; // binary 100000
```

## The three operators you need

- `&` (AND) -- checks if a bit is set. `cell & NORTH` is nonzero exactly
  when the NORTH bit is on.
- `|` (OR) -- turns a bit on. `cell | NORTH` returns a new value with the
  NORTH bit set, leaving all other bits alone.
- `& ~` (AND-NOT) -- turns a bit off. `cell & ~NORTH` returns a new value
  with the NORTH bit cleared, leaving all other bits alone.

## Your job

Open `starter.cpp`. There are six functions to implement:

1. `hasWall(cell, direction)` -- is there a wall on that side?
2. `addWall(cell, direction)` -- return a new cell value with that wall added.
3. `removeWall(cell, direction)` -- return a new cell value with that wall knocked down.
4. `isEntrance(cell)` -- is this the entrance?
5. `isExit(cell)` -- is this the exit?
6. `opposite(direction)` -- what's the direction that points back the way you came?
   (e.g. the opposite of `NORTH` is `SOUTH`)

Each function has a `// TODO` comment explaining what to fill in.

## Running the test

From this directory:

```
./run.sh
```

or, if that doesn't work:

```
g++ -std=c++17 -Wall -Wextra -o test_lesson1 test.cpp
./test_lesson1
```

Keep editing `starter.cpp` and re-running until every line says `[PASS]`.

## Stuck?

`solution.cpp` has a complete, working version -- try hard before you peek!
