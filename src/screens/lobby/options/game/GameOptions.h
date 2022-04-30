#pragma once

#include <SFML/Graphics.hpp>

#include "../Options.h"
#include "PlayersSelector.h"
#include "RoundsSelector.h"

class GameOptions : Options {

private:

    PlayersSelector _players_selector;

    RoundsSelector _rounds_selector;

public:

    GameOptions();

    void input() override;

    void draw(sf::RenderWindow& window) override;

    bool allDone() const override;

};
