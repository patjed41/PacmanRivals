#include "PassWall.h"
#include "../../../texture-holder/TextureHolder.h"

PassWall::PassWall(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/wall-breaker.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void PassWall::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    pacmans[user].get()->passWalls();
}
