#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../texture-holder/TextureHolder.h"
#include "../level-manager/LevelManager.h"
#include "../characters/player/Pacman.h"
#include "../coins/Coin.h"
#include "../screens/Screen.h"
#include "../screens/menu/Menu.h"

class GameEngine {

private:

    sf::RenderWindow _window;

    sf::View _main_view; // view used for drawing game (map and characters)
    sf::View _ui_view; // view used for drawing UI

    TextureHolder _texture_holder;

    Screen _current_screen;

    Menu _menu;

    LevelManager _level_manager;

    std::shared_ptr<Map> _grid;

    std::vector<std::shared_ptr<Ghost>> _ghosts;

    std::vector<std::shared_ptr<Pacman>> _pacmans;

    std::unordered_map<int, Coin> _coins;

    bool _new_map_needed;

    int _players_num;

    void input();
    void inputGame();

    void update(float dt_as_seconds);
    void updateGame(float dt_as_seconds);

    void draw();
    void drawGame();

public:

    GameEngine();

    void run();

};