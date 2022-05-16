#include "Pacman.h"

#include <utility>
#include <iostream>
#include "../../texture-holder/TextureHolder.h"

const float Pacman::_POWER_UP_DURATION = 10.0f;
const float Pacman::_SLOW_SPEED = 50.0f;
const float Pacman::_FAST_SPEED = 200.0f;

// Constructs default yellow pacman.
Pacman::Pacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y) : Character() {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-yellow.png"));
    _sprite.setPosition(start_tile_x, start_tile_y);
    _direction = STOP;
    _new_direction = STOP;
    _is_dead = false;
    _pass_wall = false;
    _map = std::move(map);
}

void Pacman::changeColor(const std::string &color) {
    _sprite.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + color + ".png"));
}

bool Pacman::turningBack() const {
    if (_direction == RIGHT && _new_direction == LEFT) return true;
    if (_direction == LEFT && _new_direction == RIGHT) return true;
    if (_direction == UP && _new_direction == DOWN) return true;
    if (_direction == DOWN && _new_direction == UP) return true;
    return false;
}

void Pacman::handleMovement(float dt_as_seconds) {
    sf::FloatRect position = getPosition();

    sf::Vector2i current_tile = {(int)position.left / TILE_SIZE, (int)position.top / TILE_SIZE};
    sf::Vector2i new_tile = positionOfNewTile(current_tile);
    sf::Vector2i tile_in_new_direction = positionOfTileInNewDirection(current_tile, _new_direction);

    if (_direction == STOP) {
        if (!_map->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isWall()
            || (_pass_wall && !_map->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isEdge())) {
            _direction = _new_direction;
            move(dt_as_seconds);
        }
        return;
    }

    if (turningBack()) {
        _direction = _new_direction;
        return;
    }

    if (_direction == RIGHT) {
        current_tile = {(int)(position.left + position.width) / TILE_SIZE, (int)position.top / TILE_SIZE};
        new_tile = positionOfNewTile(current_tile);
        tile_in_new_direction = positionOfTileInNewDirection(current_tile, _new_direction);
    }
    else if (_direction == DOWN) {
        current_tile = {(int)position.left / TILE_SIZE, (int)(position.top + position.height) / TILE_SIZE};
        new_tile = positionOfNewTile(current_tile);
        tile_in_new_direction = positionOfTileInNewDirection(current_tile, _new_direction);
    }

    if (!reachedNewTile(dt_as_seconds)) {
        move(dt_as_seconds);
    }
    else {
        move(dt_as_seconds);
        if (_direction == _new_direction) {
            if (_map->getTiles()[new_tile.y][new_tile.x].isWall() && (!_pass_wall || _map->getTiles()[new_tile.y][new_tile.x].isEdge())) {
                correct();
                _direction = _new_direction = STOP;
            }
        }
        else {
            if (!_map->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isWall()
                || (_pass_wall && !_map->getTiles()[tile_in_new_direction.y][tile_in_new_direction.x].isEdge())) {
                correct();
                _direction = _new_direction;
                move(dt_as_seconds);
            }
            else if (_map->getTiles()[new_tile.y][new_tile.x].isWall() && (!_pass_wall || _map->getTiles()[new_tile.y][new_tile.x].isEdge())) {
                correct();
                _direction = STOP;
            }
        }
    }
}

