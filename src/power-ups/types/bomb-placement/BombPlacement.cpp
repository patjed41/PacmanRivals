#include "BombPlacement.h"
#include "../../../texture-holder/TextureHolder.h"

BombPlacement::BombPlacement(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/bomb-setter.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void BombPlacement::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    pacmans[user]->pickUpBomb();
}
