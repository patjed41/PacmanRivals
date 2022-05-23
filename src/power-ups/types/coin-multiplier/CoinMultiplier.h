#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../../PowerUp.h"

class CoinMultiplier : public PowerUp {

public:

    CoinMultiplier() = default;

    CoinMultiplier(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};