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
    std::vector<sf::Vector2i> _players_positions;

    void loadNewGrid();
    void loadNewGhosts();
    void loadNewPlayers();

public:

    LevelManager();

    std::shared_ptr<Map> getGrid();

    std::vector<std::shared_ptr<int>> &getGhosts();

    std::vector<sf::Vector2i> &getPlayersPositions();

    std::shared_ptr<Map> loadNewLevel();

    std::vector<sf::Sprite> ghosts;
};
