#include "LobbyScreen.h"

#include <iostream>

LobbyScreen::LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/capuche/Capuche Trial.otf")) {
        std::cerr << "Failed to load _font in LobbyScreen constructor.\n";
        exit(1);
    }
}

void LobbyScreen::initialise() {
    _current_options = 0;
    _player_options.clear();
    _game_options = GameOptions(_window);
    // 2 players are default
    _player_options.emplace_back(1, _window);
    _player_options.emplace_back(2, _window);
}

void LobbyScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                *_current_screen = MENU;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // TODO: check if everyhing is done and correct
                *_current_screen = GAME;
            }

            // TODO: Arrows up-down change _current_options cyclically.
        }
    }

    // TODO: input() on current option
}

void LobbyScreen::update(float dt_as_seconds) {
    // TODO: update() on all options
}

void LobbyScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    // should be deleted
    sf::Text example_text;
    example_text.setFont(_font);
    example_text.setString("Press Enter to start.");
    example_text.setCharacterSize(80);
    example_text.setFillColor(sf::Color::White);
    sf::FloatRect position = example_text.getGlobalBounds();
    example_text.setOrigin(position.width / 2, position.height / 2);
    example_text.setPosition(_view.getCenter().x, _view.getCenter().y);
    _window->draw(example_text);

    // TODO: draw() on all options

    _window->display();
}

std::vector<PlayerInfo> LobbyScreen::getPlayerInfos() const {
    // TODO: build and return vector containing information about players
    // temporary
    return std::vector<PlayerInfo>(1) = {PlayerInfo("CoolNick1", "yellow", "WASD"),
                                         PlayerInfo("CoolNick2", "yellow", "Arrows"),
                                         PlayerInfo("CoolNick3", "yellow", "C1"),
                                         PlayerInfo("CoolNick4", "yellow", "C2")};
}

unsigned int LobbyScreen::getRounds() const {
    // TODO: get information about number of rounds from _game_options and return
    return 5;
}
