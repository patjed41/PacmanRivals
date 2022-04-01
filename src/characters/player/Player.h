#pragma once

#include "Pacman.h"

class Player {

private:

    Pacman _pacman;

public:

    Player(float start_tile_x, float start_tile_y);

    sf::Sprite &getSprite();

    void update(float dt_as_seconds);

    void turnRight();

    void turnLeft();

    void turnUp();

    void turnDown();

};

