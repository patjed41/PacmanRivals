#include "../../src/characters/player/Pacman.h"
#include "../../src/power-ups/PowerUpSpawner.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/random.h"
#include "../../include/math.h"

int main() {
    TextureHolder textureHolder;

    PowerUpSpawner spawner;

    std::vector<std::shared_ptr<Pacman>> no_pacmans;
    std::unordered_set<std::shared_ptr<PowerUp>> no_power_ups;

    // Check spawn() when map consists of walls only.
    std::shared_ptr<Map> map = std::make_shared<Map>();
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map->setTile(y, x, 1);
        }
    }
    spawner.initialise(map);
    spawner.update(100.f);
    err::checkEqual(true, spawner.timeToSpawn(), "Only walls 1");
    err::check(nullptr == spawner.spawn(no_pacmans, no_power_ups), "Only walls 2");

    // Check spawn() when map is full of players.
    std::vector<std::shared_ptr<Pacman>> pacmans;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map->setTile(y, x, 0);
            pacmans.push_back(std::make_shared<Pacman>(map, x * TILE_SIZE, y * TILE_SIZE));
        }
    }
    spawner.initialise(map);
    spawner.update(100.f);
    err::checkEqual(true, spawner.timeToSpawn(), "Full of players 1");
    err::check(nullptr == spawner.spawn(pacmans, no_power_ups), "Full of players 2");

    // Check spawn() when map is full of speed-up-down.
    spawner.initialise(map);
    std::unordered_set<std::shared_ptr<PowerUp>> power_ups;
    while (true) {
        spawner.update(100.f);
        err::checkEqual(true, spawner.timeToSpawn(), "Full of speed-up-down 1");
        std::shared_ptr<PowerUp> new_power_up = spawner.spawn(no_pacmans, power_ups);
        if (new_power_up == nullptr) {
            break;
        }
        power_ups.insert(new_power_up);
    }
    err::check(power_ups.size() > MAP_WIDTH * MAP_HEIGHT / (6 * 6), "Full of speed-up-down 2");
    err::check(power_ups.size() < MAP_WIDTH * MAP_HEIGHT / (2 * 2), "Full of speed-up-down 3");

    // Check distance between players.
    spawner.initialise(map);
    pacmans.clear();
    pacmans.push_back(nullptr);
    for (int test = 0; test < 10000; test++) {
        pacmans[0] = std::make_shared<Pacman>(
            map, random(0, MAP_HEIGHT - 1) * TILE_SIZE, random(0, MAP_WIDTH - 1) * TILE_SIZE);
        spawner.update(100.f);
        err::checkEqual(true, spawner.timeToSpawn(), "Distance 1");
        std::shared_ptr<PowerUp> power_up = spawner.spawn(pacmans, no_power_ups);
        err::check(power_up != nullptr, "Distance 2");
        if (power_up == nullptr) break;
        sf::Vector2f power_up_center = sf::Vector2f(power_up->getPosition().left + TILE_SIZE / 2,
                                                    power_up->getPosition().top + TILE_SIZE / 2);
        err::check(manhattanDistance(pacmans[0]->getCenter(), power_up_center) >= 3 * TILE_SIZE, "Distance 3");
    }
}
