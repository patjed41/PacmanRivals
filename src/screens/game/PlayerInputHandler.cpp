#include "PlayerInputHandler.h"

#include <cmath>
#include <iostream>

PlayerInputHandler::PlayerInputHandler(std::shared_ptr<Pacman> pacman, std::string control) {
    _pacman = pacman;

    _uses_arrows = _uses_WASD = false;
    if (control == "Arrows") {
        _uses_arrows = true;
    }
    else if (control == "WASD") {
        _uses_WASD = true;
    }
    else {
        _controller = control[1] - '1';
    }
}

void PlayerInputHandler::handleArrows() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _pacman->turnLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _pacman->turnRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _pacman->turnUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _pacman->turnDown();
    }

    _power_up_to_use = NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && _pacman->hasUsablePowerUp()) {
        _power_up_to_use = _pacman->getCurrentPowerUp();
    }
}

void PlayerInputHandler::handleWASD() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _pacman->turnLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _pacman->turnRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _pacman->turnUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _pacman->turnDown();
    }

    _power_up_to_use = NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && _pacman->hasUsablePowerUp()) {
        _power_up_to_use = _pacman->getCurrentPowerUp();
    }
}

void PlayerInputHandler::handleController() {
    if (sf::Joystick::isConnected(_controller)) {
        double x = sf::Joystick::getAxisPosition(_controller, sf::Joystick::X);
        double y = sf::Joystick::getAxisPosition(_controller, sf::Joystick::Y);

        // Controller is to close to the middle.
        if (x * x + y * y < 100) {
            return;
        }

        if (x < 0 && fabs(y) <= -x) {
            _pacman->turnLeft();
        }
        else if (x > 0 && fabs(y) <= x) {
            _pacman->turnRight();
        }
        else if (y < 0 && fabs(x) <= -y) {
            _pacman->turnUp();
        }
        else {
            _pacman->turnDown();
        }

        _power_up_to_use = NONE;
        if (sf::Joystick::isButtonPressed(_controller, 0) && _pacman->hasUsablePowerUp()) {
            _power_up_to_use = _pacman->getCurrentPowerUp();
        }
    }
}

void PlayerInputHandler::input() {
    if (_uses_arrows) {
        handleArrows();
    }
    else if (_uses_WASD) {
        handleWASD();
    }
    else {
        handleController();
    }
}

PowerUpName PlayerInputHandler::getPowerUpToUse() const {
    return _power_up_to_use;
}
