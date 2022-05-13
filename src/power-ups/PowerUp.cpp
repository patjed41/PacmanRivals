#include "PowerUp.h"

const sf::Sprite &PowerUp::getSprite() const {
    return _sprite;
}

sf::FloatRect PowerUp::getPosition() const {
    return _sprite.getGlobalBounds();
}
