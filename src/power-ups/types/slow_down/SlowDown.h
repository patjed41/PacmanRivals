#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../PowerUp.h"

class SlowDown : public PowerUp {

public:

    SlowDown() = default;

    SlowDown(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};