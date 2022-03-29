#pragma once

#include <SFML/Graphics.hpp>
#include "../../include/game_constants.h"

class Tile {

private:

    int _type;

    sf::Sprite _sprite;

public:

    explicit Tile(int type);

    void setPosition(int i, int j);

    const sf::Sprite &getSprite() const;

    bool isWall() const;

};