#include <iostream>
#include "RoundsSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

RoundsSelector::RoundsSelector(sf::RenderWindow* window) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in RoundsSelector constructor.\n";
        exit(1);
    }

    float position_y = 130;
    sf::Vector2f positionA(750, position_y);
    sf::Vector2f positionNumber(950, position_y);
    sf::Vector2f positionD(1150, position_y);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);
    _A = buttonA;
    _D = buttonD;

    _info.setFont(_font);
    _info.setString("rounds");
    _info.setFillColor(sf::Color::Yellow);
    _info.setCharacterSize(50);
    _info.setPosition(880, 40);

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

void RoundsSelector::input(const sf::Event &event) {
    // TODO: keys A-D change _current_rounds
    // TODO: set _current_selector_id to _my_id

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::A) {
            if (_current_rounds > MIN_ROUNDS) {
                _current_rounds -= 1;
                _number.setString(char('0' + _current_rounds));
            }
            _A.click();
        }
        if (event.key.code == sf::Keyboard::Key::D) {
            if (_current_rounds < MAX_ROUNDS) {
                _current_rounds += 1;
                _number.setString(char('0' + _current_rounds));
            }
            _D.click();
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

    _info.setFont(_font);
    _window->draw(_info);

    if (_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _number.setFont(_font);
    _window->draw(_number);

    _D.draw(_window);
}

unsigned int RoundsSelector::getCurrentRounds() const {
    return _current_rounds;
}