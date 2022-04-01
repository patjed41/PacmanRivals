#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>
#include "../map/Map.h"
#include "../characters/player/Player.h"

class LevelManager {

private:

    std::shared_ptr<Map> _grid;
    //todo: int -> proper class
    std::vector<std::shared_ptr<int>> _ghosts;
    std::vector<std::shared_ptr<Player>> _players;

    void loadNewGrid();
    void loadNewGhosts();
    void loadNewPlayers();

public:

    LevelManager();

    std::shared_ptr<Map> getGrid();

    std::vector<std::shared_ptr<int>> &getGhosts();

    std::vector<std::shared_ptr<Player>> &getPlayers();

    void loadNewLevel();

};
