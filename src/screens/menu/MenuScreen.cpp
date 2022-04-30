#include "MenuScreen.h"

#include <iostream>

const unsigned int MenuScreen::OPTIONS_NUM = 2;
const float MenuScreen::SPACE_BETWEEN = 200.f;

MenuScreen::MenuScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/capuche/Capuche Trial.otf")) {
        std::cerr << "Failed to load _menu_font.\n";
        exit(1);
    }

    _options = std::vector<sf::Text>(OPTIONS_NUM);
    _options[0].setString("New Game");
    _options[1].setString("Settings");
    // option_offset - vertical distance from screen's center of current option
    float option_offset = -SPACE_BETWEEN * (OPTIONS_NUM / 2);
    for (int i = 0; i < OPTIONS_NUM; i++) {
        _options[i].setFont(_font);
        _options[i].setCharacterSize(80);
        _options[i].setFillColor(sf::Color::White);
        sf::FloatRect option_position = _options[i].getGlobalBounds();
        _options[i].setOrigin(option_position.width / 2, option_position.height / 2);
        _options[i].setPosition(_view.getCenter().x, _view.getCenter().y + option_offset);
        option_offset += SPACE_BETWEEN;
    }
}

void MenuScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = LOBBY;
            }
        }
    }

    // TODO
}

void MenuScreen::update(float dt_as_seconds) {
    // TODO
}

void MenuScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    for (int i = 0; i < OPTIONS_NUM; i++) {
        _options[i].setFont(_font); // why is it needed? 100 points question
        _window->draw(_options[i]);
    }

    _window->display();
}
