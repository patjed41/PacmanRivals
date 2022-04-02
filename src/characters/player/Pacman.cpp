#include "Pacman.h"

#include <utility>
#include "../../texture-holder/TextureHolder.h"

Pacman::Pacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y) : Character() {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pac-man.png"));
    _sprite.setPosition(start_tile_x, start_tile_y);
    _direction = STOP;
    _new_direction = STOP;
    _map = std::move(map);
}

bool Pacman::turningBack() {
    if (_direction == RIGHT && _new_direction == LEFT) return true;
    if (_direction == LEFT && _new_direction == RIGHT) return true;
    if (_direction == UP && _new_direction == DOWN) return true;
    if (_direction == DOWN && _new_direction == UP) return true;
    return false;
}

void Pacman::move(float dt_as_seconds) {
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

sf::Vector2i Pacman::positionOfNewTile(sf::Vector2i tile) {
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

sf::Vector2i Pacman::positionOfTileInNewDirection(sf::Vector2i tile) {
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

void Pacman::update(float dt_as_seconds) {

    sf::FloatRect position = getPosition();

    sf::Vector2i current_tile = {(int)position.left / TILE_SIZE, (int)position.top / TILE_SIZE};
    sf::Vector2i new_tile = positionOfNewTile(current_tile);
    sf::Vector2i tile_in_new_direction = positionOfTileInNewDirection(current_tile);

    if (_direction == STOP) {
        if(!_map.get()->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isWall()) {
            _direction = _new_direction;
            move(dt_as_seconds);
        }
        return;
    }

    if(turningBack()) {
        _direction = _new_direction;
        return;
    }

    if (_direction == RIGHT) {
        current_tile = {(int)(position.left + position.width) / TILE_SIZE, (int)position.top / TILE_SIZE};
        new_tile = positionOfNewTile(current_tile);
        tile_in_new_direction = positionOfTileInNewDirection(current_tile);
    } else if (_direction == DOWN) {
        current_tile = {(int)position.left / TILE_SIZE, (int)(position.top + position.height) / TILE_SIZE};
        new_tile = positionOfNewTile(current_tile);
        tile_in_new_direction = positionOfTileInNewDirection(current_tile);
    }

    if (!reachedNewTile(dt_as_seconds)) {
        move(dt_as_seconds);
    } else {
        move(dt_as_seconds);
        if (_direction == _new_direction) {
            if(_map.get()->getTiles()[new_tile.y][new_tile.x].isWall()) {
                correct();
                _direction = _new_direction = STOP;
            }
        } else {
            if (!_map.get()->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isWall()) {
                correct();
                _direction = _new_direction;
                move(dt_as_seconds);
            } else if (_map.get()->getTiles()[new_tile.y][new_tile.x].isWall()) {
                correct();
                _direction = STOP;
            }
        }
    }
}

void Pacman::turnLeft() {
    _new_direction = LEFT;
}

void Pacman::turnRight() {
    _new_direction = RIGHT;
}

void Pacman::turnUp() {
    _new_direction = UP;
}

void Pacman::turnDown() {
    _new_direction = DOWN;
}