#include <iostream>
#include "RoundsSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

RoundsSelector::RoundsSelector(sf::RenderWindow* window) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/coolvetica/coolvetica condensed rg.otf")) {
        std::cerr << "Failed to load _font in ButtonAD constructor.\n";
        exit(1);
    }

    sf::Vector2f positionA(700, 100);
    sf::Vector2f positionNumber(900, 100);
    sf::Vector2f positionD(1100, 100);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);
    _A = buttonA;
    _D = buttonD;

    _border.setTexture(TextureHolder::GetTexture("../assets/graphics/select-button-border.png"));
    sf::FloatRect border_position = _border.getGlobalBounds();
    _border.setOrigin(border_position.width / 2, border_position.height / 2);
    _border.setPosition(positionNumber.x + border_position.width / 2,
                        positionNumber.y + border_position.height / 2);

    _number.setFont(_font);
    _number.setString(char('0' + _current_rounds));
    _number.setCharacterSize(60);
    _number.setPosition(positionNumber.x + border_position.width / 2.5,
                        positionNumber.y + border_position.height / 6);


}

void RoundsSelector::input() {
    // TODO: keys A-D change _current_rounds
    // TODO: set _current_selector_id to _my_id
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if (_current_rounds >= 2) {
                    _current_rounds -= 1;
                    _number.setString(char('0' + _current_rounds));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                if (_current_rounds <= 9) {
                    _current_rounds += 1;
                    _number.setString(char('0' + _current_rounds));
                }
            }
        }
    }
    _current_selector_id = _my_id;
}

void RoundsSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
    _A.update(dt_as_seconds);
    _D.update(dt_as_seconds);
}

void RoundsSelector::draw() {
    // TODO: draw this class (box with _current_rounds and A, D buttons)
    _A.draw(_window);

    if(_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _window->draw(_number);

    _D.draw(_window);
}

unsigned int RoundsSelector::getCurrentRounds() const {
    return _current_rounds;
}