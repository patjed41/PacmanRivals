#include "Shield.h"
#include "../../../texture-holder/TextureHolder.h"

Shield::Shield(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/shield.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void Shield::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
        pacmans[user]->setShield();
}