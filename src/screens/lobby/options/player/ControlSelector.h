#pragma once

#include <string>

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"

static std::vector<bool> available_controls(6, true);

class ControlSelector : Selector {

private:

    unsigned int _player;

    std::string _current_control;

    unsigned int _current_index = 0;

    std::vector<std::string> _control_options;

    sf::Text _control;

    sf::Font _font;

    sf::Sprite _border;

public:

    ButtonAD _A;

    ButtonAD _D;

    ControlSelector() = default;

    ControlSelector(sf::RenderWindow* window, unsigned int player);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentControl() const;

};
