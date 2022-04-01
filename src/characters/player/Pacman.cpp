#include "Pacman.h"
#include "../../texture-holder/TextureHolder.h"

Pacman::Pacman() : Character() {
    _sprite = sf::Sprite(TextureHolder::GetTexture("../assets/graphics/pac-man.png"));
    _direction = STOP;
//    _sprite.setPosition(start_tile_x, start_tile_y);
}

void Pacman::update(float dt_as_seconds) {
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

void Pacman::changeDirection(int d) {
    _direction = static_cast<Direction>(d);
}