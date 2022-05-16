#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../PowerUp.h"

class PassWall : public PowerUp {

public:

    PassWall() = default;

    PassWall(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};