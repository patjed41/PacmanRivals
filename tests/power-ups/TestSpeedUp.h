#pragma once

#include <SFML/Graphics.hpp>

#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/speed_up/SpeedUp.h"

class TestSpeedUp : public SpeedUp {

public:
    void testUse(std::vector<std::shared_ptr<TestPacman>> pacmans, unsigned int user) {
        pacmans[user].get()->setSpeed(200.f);
    }
};
