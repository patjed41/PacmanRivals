#pragma once

#include <cstdlib>

inline int random(int a, int b) {
    return rand() % (b - a + 1) + a;
}
