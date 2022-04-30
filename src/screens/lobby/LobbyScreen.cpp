#include "LobbyScreen.h"

#include <iostream>

LobbyScreen::LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/capuche/Capuche Trial.otf")) {
        std::cerr << "Failed to load _menu_font.\n";
        exit(1);
    }

    // TODO
}

void LobbyScreen::initialise() {
    _current_options = 0;
    _player_options.clear();
    _game_options = GameOptions();
    // 2 players are default
    _player_options.push_back(PlayerOptions(1));
    _player_options.push_back(PlayerOptions(2));

    // TODO
}

void LobbyScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                *_current_screen = MENU;
            }

            // temporary
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = GAME;
            }
        }
    }

    // TODO
    // Arrows up-down change _current_options.
    // input() on current option
}

void LobbyScreen::update(float dt_as_seconds) {
    // TODO OR NOT TODO
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

    // TODO
    // draw() on all options

    _window->display();
}

std::vector<PlayerInfo> LobbyScreen::getPlayerInfos() const {
    // temporary
    return std::vector<PlayerInfo>(1);
}

unsigned int LobbyScreen::getRounds() const {
    // temporary
    return 10;
}
