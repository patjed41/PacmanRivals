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
}

void LobbyScreen::update(float dt_as_seconds) {
    // TODO
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

    _window->display();
}