#pragma once

#include <string>

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"

class ColorSelector : Selector {

private:

    unsigned int _player;

    std::string _current_color = "lightblue"; // default

    sf::Sprite _color;

    sf::Font _font;

    sf::Sprite _border;

public:

    ButtonAD _A;

    ButtonAD _D;

    ColorSelector() = default;

    ColorSelector(sf::RenderWindow* window, unsigned int _player);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentColor() const;

};
