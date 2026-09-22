# Maze Runner: C++ Challenge

Four short lessons that build up, step by step, to a maze-solving program
that can backtrack out of dead ends.

| Lesson | Folder | What you'll build |
|---|---|---|
| 1 | `lesson1_bitmasks/` | Functions to read/write maze walls packed into a single `int` |
| 2 | `lesson2_stack/` | Your own `Stack<T>` class, built on a raw array |
| 3 | `lesson3_maze_runner/` | A maze walker for simple mazes with no dead ends |
| 4 | `lesson4_backtracking/` | A maze solver that uses your `Stack` to backtrack out of dead ends |

## How each lesson works

Every lesson folder has the same four files:

- **`instructions.md`** -- read this first. Explains the idea and what to do.
- **`starter.cpp`** -- the file you actually edit. Has `// TODO` comments
  marking what to fill in.
- **`test.cpp`** -- checks your work. You don't need to edit this, just run it.
- **`solution.cpp`** -- a complete reference answer, in case you get stuck.
  Try hard before you look!

## Running a lesson

From inside a lesson folder:

```
./run.sh
```

If that doesn't work (e.g. "permission denied"), run:

```
chmod +x run.sh
./run.sh
```

or just compile and run directly:

```
g++ -std=c++17 -Wall -Wextra -o test_lessonN test.cpp
./test_lessonN
```

You'll see a `[PASS]` or `[FAIL]` line for every check. Keep editing
`starter.cpp` and re-running until everything passes.

## Suggested order

Do the lessons in order -- 1, 2, 3, 4. Lesson 4 actually `#include`s your
Lesson 2 `Stack`, so it won't work until Lesson 2 is solid.

## Shared code

The `common/` folder has code shared by every lesson (maze representation,
the test-checking helper, an optional ASCII-art maze printer). You
shouldn't need to edit anything in there -- it's just plumbing.
