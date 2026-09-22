// Lesson 2: Stacks
// Read instructions.md before starting!

#pragma once

template <typename T>
class Stack {
public:
    Stack() {
        capacity_ = 4;
        data_ = new T[capacity_];
        size_ = 0;
    }

    ~Stack() {
        delete[] data_;
    }

    // TODO 1: Add `value` to the top of the stack.
    // If the array is full (size_ == capacity_), call grow() first.
    void push(const T& value) {
        // your code here
    }

    // TODO 2: Remove and return the value at the top of the stack.
    // You can assume pop() is never called on an empty stack.
    T pop() {
        // your code here
        return T();
    }

    // TODO 3: Return (without removing) the value at the top of the stack.
    T peek() const {
        // your code here
        return T();
    }

    // TODO 4: Return true if the stack has no elements.
    bool isEmpty() const {
        return true; // your code here
    }

    int size() const {
        return size_;
    }

    // Already implemented for you -- you'll use this in Lesson 4.
    // Returns the element at `index`, where 0 is the BOTTOM of the stack.
    T at(int index) const {
        return data_[index];
    }

private:
    T* data_;
    int capacity_;
    int size_;

    // TODO 5: Called by push() when the array is full.
    // Double capacity_, allocate a new array of that size, copy every
    // element from the old array into the new one, delete[] the old array,
    // and point data_ at the new one.
    void grow() {
        // your code here
    }
};
