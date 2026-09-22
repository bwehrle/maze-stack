#include "../common/maze_types.h"
#include "../common/test_utils.h"
#include "starter.cpp"
#include <iostream>

int main() {
    std::cout << "Lesson 2: Stacks\n=================\n\n";

    std::cout << "basic push/peek/pop with ints\n";
    Stack<int> s;
    check(s.isEmpty() == true, "a brand new stack is empty");
    s.push(10);
    check(s.isEmpty() == false, "stack is not empty after a push");
    check(s.peek() == 10, "peek() returns the last pushed value");
    check(s.size() == 1, "size() is 1 after one push");

    s.push(20);
    s.push(30);
    check(s.peek() == 30, "peek() returns the MOST recently pushed value");
    check(s.size() == 3, "size() is 3 after three pushes");

    check(s.pop() == 30, "pop() returns 30 first (LIFO order)");
    check(s.pop() == 20, "pop() returns 20 next");
    check(s.size() == 1, "size() is 1 after two pops");
    check(s.pop() == 10, "pop() returns 10 last");
    check(s.isEmpty() == true, "stack is empty after popping everything");

    std::cout << "\ngrowing past the initial capacity\n";
    Stack<int> big;
    for (int i = 0; i < 10; ++i) {
        big.push(i * 100);
    }
    check(big.size() == 10, "stack holds all 10 pushed elements");
    bool orderCorrect = true;
    for (int i = 9; i >= 0; --i) {
        if (big.pop() != i * 100) {
            orderCorrect = false;
            break;
        }
    }
    check(orderCorrect, "all 10 elements pop back out in reverse (LIFO) order");
    check(big.isEmpty() == true, "stack is empty after popping all 10");

    std::cout << "\nworks with a struct type (Position), not just int\n";
    Stack<Position> positions;
    positions.push(Position{0, 0});
    positions.push(Position{1, 0});
    positions.push(Position{1, 1});
    check((positions.peek() == Position{1, 1}), "peek() works for Position too");
    check((positions.pop() == Position{1, 1}), "pop() works for Position too");
    check((positions.pop() == Position{1, 0}), "LIFO order holds for Position too");

    std::cout << "\nat() reads from the bottom without modifying the stack\n";
    Stack<int> forAt;
    forAt.push(1);
    forAt.push(2);
    forAt.push(3);
    check(forAt.at(0) == 1, "at(0) is the bottom-most element");
    check(forAt.at(2) == 3, "at(2) is the top-most element");
    check(forAt.size() == 3, "at() does not change the stack's size");

    return reportAndExit();
}
