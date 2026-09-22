# Lesson 2: Stacks

## The idea

A **stack** is a simple way to store a list of things where you only ever
add or remove from one end -- the "top." Think of a stack of plates: you
put a new plate on top, and you take plates off the top. You can't grab a
plate from the middle without moving the ones above it first.

This "last one in is the first one out" rule is called **LIFO**
(Last-In, First-Out). It turns out to be exactly the tool you need for
backtracking through a maze in Lesson 4: every time you move forward you
"push" your new position onto the stack, and if you hit a dead end you
"pop" back to where you were before.

## What you're building

A `Stack<T>` class that works for *any* type `T` (that's what the
`template <typename T>` means -- you'll use `Stack<int>` in this lesson's
test, and `Stack<Position>` in Lesson 4). Under the hood it's backed by a
plain array that you manage yourself with `new[]` / `delete[]`.

Open `starter.cpp`. The class already has:

- A constructor that allocates a small starting array (capacity 4).
- A destructor that frees it.
- Private fields: `data_` (the array), `capacity_` (how big the array is),
  `size_` (how many elements are actually stored).
- An already-implemented `at(index)` helper you'll use in Lesson 4.

You need to fill in:

1. **`push(value)`** -- add `value` to the top of the stack. If the array
   is full, call `grow()` first to make room.
2. **`pop()`** -- remove and return the top value. (You can assume the
   caller already checked the stack isn't empty.)
3. **`peek()`** -- return the top value *without* removing it.
4. **`isEmpty()`** -- true if there are no elements.
5. **`grow()`** -- called automatically when `push()` needs more room.
   Double `capacity_`, allocate a new array of that size, copy the old
   elements into it, `delete[]` the old array, and point `data_` at the
   new one.

## Running the test

```
./run.sh
```

or:

```
g++ -std=c++17 -Wall -Wextra -o test_lesson2 test.cpp
./test_lesson2
```

The test pushes more than 4 items (to make sure `grow()` works), checks
that items pop back out in reverse order, and checks it also works with a
`Stack<Position>` (a struct, not just a plain number) -- since that's what
you'll need in Lesson 4.

## Stuck?

`solution.cpp` has a complete, working version -- try hard before you peek!
