#pragma once

#include "../../PowerUp.h"

class BombPlacement : public PowerUp {

public:

    BombPlacement() = default;

    BombPlacement(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};
