#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"
#include "ScorePrinter.h"
#include "../game/PlayerInfo.h"

class BetweenRoundsScreen : Screen {

    sf::View _view;

    std::vector<ScorePrinter> _score_printers;

public:

    BetweenRoundsScreen() = default;

    BetweenRoundsScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise(const std::vector<PlayerInfo> & player_infos);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
