#include <iostream>

#include "ControllerChecker.h"

const unsigned int ControllerChecker::CONTROLLERS_NUM = 4;
const float ControllerChecker::_SECONDS_OF_CLICK_ANIMATION = 0.2f;

ControllerChecker::ControllerChecker(sf::RenderWindow* window) : _window(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ControllerChecker constructor.\n";
        exit(1);
    }

    _controller_name = {"C1", "C2", "C3", "C4"};

    const float horizontal_offset = 140;
    _controller_info.resize(CONTROLLERS_NUM);
    _seconds_since_last_click.resize(CONTROLLERS_NUM);
    for (int controller = 0; controller < CONTROLLERS_NUM; controller++) {
        _controller_info[controller].setFont(_font);
        _controller_info[controller].setCharacterSize(60);
        _controller_info[controller].setString(_controller_name[controller]);
        _controller_info[controller].setPosition(1300 + controller * horizontal_offset, 120);
        // Controller's buttons are not clicked at the beginning.
        _seconds_since_last_click[controller] = 2 * _SECONDS_OF_CLICK_ANIMATION;
    }
}

void ControllerChecker::input() {
    for (int controller = 0; controller < CONTROLLERS_NUM; controller++) {
        bool is_button_pressed = false;
        if (sf::Joystick::isConnected(controller)) {
            for (int button = 0; button < 8; button++) {
                if (sf::Joystick::isButtonPressed(controller, button)) {
                    is_button_pressed = true;
                }
            }
        }

        if (is_button_pressed) {
            _seconds_since_last_click[controller] = 0;
        }
    }
}

void ControllerChecker::update(float dt_as_seconds) {
    for (int controller = 0; controller < CONTROLLERS_NUM; controller++) {
        _seconds_since_last_click[controller] += dt_as_seconds;
    }
}

void ControllerChecker::draw() {
    for (int controller = 0; controller < CONTROLLERS_NUM; controller++) {
        if (!sf::Joystick::isConnected(controller)) {
            _controller_info[controller].setFillColor(sf::Color(166, 166, 166, 100));
        }
        else if (_seconds_since_last_click[controller] < _SECONDS_OF_CLICK_ANIMATION) {
            _controller_info[controller].setFillColor(sf::Color::Red);
        }
        else {
            _controller_info[controller].setFillColor(sf::Color::White);
        }

        _controller_info[controller].setFont(_font);
        _window->draw(_controller_info[controller]);
    }
}
