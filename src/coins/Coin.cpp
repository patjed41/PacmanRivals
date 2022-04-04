#include "Coin.h"

#include "../../include/game_constants.h"
#include "../texture-holder/TextureHolder.h"

Coin::Coin(float tile_x, float tile_y) {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/coin2.png"));
    _sprite.setPosition(tile_x + (TILE_SIZE - COIN_SIZE) / 2, tile_y + (TILE_SIZE - COIN_SIZE) / 2);
}

void Coin::Take() {
    _is_taken = true;
}

bool Coin::isTaken() {
    return _is_taken;
}

sf::Sprite &Coin::getSprite() {
    return _sprite;
}

sf::FloatRect Coin::getPosition() {
    return _sprite.getGlobalBounds();
}