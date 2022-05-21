#include "../../src/characters/player/Pacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

#include <memory>

int main() {
    TextureHolder textureHolder;

    // Check bomberman.
    unsigned int bomberman = 10;
    Bomb bomb(sf::Vector2f(0, 0), bomberman);
    err::checkEqual(bomberman, bomb.getBomberman(), "check bomberman");

    // Check explosion timing.
    bomb = Bomb(sf::Vector2f(0, 0), 0);
    bomb.update(3.5);
    err::checkEqual(false, bomb.timeToExplode(), "check explosion timing 1");
    bomb.update(1);
    err::checkEqual(true, bomb.timeToExplode(), "check explosion timing 2");
    bomb.explode();
    err::checkEqual(false, bomb.timeToExplode(), "check explosion timing 3");

    // Check explosion reaches.
    std::shared_ptr<Map> map = std::make_shared<Map>();
    int position = 10;
    bomb = Bomb(sf::Vector2f(position * TILE_SIZE + 1, position * TILE_SIZE + 1), 0);
    Pacman pacman(map, 0, 0);
    for (size_t y = 0; y < MAP_HEIGHT; y++) {
        for (size_t x = 0; x < MAP_WIDTH; x++) {
            pacman = Pacman(map, x * TILE_SIZE, y * TILE_SIZE);
            bool result = y >= position - EXPLOSION_RADIUS && y <= position + EXPLOSION_RADIUS &&
                          x >= position - EXPLOSION_RADIUS && x <= position + EXPLOSION_RADIUS;
            err::checkEqual(result, bomb.explosionReaches(pacman.getPosition()), y * MAP_HEIGHT + x);
        }
    }
}

