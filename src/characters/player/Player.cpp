#include "Player.h"

Player::Player(float start_tile_x, float start_tile_y) {
    _pacman = Pacman();
    _pacman.getSprite().setPosition(start_tile_x, start_tile_y);
}

sf::Sprite &Player::getSprite() {
    return _pacman.getSprite();
}

void Player::turnRight() {

}

void Player::turnLeft() {

}

void Player::turnUp() {

}

void Player::turnDown() {

}
