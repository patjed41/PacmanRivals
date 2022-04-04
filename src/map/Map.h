#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "../../include/game_constants.h"

class Map {

private:

    std::vector<std::vector<Tile>> _tiles;

public:

    Map();

    void setTile(int i, int j, int type);

    std::vector<std::vector<Tile>> &getTiles();

};