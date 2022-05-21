#pragma once

#include <SFML/Graphics.hpp>

#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/shield/Shield.h"

class TestShield : public Shield {

public:
    void testUse(std::vector<std::shared_ptr<TestPacman>> pacmans, unsigned int user) {
        pacmans[user]->setShield();
    }
};
