#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../characters/player/Pacman.h"

class PowerUp {

protected:

    sf::Sprite _sprite;

public:

    const sf::Sprite &getSprite() const;

    sf::FloatRect getPosition() const;

    virtual void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) = 0;

};
