#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../map/Map.h"
#include "../characters/ghosts/Ghost.h"
#include "../characters/player/Pacman.h"

class LevelManager {

private:

    std::shared_ptr<Map> _grid;
    std::vector<std::shared_ptr<Ghost>> _ghosts;
    std::vector<std::shared_ptr<Pacman>> _pacmans;

    void loadNewGrid();
    void loadNewGhosts();
    void loadNewPlayers();

public:

    LevelManager();

    std::shared_ptr<Map> getGrid();

    std::vector<std::shared_ptr<Ghost>> &getGhosts();

    std::vector<std::shared_ptr<Pacman>> &getPlayers();

    void loadNewLevel();

    void initialise();

};
