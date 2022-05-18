#pragma once

#include "../../PowerUp.h"

class SpikesPlacement : public PowerUp {

public:

    int number_of_spikes = 3;

    SpikesPlacement() = default;

    SpikesPlacement(const sf::Vector2i &position);

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};

