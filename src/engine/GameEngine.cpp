#include <ctime>

#include "GameEngine.h"

GameEngine::GameEngine() {
    _window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                 sf::VideoMode::getDesktopMode().height),
                                 "Pacman Rivals", sf::Style::Fullscreen);

    _menu = MenuScreen(&_window, &_current_screen);
    _lobby = LobbyScreen(&_window, &_current_screen);
    _game = GameScreen(&_window, &_current_screen);
    _between_rounds = BetweenRoundsScreen(&_window, &_current_screen);

    _current_screen = MENU;
    _menu.initialise();
}

void GameEngine::input() {
    switch (_current_screen) {
        case MENU:
            _menu.input();
            if (_current_screen == LOBBY) {
                _lobby.initialise();
            }
            return;
        case LOBBY:
            _lobby.input();
            if (_current_screen == MENU) {
                _menu.initialise();
            }
            else if (_current_screen == GAME) {
                _game.initialise(_lobby.getPlayerInfos(), _lobby.getRounds());
            }
            return;
        case GAME:
            _game.input();
            return;
        case BETWEEN_ROUNDS:
            _between_rounds.input();
            if (_current_screen == MENU) {
                _menu.initialise();
            }
            return;
        default:
            return;
    }
}

void GameEngine::update(float dt_as_seconds) {
    switch (_current_screen) {
        case MENU:
            _menu.update(dt_as_seconds);
            return;
        case LOBBY:
            _lobby.update(dt_as_seconds);
            return;
        case GAME:
            _game.update(dt_as_seconds);
            if (_current_screen == BETWEEN_ROUNDS) {
                _between_rounds.initialise(_game.getPlayerInfos());
            }
            return;
        case BETWEEN_ROUNDS:
            _between_rounds.update(dt_as_seconds);
            return;
        default:
            return;
    }
}

void GameEngine::draw() {
    switch (_current_screen) {
        case MENU:
            _menu.draw();
            return;
        case LOBBY:
            _lobby.draw();
            return;
        case GAME:
            _game.draw();
            return;
        case BETWEEN_ROUNDS:
            _between_rounds.draw();
            return;
        default:
            return;
    }
}

void GameEngine::run() {
    srand(time(nullptr));
    sf::Clock clock;

    while (_window.isOpen()) {
        sf::Time dt = clock.restart();
        float dt_as_seconds = dt.asSeconds();

        input();
        update(dt_as_seconds);
        draw();
    }
}