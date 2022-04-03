#pragma once

#include "../Character.h"

class Ghost : public Character {

public:

    ~Ghost() override = default;

protected:

    void moveForward(float dt_as_seconds);

    sf::Vector2i getNextTile(sf::Vector2i tile);

    void turnBack();

    sf::Vector2i getUpTile();

    sf::Vector2i getDownTile();

    sf::Vector2i getLeftTile();

    sf::Vector2i getRightTile();

};
