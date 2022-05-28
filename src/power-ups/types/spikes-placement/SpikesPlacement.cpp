#include "SpikesPlacement.h"
#include "../../../texture-holder/TextureHolder.h"

SpikesPlacement::SpikesPlacement(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/thorns.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void SpikesPlacement::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
    pacmans[user]->pickUpSpikes();
}
