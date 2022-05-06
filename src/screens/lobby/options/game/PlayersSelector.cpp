#include <iostream>
#include "PlayersSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

PlayersSelector::PlayersSelector(sf::RenderWindow* window) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ButtonAD constructor.\n";
        exit(1);
    }

    sf::Vector2f positionA(100, 100);
    sf::Vector2f positionNumber(300, 100);
    sf::Vector2f positionD(500, 100);

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
    _number.setString(char('0' + _current_players));
    _number.setCharacterSize(60);
    _number.setPosition(positionNumber.x + border_position.width / 2.5,
                        positionNumber.y + border_position.height / 6);


}

void PlayersSelector::input(const sf::Event &event) {
    // TODO: keys A-D change _current_players
    // TODO: set _current_selector_id to _my_id

    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (_current_players >= 2) {
                _current_players -= 1;
                _number.setString(char('0' + _current_players));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (_current_players <= 3) {
                _current_players += 1;
                _number.setString(char('0' + _current_players));
            }
        }
    }

    _current_selector_id = _my_id;
}

void PlayersSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
    _A.update(dt_as_seconds);
    _D.update(dt_as_seconds);
}

void PlayersSelector::draw() {
    // TODO: draw this class (box with _current_players and A, D buttons)
    _A.draw(_window);

    if(_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _number.setFont(_font);
    _window->draw(_number);

    _D.draw(_window);
}

unsigned int PlayersSelector::getCurrentPlayers() const {
    return _current_players;
}
