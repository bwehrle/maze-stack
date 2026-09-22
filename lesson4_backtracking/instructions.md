# Lesson 4: Backtracking with a Stack

## The idea

Real mazes have dead ends and branches -- more than one open direction to
choose from, and some of those choices lead nowhere. "Always take the
other opening" (Lesson 3) doesn't work anymore, because sometimes there
are *two* other openings, and you don't know which one is right until you
try it.

This is where your `Stack` from Lesson 2 earns its keep. The idea:

1. Push your starting position onto the stack, and mark it visited.
2. Look at the position on **top** of the stack (that's where you
   currently "are").
   - If it's the exit, you're done! The stack, read from bottom to top,
     *is* the solved path.
   - Otherwise, look for a neighboring cell that (a) has no wall in the
     way, and (b) hasn't been visited yet.
     - **Found one?** Mark it visited, and push it. You've moved forward.
     - **Found nothing?** You're stuck -- this is a dead end. Pop the
       stack. That un-does your last move and puts you back where you
       were, so you can try a different direction from there.
3. Repeat step 2.

This is called **backtracking**: try a path, and if it doesn't work out,
undo your last step and try something else. The stack is what makes "undo
my last step" a single, cheap operation (`pop()`).

Notice that dead-end detours never make it into the final answer -- once
you pop them off, they're gone. Whatever is left on the stack when you
reach the exit is exactly the path that worked.

## Your job

Open `starter.cpp`. It already includes your own `Stack` class from
Lesson 2 (`../lesson2_stack/starter.cpp`) -- so make sure Lesson 2 is
working first, or this lesson can't pass either!

Implement:

```cpp
std::vector<Position> solveMazeWithBacktracking(const Maze& maze, Position start);
```

**Check directions in this order every time:** `NORTH`, `EAST`, `SOUTH`,
`WEST`. That keeps your answer predictable and matches what the test
expects.

**Tracking visited cells:** use a `std::vector<std::vector<bool>>` the
same size as the maze, all starting `false`.

**Reading the final answer off the stack:** once you break out of the
loop, the stack holds the solved path with the bottom (`stack.at(0)`)
being the start and the top (`stack.at(stack.size() - 1)`) being the exit.
Copy those into a `std::vector<Position>` and return it.

## Running the test

```
./run.sh
```

or:

```
g++ -std=c++17 -Wall -Wextra -o test_lesson4 test.cpp
./test_lesson4
```

The test uses a maze with two dead-end branches placed so that your
solver will walk into them before finding the exit -- so if backtracking
isn't working, the test will catch it.

## Stuck?

`solution.cpp` has a complete, working version -- try hard before you peek!
