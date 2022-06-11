#pragma once

#include "../Character.h"

class Ghost : public Character {

public:

    ~Ghost() override = default;

protected:

    sf::Vector2i getUpTile() const;

    sf::Vector2i getDownTile() const;

    sf::Vector2i getLeftTile() const;

    sf::Vector2i getRightTile() const;

};
