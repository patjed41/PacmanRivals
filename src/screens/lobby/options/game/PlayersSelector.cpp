#include "PlayersSelector.h"

PlayersSelector::PlayersSelector(sf::RenderWindow* window) : Selector(window) {

}

void PlayersSelector::input() {
    // TODO: keys A-D change _current_players
    // TODO: set _current_selector_id to _my_id
}

void PlayersSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
}

void PlayersSelector::draw() {
    // TODO: draw this class (box with _current_players and A, D buttons)
}

unsigned int PlayersSelector::getCurrentPlayers() const {
    return _current_players;
}
