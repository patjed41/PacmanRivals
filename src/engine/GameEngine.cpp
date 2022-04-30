#include <ctime>

#include "GameEngine.h"

GameEngine::GameEngine() {
    _window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                 sf::VideoMode::getDesktopMode().height),
                                 "Pacman Rivals", sf::Style::Fullscreen);

    _current_screen = MENU;
    _menu = MenuScreen(&_window, &_current_screen);
    _lobby = LobbyScreen(&_window, &_current_screen);
    _game = GameScreen(&_window, &_current_screen);
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