void Pacman::handlePowerUpExpiry() {
    switch (_current_power_up) {
        case COIN_MULTIPLIER:
            // TODO
            break;
        case SPEED_UP:
            _speed = _NORMAL_SPEED;
            break;
        case GLUTTONY:
            // TODO
            break;
        case SHIELD:
            // TODO
            break;
        case WALL_PASSING:
            {
                _pass_wall = false;
                sf::FloatRect position = getPosition();
                sf::Vector2i current_tile = {(int)position.left / TILE_SIZE, (int)position.top / TILE_SIZE};
                if(_map->getTiles()[current_tile.y][current_tile.x].isWall()) {
                    bool done = false;
                    for (int i = 0; i < MAP_HEIGHT; ++i) {
                        for (int j = 0; j < MAP_WIDTH; ++j) {
                            if (current_tile.y > 0 && !_map->getTiles()[current_tile.y - i][current_tile.x - j].isWall()) {
                                setPosition(current_tile.x - j, current_tile.y - i);
                                done = true;
                                break;
                            }
                            else if (current_tile.y < MAP_HEIGHT - 2 && !_map->getTiles()[current_tile.y + i][current_tile.x + j].isWall()) {
                                setPosition(current_tile.x + j, current_tile.y + i);
                                done = true;
                                break;
                            }
                            else if (current_tile.x > 0 && !_map->getTiles()[current_tile.y - i][current_tile.x - j].isWall()) {
                                setPosition(current_tile.x - j, current_tile.y - i);
                                done = true;
                                break;
                            }
                            else if (current_tile.x < MAP_WIDTH - 2 && !_map->getTiles()[current_tile.y + i][current_tile.x + j].isWall()) {
                                setPosition(current_tile.x + j, current_tile.y + i);
                                done = true;
                                break;
                            }
                        }
                        if (done)
                            break;
                    }

                }

            }
            break;
        case SPIKES_PLACEMENT:
            // TODO
            break;
        case BOMB_PLACEMENT:
            // TODO
            break;
        case FIRING_BULLET:
            // TODO
            break;
        default:
            break;
    }

    _power_up_seconds_left = -1.0f;
    _current_power_up = NONE;
}

void Pacman::update(float dt_as_seconds) {
    handleMovement(dt_as_seconds);

    // Handle power-up expiry apart from SLOW_DOWN.
    if (_power_up_seconds_left >= 0 && _power_up_seconds_left - dt_as_seconds < 0) {
        handlePowerUpExpiry();
    }
    _power_up_seconds_left -= dt_as_seconds;

    // Handle SLOW_DOWN.
    if (_slow_down_seconds_left >= 0 && _slow_down_seconds_left - dt_as_seconds < 0) {
        if (_current_power_up != SPEED_UP) {
            _speed = _NORMAL_SPEED;
        }
    }
    _slow_down_seconds_left -= dt_as_seconds;
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

void Pacman::takeDamage() {
    // TODO: shield and immunity
    _current_power_up = NONE;
    _is_dead = true;
}

bool Pacman::isDead() const {
    return _is_dead;
}

float Pacman::getPartOfPowerUpTimeLeft() const {
    if (isDead() || _power_up_seconds_left < 0) {
        return 0;
    }
    else {
        return _power_up_seconds_left / _POWER_UP_DURATION;
    }
}

PowerUpName Pacman::getCurrentPowerUp() const {
    return _current_power_up;
}

bool Pacman::hasUsablePowerUp() const {
    return _current_power_up == BOMB_PLACEMENT ||
          (_current_power_up == FIRING_BULLET && _direction != STOP);
}

void Pacman::speedUp() {
    handlePowerUpExpiry();
    _current_power_up = SPEED_UP;
    _power_up_seconds_left = _POWER_UP_DURATION;
    _slow_down_seconds_left = -1.0f;
    _speed = _FAST_SPEED;
}

void Pacman::slowDown() {
    if (_current_power_up == SPEED_UP) {
        _current_power_up = NONE;
        _power_up_seconds_left = -1.0f;
    }
    _slow_down_seconds_left = _POWER_UP_DURATION;
    _speed = _SLOW_SPEED;
}

void Pacman::pickUpBullet() {
    handlePowerUpExpiry();
    _power_up_seconds_left = _POWER_UP_DURATION;
    _current_power_up = FIRING_BULLET;
}

std::shared_ptr<Bullet> Pacman::fireBullet(unsigned int shooter) {
    if (_current_power_up != FIRING_BULLET || _power_up_seconds_left < 0 ||
        _direction == STOP) {
        std::cerr << "fireBullet() call when it is impossible";
        exit(1);
    }

    handlePowerUpExpiry();
    // TODO: play firing sound
    return std::make_shared<Bullet>(getCenter(), _map, shooter, _direction);
}

void Pacman::passWalls() {
    handlePowerUpExpiry();
    _power_up_seconds_left = _POWER_UP_DURATION;
    _current_power_up = WALL_PASSING;
    _pass_wall = true;
}

void Pacman::setPosition(float tile_x, float tile_y) {
    _sprite.setPosition(tile_x * TILE_SIZE, tile_y * TILE_SIZE);
}

bool Pacman::inWall() {
    sf::FloatRect position = getPosition();
    sf::Vector2i current_tile = {(int)position.left / TILE_SIZE, (int)position.top / TILE_SIZE};
    return _map->getTiles()[current_tile.y][current_tile.x].isWall();
}
