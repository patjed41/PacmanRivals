#include "../../src/characters/player/Pacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

#include <memory>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr<Map> map = std::make_shared<Map>();

    // Check disappearing.
    unsigned int shooter = 10;
    Bullet bullet(sf::Vector2f(0, 0), map, shooter, 0);
    err::checkEqual(false, bullet.disappeared(), "Disappearing 1");
    bullet.disappear();
    err::checkEqual(true, bullet.disappeared(), "Disappearing 2");

    // Check getShooter().
    err::checkEqual(shooter, bullet.getShooter(), "getShooter 1");

    // Check hitting wall:
    for (int x = 0; x < MAP_WIDTH; x++) {
        map->setTile(0, x, 1);
        map->setTile(MAP_HEIGHT - 1, x, 1);
    }
    for (int y = 0; y < MAP_HEIGHT; y++) {
        map->setTile(y, 0, 1);
        map->setTile(y, MAP_WIDTH - 1, 1);
    }
    // - while moving left
    bullet = Bullet(sf::Vector2f(500, 500), map, 0, 0);
    for (int i = 0; i < 1000; i++) {
        bullet.update(0.01);
    }
    err::checkEqual(true, bullet.disappeared(), "Hitting wall 1");
    // - while moving right
    bullet = Bullet(sf::Vector2f(500, 500), map, 0, 1);
    for (int i = 0; i < 1000; i++) {
        bullet.update(0.01);
    }
    err::checkEqual(true, bullet.disappeared(), "Hitting wall 2");
    // - while moving up
    bullet = Bullet(sf::Vector2f(500, 500), map, 0, 2);
    for (int i = 0; i < 1000; i++) {
        bullet.update(0.01);
    }
    // - while moving down
    err::checkEqual(true, bullet.disappeared(), "Hitting wall 3");
    bullet = Bullet(sf::Vector2f(500, 500), map, 0, 3);
    for (int i = 0; i < 1000; i++) {
        bullet.update(0.01);
    }
    err::checkEqual(true, bullet.disappeared(), "Hitting wall 4");
}
