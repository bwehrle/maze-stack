#pragma once
// Tiny test-reporting helper used by every lesson's test.cpp.
// You don't need to edit this file.

#include <iostream>
#include <string>

struct TestResults {
    int passed = 0;
    int failed = 0;
};

inline TestResults& results() {
    static TestResults r;
    return r;
}

// Call this with a true/false condition and a description of what you
// checked. It prints PASS or FAIL and keeps score.
inline void check(bool condition, const std::string& description) {
    if (condition) {
        results().passed++;
        std::cout << "  [PASS] " << description << "\n";
    } else {
        results().failed++;
        std::cout << "  [FAIL] " << description << "\n";
    }
}

// Call this at the end of main(). Returns 0 if everything passed (so your
// shell will say "success"), 1 otherwise.
inline int reportAndExit() {
    std::cout << "\n" << results().passed << " passed, "
               << results().failed << " failed\n";
    if (results().failed == 0) {
        std::cout << "All tests passed! Great job.\n";
    } else {
        std::cout << "Some tests failed. Keep going -- read the [FAIL] lines above.\n";
    }
    return results().failed == 0 ? 0 : 1;
}
