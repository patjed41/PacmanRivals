#include "Character.h"

sf::FloatRect Character::getPosition() {
    return _sprite.getGlobalBounds();
}

sf::Sprite &Character::getSprite() {
    return _sprite;
}

void Character::correctRight() {
    sf::FloatRect position = getPosition();
    position.left = position.left / TILE_SIZE * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctLeft() {
    sf::FloatRect position = getPosition();
    position.left = (position.left / TILE_SIZE + 1) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctUp() {
    sf::FloatRect position = getPosition();
    position.top = (position.top / TILE_SIZE + 1) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctDown() {
    sf::FloatRect position = getPosition();
    position.top = position.top / TILE_SIZE * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

