#include "Map.h"

std::vector<std::vector<Tile>> &Map::getTiles()  {
    return _tiles;
}

void Map::setTile(int i, int j, int type)  {
    Map::_tiles[i][j] = Tile(type);
    Map::_tiles[i][j].setPosition(i, j);
}

Map::Map() {
    _tiles = std::vector<std::vector<Tile>>( MAP_HEIGHT , std::vector<Tile> (MAP_WIDTH, Tile(0)));
}

