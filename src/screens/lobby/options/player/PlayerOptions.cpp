#include "PlayerOptions.h"

PlayerOptions::PlayerOptions(unsigned int player) {
    _player = player;
    // TODO: construct selectors
}

void PlayerOptions::input() {
    // TODO
    // Arrows left-right move between _nick_selector and _color_selector, _control_selector
    // // (change _current_selector).
    // Call input() on current selector.
}

void PlayerOptions::update(float dt_as_seconds) {
    // TODO
    // Update _nick_selector and _color_selector, _control_selector.
}


void PlayerOptions::draw(sf::RenderWindow* window) {
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
