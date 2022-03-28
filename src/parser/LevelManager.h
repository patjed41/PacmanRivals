#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>
#include "../map/Map.h"

class LevelManager {
private:
    std::shared_ptr<Map> _grid;
    //todo: int -> proper class
    std::vector<std::shared_ptr<int>> _ghosts;
    std::vector<std::pair<int, int>> _player_positions;

    void loadNewGrid();
    void loadNewGhosts();
    void loadNewPlayers();

public:

    LevelManager();

    std::shared_ptr<Map> getGrid();

    std::vector<std::shared_ptr<int>> &getGhosts();

    std::vector<std::pair<int, int>> &getPlayerPositions();

    std::shared_ptr<Map> loadNewLevel();
};
