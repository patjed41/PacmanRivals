#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "../Screen.h"
#include "../game/PlayerInfo.h"
#include "../../../include/game_constants.h"
#include "options/game/GameOptions.h"
#include "options/player/PlayerOptions.h"

class LobbyScreen : Screen {

private:

    sf::View _view;

    sf::Font _font;

    unsigned int _current_options;
    GameOptions _game_options;
    std::vector<PlayerOptions> _player_options;

public:

    LobbyScreen() = default;

    LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::vector<PlayerInfo> getPlayerInfos() const;

    unsigned int getRounds() const;

};
