#pragma once

#include <SFML/Graphics.hpp>

#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/slow_down/SlowDown.h"

class TestSlowDown : public SlowDown {

public:
    void testUse(std::vector<std::shared_ptr<TestPacman>> pacmans, unsigned int user) {
        for (int i = 0; i < pacmans.size(); ++i) {
            if (i == user) continue;
            pacmans[i]->slowDown();
        }
    }
};
