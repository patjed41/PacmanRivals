#include "Pacman.h"
#include "../../texture-holder/TextureHolder.h"

Pacman::Pacman(float start_tile_x, float start_tile_y) : Character() {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pac-man.png"));
    _direction = STOP;
    _new_direction = STOP;
    _sprite.setPosition(start_tile_x, start_tile_y);
}

void Pacman::update(float dt_as_seconds) {
    if (reachedNewTile(dt_as_seconds)) {
        if (_direction != _new_direction && _direction + _new_direction != 1 && _direction + _new_direction != 5) {
//        zawracanie
            if (_direction == LEFT) {
                correctLeft();
            } else if (_direction == RIGHT) {
                correctRight();
            } else if (_direction == UP) {
                correctUp();
            } else if (_direction == DOWN) {
                correctDown();
            }
        }
    }
    _direction = _new_direction;

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