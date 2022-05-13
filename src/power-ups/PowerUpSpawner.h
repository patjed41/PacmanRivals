#pragma once

#include <memory>

#include "PowerUp.h"
#include "../map/Map.h"

class PowerUpSpawner {

private:

    std::shared_ptr<Map> _map;

public:

    void initialise(std::shared_ptr<Map> map);

    bool timeToSpawn();

    std::shared_ptr<PowerUp> spawn(std::vector<std::shared_ptr<Pacman>> pacmans,
                                   std::vector<PowerUp> power_ups);

};
