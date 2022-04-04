#include "Ghost.h"

void Ghost::moveForward(float dt_as_seconds) {
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

sf::Vector2i Ghost::getNextTile(sf::Vector2i tile) {
    sf::Vector2i res;
    switch (_direction) {
        case LEFT:
            res.x = tile.x - 1;
            res.y = tile.y;
            return res;
        case RIGHT:
            res.x = tile.x + 1;
            res.y = tile.y;
            return res;
        case UP:
            res.x = tile.x;
            res.y = tile.y - 1;
            return res;
        case DOWN:
            res.x = tile.x;
            res.y = tile.y + 1;
            return res;
        default:
            return res;
    }
}

Character::Direction Ghost::getOppositeDirection() {
    switch (_direction) {
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        default:
            return STOP;
    }
}

sf::Vector2i Ghost::getUpTile() {
    sf::FloatRect pos = getPosition();
    sf::Vector2i curr_tile = {(int) (pos.left / TILE_SIZE + 0.5), (int) (pos.top / TILE_SIZE + 0.5)};
    return {curr_tile.x, curr_tile.y - 1};
}

sf::Vector2i Ghost::getDownTile() {
    sf::FloatRect pos = getPosition();
    sf::Vector2i curr_tile = {(int) (pos.left / TILE_SIZE + 0.5), (int) (pos.top / TILE_SIZE + 0.5)};
    return {curr_tile.x, curr_tile.y + 1};
}

sf::Vector2i Ghost::getLeftTile() {
    sf::FloatRect pos = getPosition();
    sf::Vector2i curr_tile = {(int) (pos.left / TILE_SIZE + 0.5), (int) (pos.top / TILE_SIZE + 0.5)};
    return {curr_tile.x - 1, curr_tile.y};
}

sf::Vector2i Ghost::getRightTile() {
    sf::FloatRect pos = getPosition();
    sf::Vector2i curr_tile = {(int) (pos.left / TILE_SIZE + 0.5), (int) (pos.top / TILE_SIZE + 0.5)};
    return {curr_tile.x + 1, curr_tile.y};
}
