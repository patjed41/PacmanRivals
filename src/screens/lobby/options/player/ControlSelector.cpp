#include <iostream>
#include "ControlSelector.h"
#include "../../../../texture-holder/TextureHolder.h"

std::vector<bool> ControlSelector::_available_controls = std::vector<bool>(6, true);

void ControlSelector::clearState() {
    _available_controls = std::vector<bool>(6, true);
}

ControlSelector::ControlSelector(sf::RenderWindow* window, unsigned int player) : Selector(window) {
    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in ControlSelector constructor.\n";
        exit(1);
    }

    _player = player;
    _control_options.clear();
    _control_options.emplace_back("K1");
    _control_options.emplace_back("K2");
    _control_options.emplace_back("C1");
    _control_options.emplace_back("C2");
    _control_options.emplace_back("C3");
    _control_options.emplace_back("C4");

    sf::Vector2f positionA(1300, player * 220 + 100);
    sf::Vector2f positionControl(1450, player * 220 + 100);
    sf::Vector2f positionD(1700, player * 220 + 100);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);
    _A = buttonA;
    _D = buttonD;

    while (!_available_controls[_current_index]) {
        _current_index = (_current_index + 1) % _control_options.size();
    }
    _available_controls[_current_index] = false;
    _current_control = _control_options[_current_index];

    _border.setTexture(TextureHolder::GetTexture("../assets/graphics/select-button-border.png"));
    sf::FloatRect border_position = _border.getGlobalBounds();
    _border.setOrigin(border_position.width / 2, border_position.height / 2);
    _border.setPosition(positionControl.x + border_position.width / 2,
                        positionControl.y + border_position.height / 2);

    _control.setFont(_font);
    _control.setCharacterSize(60);
    _control.setString(_current_control);
    _control.setPosition(positionControl.x + border_position.width / 2.5,
                         positionControl.y + border_position.height / 6);
}

void ControlSelector::input(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
        _available_controls[_current_index] = true;
        do {
            _current_index = (_current_index + _control_options.size() - 1) % _control_options.size();
        } while (!_available_controls[_current_index]);
        _available_controls[_current_index] = false;
        _current_control = _control_options[_current_index];
        _control.setString(_current_control);
        _A.click();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
        _available_controls[_current_index] = true;
        do {
            _current_index = (_current_index + 1) % _control_options.size();
        } while (!_available_controls[_current_index]);
        _available_controls[_current_index] = false;
        _current_control = _control_options[_current_index];
        _control.setString(_current_control);
        _D.click();
    }

    _current_selector_id = _my_id;
}

void ControlSelector::update(float dt_as_seconds) {
    _A.update(dt_as_seconds);
    _D.update(dt_as_seconds);
}

void ControlSelector::draw() {
    _A.draw(_window);

    if (_current_selector_id == _my_id) {
        _window->draw(_border);
    }
    _control.setFont(_font);
    _window->draw(_control);

    _D.draw(_window);
}

std::string ControlSelector::getCurrentControl() const {
    if (_current_control == "K1") {
        return "Arrows";
    }
    if (_current_control == "K2") {
        return "WASD";
    }
    return _current_control;
}

void ControlSelector::freeCurrentControl() {
    _available_controls[_current_index] = true;
}

