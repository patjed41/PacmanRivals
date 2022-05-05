#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../texture-holder/TextureHolder.h"
#include "../screens/ScreenName.h"
#include "../screens/menu/MenuScreen.h"
#include "../screens/lobby/LobbyScreen.h"
#include "../screens/game/GameScreen.h"
#include "../screens/between-rounds/BetweenRoundsScreen.h"

class GameEngine {

private:

    sf::RenderWindow _window;

    TextureHolder _texture_holder;

    ScreenName _current_screen;
    MenuScreen _menu;
    LobbyScreen _lobby;
    GameScreen _game;
    BetweenRoundsScreen _between_rounds;

    void input();

    void update(float dt_as_seconds);

    void draw();

public:

    GameEngine();

    void run();

};