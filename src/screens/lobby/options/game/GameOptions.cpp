#include <iostream>
#include "GameOptions.h"

GameOptions::GameOptions(sf::RenderWindow* window) : Options(window) {
    // TODO: construct selectors
    _players_selector = PlayersSelector(_window);
    _rounds_selector = RoundsSelector(_window);
}

void GameOptions::input() {

//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//        _window->close();
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        _current_selector = (_current_selector + 2 + 1) % 2; // currently 2
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        _current_selector  = (_current_selector + 2 - 1) % 2;
//
//    }
    if (_current_selector == 0){
        _players_selector.input();
    }
    else {
        _rounds_selector.input();
    }
    // TODO
    // Arrows left-right move between _players_selector and _rounds_selector
    // (change _current_selector).
    // Call input() on current selector.
}

void GameOptions::update(float dt_as_seconds) {
    _players_selector.update(dt_as_seconds);
    _rounds_selector.update(dt_as_seconds);
    // TODO
    // Update _players_selector and _rounds_selector.
}


void GameOptions::draw() {
    _players_selector.draw();
    _rounds_selector.draw();
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


