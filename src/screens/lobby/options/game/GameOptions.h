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

    GameOptions() = default;

    GameOptions(sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    bool allDone() const override;

    unsigned int getNumberOfPlayers();

    unsigned int getNumberOfRounds();

};
