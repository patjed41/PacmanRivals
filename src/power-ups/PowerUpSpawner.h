#pragma once

#include <memory>
#include <unordered_set>

#include "PowerUp.h"
#include "PowerUpName.h"
#include "../map/Map.h"
#include "types/firing-bullet/FiringBullet.h"
#include "types/slow_down/SlowDown.h"
#include "types/speed_up/SpeedUp.h"
#include "types/shield/Shield.h"

class PowerUpSpawner {

private:

    std::shared_ptr<Map> _grid;

    std::vector<PowerUpName> _power_ups;

    static const float _SECONDS_BETWEEN_SPAWNS;
    float _seconds_to_next_spawn;

    std::vector<sf::Vector2i> findAvailableTiles(
        const std::vector<std::shared_ptr<Pacman>> &pacmans,
        const std::unordered_set<std::shared_ptr<PowerUp>> &power_ups
    );

public:

    PowerUpSpawner();

    void initialise(std::shared_ptr<Map> grid);

    void update(float dt_as_seconds);

    bool timeToSpawn();

    std::shared_ptr<PowerUp> spawn(const std::vector<std::shared_ptr<Pacman>> &pacmans,
                                   const std::unordered_set<std::shared_ptr<PowerUp>> &power_ups);

};
