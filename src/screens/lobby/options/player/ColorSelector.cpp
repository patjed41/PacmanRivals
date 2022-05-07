#include <iostream>
#include "ColorSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

ColorSelector::ColorSelector(sf::RenderWindow* window,  unsigned int player) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ColorSelector constructor.\n";
        exit(1);
    }

    _player = player;
    _pac_man_options.clear();
    _pac_man_options.emplace_back("lightblue");
    _pac_man_options.emplace_back("lightgreen");
    _pac_man_options.emplace_back("orange");
    _pac_man_options.emplace_back("pink");
    _pac_man_options.emplace_back("purple");

    sf::Vector2f positionA(700, player*220 + 100);
    sf::Vector2f positionPacman(900, player * 220 + 100);
    sf::Vector2f positionD(1100, player*220 + 100);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);
    _A = buttonA;
    _D = buttonD;

    _color.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + _pac_man_options[_current_index] + ".png"));
    _color.setScale(1.5, 1.5);

    _border.setTexture(TextureHolder::GetTexture("../assets/graphics/select-button-border.png"));
    sf::FloatRect border_position = _border.getGlobalBounds();
    _border.setOrigin(border_position.width / 2, border_position.height / 2);
    _border.setPosition(positionPacman.x + border_position.width / 2,
                        positionPacman.y + border_position.height / 2);

    _color.setPosition(positionPacman.x + border_position.width / 2.5,
                       positionPacman.y + border_position.height / 6);


}

void ColorSelector::input(const sf::Event &event) {
    // TODO: keys A-D change _current_color
    // TODO: set _current_selector_id to _my_id

    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            _current_index = (_current_index + _pac_man_options.size() - 1) % _pac_man_options.size(); //todo change size na const
            _color.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + _pac_man_options[_current_index] + ".png"));
            _color.setScale(1.5, 1.5);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            _current_index = (_current_index + _pac_man_options.size() + 1) % _pac_man_options.size();
            _color.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + _pac_man_options[_current_index] + ".png"));
            _color.setScale(1.5, 1.5);
        }
    }
    _current_selector_id = _my_id;
}

void ColorSelector::update(float dt_as_seconds) {
    // TODO: update A, D buttons
    _A.update(dt_as_seconds);
    _D.update(dt_as_seconds);
}

void ColorSelector::draw() {
    // TODO: draw this class (box with _current_color and A, D buttons)
    _A.draw(_window);

    if(_current_selector_id == _my_id) {
        _window->draw(_border);
    }
//    _number.setFont(_font);
    _window->draw(_color);

    _D.draw(_window);
}

std::string ColorSelector::getCurrentColor() const {
    return _current_color;
}
