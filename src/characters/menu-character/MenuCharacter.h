#pragma once

#include <SFML/Graphics.hpp>
#include "../Character.h"
#include "../ghosts/Ghost.h"

class MenuCharacter : public Character {
private:
    bool _if_random;

public:

    MenuCharacter(float start_tile_x, float start_tile_y,  int direction);

    void update(float dt_as_seconds) override;
};


