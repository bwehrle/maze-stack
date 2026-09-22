#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
g++ -std=c++17 -Wall -Wextra -o test_lesson1 test.cpp
./test_lesson1
