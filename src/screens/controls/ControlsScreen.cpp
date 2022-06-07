#include "ControlsScreen.h"

#include <iostream>

const unsigned int ControlsScreen::COLUMNS = 3;
const unsigned int ControlsScreen::ROWS = 4;
const float ControlsScreen::HEADER_Y = 120.f;
const float ControlsScreen::SPACE_BETWEEN = 150.f;
const float ControlsScreen::POSITION_OFFSET = 500.f;

ControlsScreen::ControlsScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ControlsScreen constructor.\n";
        exit(1);
    }

    _header.setFont(_font);
    _header.setString("controls info");
    _header.setFillColor(sf::Color::White);
    _header.setCharacterSize(60);
    sf::FloatRect header_position = _header.getGlobalBounds();
    _header.setOrigin(header_position.width / 2, header_position.height / 2);
    _header.setPosition(_view.getCenter().x, HEADER_Y);

    std::vector<std::vector<std::string>> table_text = {
            {"", "K1", "K2", "C1-C4"},
            {"movement", "WASD", "arrows", "left scroll"},
            {"use power-up", "x", "p", "a/x (controller)"}
    };

    std::vector<sf::Text> column_text(ROWS);
    for (int i = 0; i < ROWS; i++) {
        column_text[i].setFont(_font);
        column_text[i].setFillColor(sf::Color::White);
        column_text[i].setCharacterSize(40);
    }

    _table = std::vector<std::vector<sf::Text>>(COLUMNS);
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            column_text[j].setString(table_text[i][j]);
            column_text[j].setPosition(150 + i * POSITION_OFFSET, 320 + j * SPACE_BETWEEN);
            i == 0 ? column_text[j].setFillColor(sf::Color::Yellow) : column_text[j].setFillColor(sf::Color::White);
        }
        _table[i] = column_text;
        _table[i][0].setFillColor(sf::Color::Yellow);
    }
}

void ControlsScreen::initialise() {}

void ControlsScreen::input() {
    sf::Event event{};

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = MENU;
            }
        }
    }
}

void ControlsScreen::update(float dt_as_seconds) {}

void ControlsScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    _header.setFont(_font);
    _window->draw(_header);

    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            _table[i][j].setFont(_font);
            _window->draw(_table[i][j]);
        }
    }

    _window->display();
}
