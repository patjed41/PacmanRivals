#pragma once

#include <SFML/Graphics.hpp>

#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/passing_walls/PassWall.h"

class TestPassWall : public PassWall {

public:
    void testUse(std::vector<std::shared_ptr<TestPacman>> pacmans, unsigned int user) {
        pacmans[user].get()->passWalls();
    }
};
