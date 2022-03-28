#include "LevelManager.h"

#include <utility>
#include "../texture-holder/TextureHolder.h"

std::shared_ptr<Map> LevelManager::getGrid() {
    return _grid;
}

std::vector<std::shared_ptr<int>> &LevelManager::getGhosts() {
    return _ghosts;
}

std::vector<std::pair<int, int>> &LevelManager::getPlayerPositions() {
    return _player_positions;
}

void LevelManager::loadNewGrid() {
    // todo: inteligentne wybieranie numeru planszy

    std::ifstream myfile;
    myfile.open("../assets/maps/grids/grid1.txt");

    if (myfile.is_open()) {
        for (int i = 0; i < MAP_HEIGHT; i++) {
            _grid->getTiles().emplace_back();
            for (int j = 0; j < MAP_WIDTH; j++) {
                int tmp;
                myfile >> tmp;
                _grid->getTiles()[i].push_back(Tile(0));
                _grid->setTile(i, j, tmp);
            }
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file " << std::endl;
    }
}

// wersja tmp
void LevelManager::loadNewGhosts() {
    std::ifstream myfile;
    myfile.open("../assets/maps/ghosts/ghosts1.txt");

    std::vector<sf::Sprite> ghosts;
    if (myfile.is_open()) {
        int size;
        myfile >> size;

        for (int k = 0; k < size; k++) {
            ghosts.emplace_back(TextureHolder::GetTexture("../assets/graphics/ghost-pink.png"));
            std::string type;
            int i, j;
            myfile >> type >> i >> j;
            ghosts[k].setPosition(j * TILE_SIZE, i * TILE_SIZE);
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file " << std::endl;
    }
}

void LevelManager::loadNewPlayers() {

}

std::shared_ptr<Map> LevelManager::loadNewLevel() {
    loadNewGrid();
    loadNewGhosts();
    loadNewPlayers();
    return _grid;
}

LevelManager::LevelManager()  {
    std::shared_ptr<Map> test(new Map());
    _grid = test;
}


