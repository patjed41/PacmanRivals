#include "Map.h"

std::vector<std::vector<Tile>> &Map::getTiles()  {
    return _tiles;
}

void Map::setTile(int i, int j, int type)  {

    Map::_tiles[i][j] = Tile(type);
    Map::_tiles[i][j].setPosition(i, j);
}

// todo: poprawne przekazanie okna
void Map::draw(sf::RenderWindow window) {
    for (int i = 0; i < MAP_HEIGHT; i++){
        for (int j = 0; j < MAP_WIDTH; j++){
            window.draw( _tiles[i][j].getSprite());
        }
    }
}
