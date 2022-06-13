#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "../map/Map.h"
#include "../../include/game_constants.h"

class Character {

protected:

    static const float _NORMAL_SPEED;

    float _speed = 100;

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

    void move(float dt_as_seconds);

    sf::Vector2i positionOfNewTile(sf::Vector2i tile) const;

    sf::Vector2i positionOfTileInNewDirection(sf::Vector2i new_tile, Direction _new_direction) const;

public:

    Character() = default;

    Character(sf::Sprite sprite, std::shared_ptr<Map> map);

    sf::FloatRect getPosition() const;

    sf::Vector2f getCenter() const;

    const sf::Sprite &getSprite() const;

    virtual void update(float dt_as_seconds) = 0;

    virtual ~Character() = default;

protected:

    bool reachedNewTile(float dt_as_seconds) const;

    void correct();

    void correctRight();

    void correctLeft();

    void correctUp();

    void correctDown();

};
