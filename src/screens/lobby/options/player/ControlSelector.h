#pragma once

#include <string>

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"

class ControlSelector : Selector {

private:

    unsigned int _player;

    std::string _current_control = "none";

    unsigned int _current_index = 0;

    std::vector<std::string> _control_options;

    static std::vector<bool> _available_controls;

    sf::Text _control;

    sf::Font _font;

    sf::Sprite _border;

    ButtonAD _A;

    ButtonAD _D;

public:

    ControlSelector() = default;

    ControlSelector(sf::RenderWindow* window, unsigned int player);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentControl() const;

    static void clearState();

    void freeCurrentControl() const;

};
