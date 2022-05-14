#pragma once

#include "../../PowerUp.h"

class FiringBullet : PowerUp {

public:

    FiringBullet();

    void use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) override;

};

