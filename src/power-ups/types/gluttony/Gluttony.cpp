#include "Gluttony.h"
#include "../../../texture-holder/TextureHolder.h"

Gluttony::Gluttony(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/pac-man-eater.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void Gluttony::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    pacmans[user]->startEating();
}