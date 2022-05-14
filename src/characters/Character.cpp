#include "Character.h"

#include <utility>
#include <cmath>

const float Character::_NORMAL_SPEED = 100;

Character::Character(sf::Sprite sprite, std::shared_ptr<Map> map) {
    _direction = STOP;
    _sprite = std::move(sprite);
    _map = std::move(map);
}

sf::FloatRect Character::getPosition() const {
    return _sprite.getGlobalBounds();
}

sf::Vector2f Character::getCenter() const {
    sf::FloatRect position = getPosition();
    return sf::Vector2f(position.left + position.width / 2,
                        position.top + position.height / 2);
}

const sf::Sprite &Character::getSprite() const {
    return _sprite;
}

void Character::move(float dt_as_seconds) {
    switch (_direction) {
        case LEFT:
            _sprite.setPosition(getPosition().left - _speed * dt_as_seconds, getPosition().top);
            break;
        case RIGHT:
            _sprite.setPosition(getPosition().left + _speed * dt_as_seconds, getPosition().top);
            break;
        case UP:
            _sprite.setPosition(getPosition().left, getPosition().top - _speed * dt_as_seconds);
            break;
        case DOWN:
            _sprite.setPosition(getPosition().left, getPosition().top + _speed * dt_as_seconds);
            break;
        default:
            return;
    }
}

sf::Vector2i Character::positionOfNewTile(sf::Vector2i tile) const {
    sf::Vector2i position;
    switch (_direction) {
        case LEFT:
            position.x = tile.x - 1;
            position.y = tile.y;
            return position;
        case RIGHT:
            position.x = tile.x + 1;
            position.y = tile.y;
            return position;
        case UP:
            position.x = tile.x;
            position.y = tile.y - 1;
            return position;
        case DOWN:
            position.x = tile.x;
            position.y = tile.y + 1;
            return position;
        default:
            return position;
    }
}

sf::Vector2i Character::positionOfTileInNewDirection(sf::Vector2i tile, Direction _new_direction) const {
    sf::Vector2i position;
    switch (_new_direction) {
        case LEFT:
            position.x = tile.x - 1;
            position.y = tile.y;
            return position;
        case RIGHT:
            position.x = tile.x + 1;
            position.y = tile.y;
            return position;
        case UP:
            position.x = tile.x;
            position.y = tile.y - 1;
            return position;
        case DOWN:
            position.x = tile.x;
            position.y = tile.y + 1;
            return position;
        default:
            return position;
    }
}

bool Character::reachedNewTile(float dt_as_seconds) const {
    sf::FloatRect position = getPosition();
    switch (_direction) {
        case LEFT:
            return int(position.left / TILE_SIZE) != int((position.left - _speed * dt_as_seconds) / TILE_SIZE);
        case RIGHT:
            return int((position.left + position.width) / TILE_SIZE) != int((position.left + position.width + _speed * dt_as_seconds) / TILE_SIZE);
        case UP:
            return int(position.top / TILE_SIZE) != int((position.top - _speed * dt_as_seconds) / TILE_SIZE);
        case DOWN:
            return int((position.top + position.height) / TILE_SIZE) != int((position.top + position.height + _speed * dt_as_seconds) / TILE_SIZE);
        default:
            return false;
    }

}

void Character::correct() {
    switch (_direction) {
        case RIGHT:
            correctRight();
            break;
        case LEFT:
            correctLeft();
            break;
        case UP:
            correctUp();
            break;
        case DOWN:
            correctDown();
            break;
        default:
            break;
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
