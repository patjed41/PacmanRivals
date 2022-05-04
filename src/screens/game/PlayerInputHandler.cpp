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
        _pacman.get()->turnLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _pacman.get()->turnRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _pacman.get()->turnUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _pacman.get()->turnDown();
    }
}

void PlayerInputHandler::handleWASD() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _pacman.get()->turnLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _pacman.get()->turnRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _pacman.get()->turnUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _pacman.get()->turnDown();
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
            _pacman.get()->turnLeft();
        }
        else if (x > 0 && fabs(y) <= x) {
            _pacman.get()->turnRight();
        }
        else if (y < 0 && fabs(x) <= -y) {
            _pacman.get()->turnUp();
        }
        else {
            _pacman.get()->turnDown();
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
