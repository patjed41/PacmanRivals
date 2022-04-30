#include "PlayerOptions.h"

PlayerOptions::PlayerOptions(unsigned int player) {
    _player = player;
    // TODO
}

void PlayerOptions::input() {
    // TODO
    // Arrows left-right move between _nick_selector and _color_selector, _control_selector.
    // Handle input of actually selected.
}

void PlayerOptions::draw(sf::RenderWindow& window) {
    // TODO
    // Draw _nick_selector and _color_selector, _control_selector.
}

bool PlayerOptions::allDone() const {
    // TODO
    return true;
    // Are _nick_selector and _color_selector, _control_selector done?
}
