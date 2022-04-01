#include "Player.h"

Player::Player(float start_tile_x, float start_tile_y) {
    _pacman = Pacman();
    _pacman.getSprite().setPosition(start_tile_x, start_tile_y);
}

sf::Sprite &Player::getSprite() {
    return _pacman.getSprite();
}

void Player::update(float dt_as_seconds) {
    _pacman.update(dt_as_seconds);
}

void Player::turnLeft() {
    _pacman.changeDirection(0);
}

void Player::turnRight() {
    _pacman.changeDirection(1);
}

void Player::turnUp() {
    _pacman.changeDirection(2);
}

void Player::turnDown() {
    _pacman.changeDirection(3);
}
