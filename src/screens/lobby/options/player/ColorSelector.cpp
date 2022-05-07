#include <iostream>
#include "ColorSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

std::vector<bool> ColorSelector::_available_colors = std::vector<bool>(10, true);

void ColorSelector::clearState() {
    _available_colors = std::vector<bool>(10, true);
}

ColorSelector::ColorSelector(sf::RenderWindow* window,  unsigned int player) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ColorSelector constructor.\n";
        exit(1);
    }

    _player = player;
    _pac_man_options.clear();
    _pac_man_options.emplace_back("lightblue");
    _pac_man_options.emplace_back("darkblue");
    _pac_man_options.emplace_back("lightgreen");
    _pac_man_options.emplace_back("darkgreen");
    _pac_man_options.emplace_back("orange");
    _pac_man_options.emplace_back("pink");
    _pac_man_options.emplace_back("purple");
    _pac_man_options.emplace_back("red");
    _pac_man_options.emplace_back("yellow");
    _pac_man_options.emplace_back("black");

    sf::Vector2f positionA(700, player * 220 + 100);
    sf::Vector2f positionPacman(900, player * 220 + 100);
    sf::Vector2f positionD(1100, player * 220 + 100);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);
    _A = buttonA;
    _D = buttonD;

    while (!_available_colors[_current_index]) {
        _current_index = (_current_index + 1) % _pac_man_options.size();
    }

    _available_colors[_current_index] = false;
    _current_color = _pac_man_options[_current_index];
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

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::A) {
            _available_colors[_current_index] = true;

            do {
                _current_index = (_current_index + _pac_man_options.size() - 1) % _pac_man_options.size();
            } while (!_available_colors[_current_index]);
            _available_colors[_current_index] = false;
            _current_color = _pac_man_options[_current_index];
            _color.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + _pac_man_options[_current_index] + ".png"));
            _color.setScale(1.5, 1.5);
            _A.click();
        }
        else if (event.key.code == sf::Keyboard::Key::D) {

            _available_colors[_current_index] = true;

            do {
                _current_index = (_current_index + _pac_man_options.size() + 1) % _pac_man_options.size();
            } while (!_available_colors[_current_index]);

            _available_colors[_current_index] = false;
            _current_color = _pac_man_options[_current_index];

            _color.setTexture(TextureHolder::GetTexture("../assets/graphics/pacmans/pac-man-" + _pac_man_options[_current_index] + ".png"));
            _color.setScale(1.5, 1.5);
            _D.click();
        }
    }
    _current_selector_id = _my_id;
}

void ColorSelector::update(float dt_as_seconds) {
    _A.update(dt_as_seconds);
    _D.update(dt_as_seconds);
}

void ColorSelector::draw() {
    _A.draw(_window);

    if(_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _window->draw(_color);

    _D.draw(_window);
}

std::string ColorSelector::getCurrentColor() const {
    return _current_color;
}

void ColorSelector::freeCurrentColor() const {
    _available_colors[_current_index] = true;
}