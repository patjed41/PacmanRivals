#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "../../include/game_constants.h"
class Map {

private:
    std::vector<std::vector<Tile>> _tiles;

public:
    Map() = default;

    void setTile(int i, int j, int type);

    [[nodiscard]] std::vector<std::vector<Tile>> &getTiles();

    void draw(sf::RenderWindow window);

};