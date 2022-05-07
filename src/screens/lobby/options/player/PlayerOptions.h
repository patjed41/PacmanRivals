#pragma once

#include <SFML/Graphics.hpp>

#include "../Options.h"
#include "NickSelector.h"
#include "ColorSelector.h"
#include "ControlSelector.h"
#include "../../../game/PlayerInfo.h"

class PlayerOptions : Options {

    unsigned int _player;
    
    NickSelector _nick_selector;
    ColorSelector _color_selector;
    ControlSelector _control_selector;

public:

    PlayerOptions(unsigned int player, sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    bool allDone() const override;

    void freeOptions();

    PlayerInfo getPlayerInfo();

};

