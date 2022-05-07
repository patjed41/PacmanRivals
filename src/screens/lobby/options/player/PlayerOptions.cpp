#include <iostream>
#include "PlayerOptions.h"

PlayerOptions::PlayerOptions(unsigned int player, sf::RenderWindow* window) : Options(window) {
    _player = player;

    _nick_selector = NickSelector(_window, player);
    _color_selector = ColorSelector(_window, player);
    _control_selector = ControlSelector(_window, player);

    // TODO: construct selectors
}

void PlayerOptions::input(const sf::Event &event) {

    if (event.type == sf::Event::KeyPressed) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _current_selector = (_current_selector + 3 + 1) % 3; // TODO : create a const, currently 3
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _current_selector  = (_current_selector + 3 - 1) % 3;
        }
    }

    if (_current_selector == 0){
        _nick_selector.input(event);
    }
    else if (_current_selector == 1){
        _color_selector.input(event);
    }
    else {
        _control_selector.input(event);
    }
    // TODO
    // Arrows left-right move between _nick_selector and _color_selector, _control_selector
    // // (change _current_selector).
    // Call input() on current selector.
}

void PlayerOptions::update(float dt_as_seconds) {
    _nick_selector.update(dt_as_seconds);
    _color_selector.update(dt_as_seconds);
    _control_selector.update(dt_as_seconds);
    // TODO
    // Update _nick_selector and _color_selector, _control_selector.
}


void PlayerOptions::draw() {
    _nick_selector.draw();
    _color_selector.draw();
    _control_selector.draw();
    // TODO
    // Draw _nick_selector and _color_selector, _control_selector.
}

bool PlayerOptions::allDone() const {
    // TODO
    return true;
    // Are _nick_selector, _color_selector, _control_selector done?
}

PlayerInfo PlayerOptions::getPlayerInfo() {
    return PlayerInfo(_nick_selector.getCurrentNick(),
                      _color_selector.getCurrentColor(),
                      _control_selector.getCurrentControl());
}
