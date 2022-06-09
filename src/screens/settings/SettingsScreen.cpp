#include "SettingsScreen.h"

#include <iostream>

SettingsScreen::SettingsScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));
}

void SettingsScreen::initialise() {}

void SettingsScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = MENU;
            }
        }
    }
}

void SettingsScreen::update(float dt_as_seconds) {}

void SettingsScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);


    _window->display();
}
