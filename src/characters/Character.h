#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "../map/Map.h"
#include "../../include/game_constants.h"

class Character {

protected:

    sf::Sprite _sprite;

    float _speed;

    std::shared_ptr<Map> map;

    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

public:

    sf::FloatRect getPosition();

    sf::Sprite &getSprite();

    virtual void update(float dt_as_seconds) = 0;

protected:

    void correctRight();

    void correctLeft();

    void correctUp();

    void correctDown();

};

