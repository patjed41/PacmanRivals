#pragma once

#include <SFML/Graphics.hpp>

#include "../../../include/game_constants.h"
#include "../Character.h"

class Pacman : public Character {

protected:

    Direction _new_direction;

    bool turningBack();

public:

    Pacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y);

    void update(float dt_as_seconds) override;

    void turnLeft();

    void turnRight();

    void turnUp();

    void turnDown();

};

