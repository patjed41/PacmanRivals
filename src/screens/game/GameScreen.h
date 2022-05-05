#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"
#include "../../level-manager/LevelManager.h"
#include "../../characters/player/Pacman.h"
#include "../../coins/Coin.h"
#include "PlayerInfo.h"
#include "PlayerInputHandler.h"

class GameScreen : Screen {

private:

    sf::View _main_view; // view used for drawing game (map, characters, ...)

    LevelManager _level_manager;

    std::shared_ptr<Map> _grid;

    std::vector<std::shared_ptr<Ghost>> _ghosts;

    std::vector<PlayerInfo> _player_infos;

    std::vector<std::shared_ptr<Pacman>> _pacmans;

    std::vector<PlayerInputHandler> _player_input_handlers;

    std::unordered_map<int, Coin> _coins;

    bool _new_map_needed;

    unsigned int _players_num;

    unsigned int _rounds_left;

    void loadNewMap();

    void handleCollisionsPC();
    void handleCollisionsPG();

public:

    GameScreen() = default;

    GameScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise(std::vector<PlayerInfo> player_infos, unsigned int rounds);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
