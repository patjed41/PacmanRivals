#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"
#include "../../level-manager/LevelManager.h"
#include "../../characters/player/Pacman.h"
#include "../../coins/Coin.h"

class GameScreen : Screen {

private:

    sf::View _main_view; // view used for drawing game (map, characters, ...)

    LevelManager _level_manager;

    std::shared_ptr<Map> _grid;

    std::vector<std::shared_ptr<Ghost>> _ghosts;

    std::vector<std::shared_ptr<Pacman>> _pacmans;

    std::unordered_map<int, Coin> _coins;

    bool _new_map_needed;

    int _players_num;

public:

    GameScreen() = default;

    GameScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise() override;

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
