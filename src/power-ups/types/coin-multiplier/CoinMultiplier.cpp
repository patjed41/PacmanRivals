#include "CoinMultiplier.h"
#include "../../../texture-holder/TextureHolder.h"

CoinMultiplier::CoinMultiplier(const sf::Vector2i &position) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/power-ups/coin-multiplier.png"));
    _sprite.setPosition(position.x * TILE_SIZE, position.y * TILE_SIZE);
}

void CoinMultiplier::use(std::vector<std::shared_ptr<Pacman>> pacmans, unsigned int user) {
        pacmans[user]->coinMultiply();
}