#include "Coin.h"

#include "../../include/game_constants.h"
#include "../texture-holder/TextureHolder.h"

Coin::Coin(float tile_x, float tile_y) {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/coin.png"));
    _sprite.setPosition(tile_x, tile_y);
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