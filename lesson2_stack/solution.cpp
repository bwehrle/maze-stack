// Lesson 2: Stacks -- reference solution.
// Try to solve starter.cpp yourself before reading this!

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

    void push(const T& value) {
        if (size_ == capacity_) {
            grow();
        }
        data_[size_] = value;
        size_++;
    }

    T pop() {
        size_--;
        return data_[size_];
    }

    T peek() const {
        return data_[size_ - 1];
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

    T at(int index) const {
        return data_[index];
    }

private:
    T* data_;
    int capacity_;
    int size_;

    void grow() {
        int newCapacity = capacity_ * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
};
