#pragma once

#include <SFML/Graphics.hpp>

#include "../texture-holder/TextureHolder.h"
#include "../level-manager/LevelManager.h"

class GameEngine {

private:

    sf::RenderWindow _window;

    sf::View _main_view; // view used for drawing game (map and characters)

    TextureHolder _texture_holder;

    LevelManager _level_manager;

    bool _new_map_needed;

    void input();

    void update(float dt_as_seconds);

    void draw();

public:

    GameEngine();

    void run();

};
