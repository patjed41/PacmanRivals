#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"
#include "WinnerPrinter.h"
#include "../game/PlayerInfo.h"

class GameOverScreen : Screen {

    sf::View _view;

    sf::Font _font;

    sf::Text _game_over_text;

    std::vector<WinnerPrinter> _winner_printers;

public:

    GameOverScreen() = default;

    GameOverScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise(const std::vector<PlayerInfo> & player_infos);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
