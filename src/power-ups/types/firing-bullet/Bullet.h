#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "../../../map/Map.h"

class Bullet {

private:

    float _speed = 300;

    sf::Sprite _sprite;

    std::shared_ptr<Map> _map;

    unsigned int _shooter;

    enum Direction {
        LEFT = 0,
        RIGHT = 1,
        UP = 2,
        DOWN = 3
    };

    Direction _direction;

    bool _disappeared = false;

public:

    Bullet() = default;

    Bullet(sf::Vector2f position, std::shared_ptr<Map> map,
           unsigned int shooter, int direction);

    sf::FloatRect getPosition() const;

    const sf::Sprite &getSprite() const;

    unsigned int getShooter() const;

    void disappear();

    bool disappeared() const;

    void update(float dt_as_seconds);

};
