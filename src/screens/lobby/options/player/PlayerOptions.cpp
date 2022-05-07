#include <iostream>
#include "PlayerOptions.h"

PlayerOptions::PlayerOptions(unsigned int player, sf::RenderWindow* window) : Options(window) {
    _player = player;

    _nick_selector = NickSelector(_window, player);
    _color_selector = ColorSelector(_window, player);
    _control_selector = ControlSelector(_window, player);

}

void PlayerOptions::input(const sf::Event &event) {

    if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Key::Right) {
            _current_selector = (_current_selector + 3 + 1) % 3; // TODO : create a const, currently 3
        }
        else if (event.key.code == sf::Keyboard::Key::Left) {
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
}

void PlayerOptions::update(float dt_as_seconds) {
    _nick_selector.update(dt_as_seconds);
    _color_selector.update(dt_as_seconds);
    _control_selector.update(dt_as_seconds);
}


void PlayerOptions::draw() {
    _nick_selector.draw();
    _color_selector.draw();
    _control_selector.draw();
}

bool PlayerOptions::allDone() const {
    if (_color_selector.getCurrentColor() == "none" || _control_selector.getCurrentControl() == "none"
    || _nick_selector.getCurrentNick().empty())
        return false;

    return true;
}

PlayerInfo PlayerOptions::getPlayerInfo() {
    return PlayerInfo(_nick_selector.getCurrentNick(),
                      _color_selector.getCurrentColor(),
                      _control_selector.getCurrentControl());
}

void PlayerOptions::freeOptions() {
    _color_selector.freeCurrentColor();
    _control_selector.freeCurrentControl();
}
