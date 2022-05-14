#pragma once

#include "../../PowerUp.h"

class FiringBullet : public PowerUp {

public:

    FiringBullet() = default;

    FiringBullet(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};

