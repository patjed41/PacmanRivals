#include "RoundsSelector.h"

void RoundsSelector::input() {
    // TODO: keys A-D change _current_players
    // TODO: set _current_selector_id to _my_id
}

void RoundsSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
}

void RoundsSelector::draw(sf::RenderWindow* window) {
    // TODO: draw this class (box with _current_rounds and A, D buttons)
}

unsigned int RoundsSelector::getCurrentRounds() const {
    return _current_rounds;
}