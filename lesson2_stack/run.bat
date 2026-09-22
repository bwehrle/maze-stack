@echo off
cd /d "%~dp0"
g++ -std=c++17 -Wall -Wextra -o test_lesson2.exe test.cpp || exit /b 1
test_lesson2.exe
