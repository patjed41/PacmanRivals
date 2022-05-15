#include "SpeedUp.h"
#include "../../../texture-holder/TextureHolder.h"

SpeedUp::SpeedUp(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/place-holder.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void SpeedUp::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    pacmans[user]->speedUp();
}