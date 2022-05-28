#include "PowerUpSpawner.h"
#include "../../include/math.h"
#include "../../include/random.h"
#include "types/passing_walls/PassWall.h"
#include "types/spikes-placement/SpikesPlacement.h"

const float PowerUpSpawner::_SECONDS_BETWEEN_SPAWNS = 5.f;

PowerUpSpawner::PowerUpSpawner() {
    _power_ups = { COIN_MULTIPLIER, SPEED_UP, SLOW_DOWN, GLUTTONY, SHIELD,
                   WALL_PASSING, SPIKES_PLACEMENT, BOMB_PLACEMENT, FIRING_BULLET };
}

void PowerUpSpawner::initialise(std::shared_ptr<Map> grid) {
    _grid = grid;
    _seconds_to_next_spawn = _SECONDS_BETWEEN_SPAWNS;
}

void PowerUpSpawner::update(float dt_as_seconds) {
    _seconds_to_next_spawn -= dt_as_seconds;
}

bool PowerUpSpawner::timeToSpawn() {
    return _seconds_to_next_spawn <= 0;
}

std::vector<sf::Vector2i> PowerUpSpawner::findAvailableTiles(
    const std::vector<std::shared_ptr<Pacman>> &pacmans,
    const std::unordered_set<std::shared_ptr<PowerUp>> &power_ups
) {
    std::vector<sf::Vector2i> availableTiles;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            bool available = true;

            // Power-up cannot spawn on the wall.
            if (_grid->getTiles()[y][x].isWall()) {
                available = false;
            }

            sf::Vector2f tile_center(x * TILE_SIZE + TILE_SIZE / 2,
                                     y * TILE_SIZE + TILE_SIZE / 2);

            // Power-up cannot spawn too close to pacmans.
            for (const auto & pacman : pacmans) {
                if (!pacman->isDead() && manhattanDistance(tile_center, pacman->getCenter()) < 3 * TILE_SIZE) {
                    available = false;
                }
            }

            // Power-up cannot spawn too close to another power-up.
            for (const auto & power_up : power_ups) {
                sf::Vector2f power_up_center(power_up->getPosition().left + TILE_SIZE / 2,
                                             power_up->getPosition().top + TILE_SIZE / 2);
                if (manhattanDistance(tile_center, power_up_center) < 3 * TILE_SIZE) {
                    available = false;
                }
            }

            if (available) {
                availableTiles.push_back(sf::Vector2i(x, y));
            }
        }
    }

    return availableTiles;
}

// Returns nullptr if spawning was impossible.
std::shared_ptr<PowerUp> PowerUpSpawner::spawn(
    const std::vector<std::shared_ptr<Pacman>> &pacmans,
    const std::unordered_set<std::shared_ptr<PowerUp>> &power_ups
) {
    std::vector<sf::Vector2i> availableTiles = findAvailableTiles(pacmans, power_ups);
    if (availableTiles.size() == 0) {
        return nullptr;
    }

    _seconds_to_next_spawn = _SECONDS_BETWEEN_SPAWNS;

    sf::Vector2i spawn_tile = availableTiles[random(0, availableTiles.size() - 1)];
    PowerUpName power_up = _power_ups[random(0, _power_ups.size() - 1)];
    /*
    switch (power_up) {
        case COIN_MULTIPLIER:
            return std::static_pointer_cast<PowerUp>(std::make_shared<CoinMultiplier>(spawn_tile));
        case SPEED_UP:
            return std::static_pointer_cast<PowerUp>(std::make_shared<SpeedUp>(spawn_tile));
        case SLOW_DOWN:
            return std::static_pointer_cast<PowerUp>(std::make_shared<SlowDown>(spawn_tile));
        case GLUTTONY:
            return std::static_pointer_cast<PowerUp>(std::make_shared<Gluttony>(spawn_tile));
        case SHIELD:
            return std::static_pointer_cast<PowerUp>(std::make_shared<Shield>(spawn_tile));
        case WALL_PASSING:
            return std::static_pointer_cast<PowerUp>(std::make_shared<WallPassing>(spawn_tile));
        case SPIKES_PLACEMENT:
            return std::static_pointer_cast<PowerUp>(std::make_shared<SpikesPlacement>(spawn_tile));
        case BOMB_PLACEMENT:
            return std::static_pointer_cast<PowerUp>(std::make_shared<BombPlacement>(spawn_tile));
        case FIRING_BULLET:
            return std::static_pointer_cast<PowerUp>(std::make_shared<FiringBullet>(spawn_tile));
        default:
            return nullptr;
    }
    */
    int r = random(0, 8);
    if (r == 0) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<SlowDown>(spawn_tile));
    }
    else if (r == 1) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<SpeedUp>(spawn_tile));
    }
    else if (r == 2) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<Shield>(spawn_tile));
    }
    else if (r == 3) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<FiringBullet>(spawn_tile));
    }
    else if (r == 4) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<PassWall>(spawn_tile));
    }
    else if (r == 5) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<Gluttony>(spawn_tile));
    }
    else if (r == 6) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<SpikesPlacement>(spawn_tile));
    }
    else if (r == 7) {
        return std::static_pointer_cast<PowerUp>(std::make_shared<CoinMultiplier>(spawn_tile));
    }
    else {
        return std::static_pointer_cast<PowerUp>(std::make_shared<BombPlacement>(spawn_tile));
    }
}
