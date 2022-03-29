#include "Character.h"

#include <utility>

Character::Character(sf::Sprite sprite, std::shared_ptr<Map> map) {
    _sprite = sprite;
    _map = std::move(map);
}

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
    if(position.left == position.left / TILE_SIZE * TILE_SIZE) return;
    position.left = (position.left / TILE_SIZE + 1) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctUp() {
    sf::FloatRect position = getPosition();
    if(position.top == position.top / TILE_SIZE * TILE_SIZE) return;
    position.top = (position.top / TILE_SIZE + 1) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctDown() {
    sf::FloatRect position = getPosition();
    position.top = position.top / TILE_SIZE * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

