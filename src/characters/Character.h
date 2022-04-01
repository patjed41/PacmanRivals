#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "../map/Map.h"
#include "../../include/game_constants.h"

class Character {

protected:

    float _speed = 30;

    sf::Sprite _sprite{};

    std::shared_ptr<Map> _map;

    enum Direction {
        LEFT = 0,
        RIGHT = 1,
        UP = 2,
        DOWN = 3,
        STOP = 4
    };

    Direction _direction;

public:

    Character() = default;

    Character(sf::Sprite sprite, std::shared_ptr<Map> map);

    sf::FloatRect getPosition();

    sf::Sprite &getSprite();

    virtual void update(float dt_as_seconds) = 0;

    virtual ~Character() = default;

protected:

    bool reachedNewTile(float dt_as_seconds);

    void correctRight();

    void correctLeft();

    void correctUp();

    void correctDown();

};

