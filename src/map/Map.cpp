#include "Map.h"

std::vector<std::vector<Tile>> &Map::getTiles()  {
    return _tiles;
}

void Map::setTile(int i, int j, int type) {
    setTile(i, j, type, 1);
}

void Map::setTile(int i, int j, int type, int color)  {
    Map::_tiles[i][j] = Tile(type, color);
    Map::_tiles[i][j].setPosition(i, j);
}

Map::Map() {
    _tiles = std::vector<std::vector<Tile>>(MAP_HEIGHT , std::vector<Tile> (MAP_WIDTH, Tile(0, 1)));
}

