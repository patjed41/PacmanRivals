#include "GameOptions.h"

GameOptions::GameOptions(sf::RenderWindow* window) : Options(window) {
    // TODO: construct selectors
}

void GameOptions::input(const sf::Event &event) {
    // TODO
    // Arrows left-right move between _players_selector and _rounds_selector
    // (change _current_selector).
    // Call input() on current selector.
}

void GameOptions::update(float dt_as_seconds) {
    // TODO
    // Update _players_selector and _rounds_selector.
}


void GameOptions::draw() {
    // TODO
    // Draw _players_selector and _rounds_selector.
}

bool GameOptions::allDone() const {
    return true;
}

unsigned int GameOptions::getNumberOfPlayers() {
    return _players_selector.getCurrentPlayers();
}

unsigned int GameOptions::getNumberOfRounds() {
    return _rounds_selector.getCurrentRounds();
}


