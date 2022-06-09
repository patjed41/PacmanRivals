#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../texture-holder/TextureHolder.h"
#include "../sound-manager/SoundManager.h"
#include "../screens/ScreenName.h"
#include "../screens/menu/MenuScreen.h"
#include "../screens/lobby/LobbyScreen.h"
#include "../screens/game/GameScreen.h"
#include "../screens/controls/ControlsScreen.h"
#include "../screens/between-rounds/BetweenRoundsScreen.h"
#include "../screens/game-over/GameOverScreen.h"

class GameEngine {

private:

    sf::RenderWindow _window;

    TextureHolder _texture_holder;

    SoundManager _sound_manager;

    ScreenName _current_screen;
    MenuScreen _menu;
    LobbyScreen _lobby;
    GameScreen _game;
    ControlsScreen _controls;
    BetweenRoundsScreen _between_rounds;
    GameOverScreen _game_over;

    void input();

    void update(float dt_as_seconds);

    void draw();

public:

    GameEngine();

    void run();

};