#include <iostream>
#include "NickSelector.h"
#include "../../../../texture-holder/TextureHolder.h"
#include "../../../../../include/game_constants.h"

NickSelector::NickSelector(sf::RenderWindow* window, unsigned int player) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in NickSelector constructor.\n";
        exit(1);
    }

    _player = player;

    sf::Vector2f positionNick(125, player * 180 + 200);

    _border.setTexture(TextureHolder::GetTexture("../assets/graphics/select-button-border.png"));
    sf::FloatRect border_position = _border.getGlobalBounds();
    _border.setOrigin(border_position.width / 2, border_position.height / 2);
    _border.setPosition(positionNick.x + border_position.width / 2,
                        positionNick.y + border_position.height / 2);

    _nickname.setFont(_font);
    _nickname.setCharacterSize(60);
    _nickname.setPosition(positionNick.x + border_position.width / 2.5,
                          positionNick.y + border_position.height / 6);
}

void NickSelector::input(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "A";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "B";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "C";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "D";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "E";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "F";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "G";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "H";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "I";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "J";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "K";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "L";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "M";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "N";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "O";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "P";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "Q";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "R";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "S";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "T";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "U";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "V";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "W";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "X";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Y) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "Y";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "Z";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num0) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "0";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "1";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "2";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "3";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "4";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "5";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num6) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "6";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num7) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "7";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num8) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "8";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num9) {
        if (_current_nick.length() < NICKLEN_MAX)
            _current_nick += "9";
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace) {
        if (!_current_nick.empty()) {
            _current_nick.pop_back();
        }
    }

    _nickname.setString(_current_nick);
    _current_selector_id = _my_id;
}

void NickSelector::update(float dt_as_seconds) {}

void NickSelector::draw() {
    if (_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _nickname.setFont(_font);
    _window->draw(_nickname);
}

std::string NickSelector::getCurrentNick() const {
    return _current_nick.empty() ? ("player" + std::to_string(_player)) : _current_nick;;
}
