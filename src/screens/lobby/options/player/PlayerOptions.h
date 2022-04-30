#pragma once

#include <SFML/Graphics.hpp>

#include "../Options.h"
#include "NickSelector.h"
#include "ColorSelector.h"
#include "ControlSelector.h"

class PlayerOptions : Options {

    unsigned int _player;
    
    NickSelector _nick_selector;
    ColorSelector _color_selector;
    ControlSelector _control_selector;

public:

    PlayerOptions(unsigned int player);

    void input() override;

    void draw(sf::RenderWindow& window) override;

    bool allDone() const override;

};

