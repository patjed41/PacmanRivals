#include "ButtonAD.h"
#include "../../../texture-holder/TextureHolder.h"

#include <iostream>

float ButtonAD::_seconds_of_click_animation = 0.2f;

ButtonAD::ButtonAD(sf::Vector2f position, bool isA) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ButtonAD constructor.\n";
        exit(1);
    }

    _border.setTexture(TextureHolder::GetTexture("../assets/graphics/AD-button-border.png"));
    sf::FloatRect border_position = _border.getGlobalBounds();
    _border.setOrigin(border_position.width / 2, border_position.height / 2);
    _border.setPosition(position.x + border_position.width / 2,
                        position.y + border_position.height / 2);
    if (!isA) {
        _border.rotate(180.0f);
    }

    _letter.setFont(_font);
    _letter.setString(isA ? "A" : "D");
    _letter.setCharacterSize(55);
    _letter.setPosition(position.x + border_position.width / 3,
                        position.y + border_position.height / 4.2);

    // Button is not clicked at the beginning.
    _seconds_since_last_click = 2 * _seconds_of_click_animation;
}

void ButtonAD::click() {
    _seconds_since_last_click = 0;
}

bool ButtonAD::isClicked() {
    return _seconds_since_last_click < _seconds_of_click_animation;
}

void ButtonAD::update(float dt_as_seconds) {
    _seconds_since_last_click += dt_as_seconds;
}

void ButtonAD::draw(sf::RenderWindow *window) {
    window->draw(_border);

    if (isClicked()) {
        _letter.setFillColor(sf::Color::Red);
    }
    else {
        _letter.setFillColor(sf::Color::White);
    }
    _letter.setFont(_font);
    window->draw(_letter);
}
