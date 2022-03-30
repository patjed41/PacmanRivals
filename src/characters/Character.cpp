#include "Character.h"

#include <utility>
#include <cmath>

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

bool Character::reachedNewTile(float dt_as_seconds) {
    sf::FloatRect position = getPosition();
    switch (_direction) {
        case LEFT:
            return int(position.left / TILE_SIZE) != int((position.left - _speed * dt_as_seconds) / TILE_SIZE);
        case RIGHT:
            return int(position.left / TILE_SIZE) != int((position.left + _speed * dt_as_seconds) / TILE_SIZE);
        case UP:
            return int(position.top / TILE_SIZE) != int((position.top - _speed * dt_as_seconds) / TILE_SIZE);
        case DOWN:
            return int(position.top / TILE_SIZE) != int((position.top + _speed * dt_as_seconds) / TILE_SIZE);
        default:
            return false;
    }

}

void Character::correctRight() {
    sf::FloatRect position = getPosition();
    position.left = std::floor(position.left / TILE_SIZE) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctLeft() {
    sf::FloatRect position = getPosition();
    position.left = (std::floor(position.left / TILE_SIZE + 1)) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctUp() {
    sf::FloatRect position = getPosition();
    position.top = (std::floor(position.top / TILE_SIZE) + 1) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

void Character::correctDown() {
    sf::FloatRect position = getPosition();
    position.top = std::floor(position.top / TILE_SIZE) * TILE_SIZE;
    _sprite.setPosition(position.left, position.top);
}

