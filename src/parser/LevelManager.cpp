#include "LevelManager.h"

#include <utility>
#include "../texture-holder/TextureHolder.h"

std::shared_ptr<Map> LevelManager::getGrid() {
    return _grid;
}

std::vector<std::shared_ptr<int>> &LevelManager::getGhosts() {
    return _ghosts;
}

std::vector<sf::Vector2i> &LevelManager::getPlayersPositions() {
    return _players_positions;
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
        std::cerr << "Can't find input file" << std::endl;
    }
}

// wersja tmp
enum ghost_enum
{
    RANDOM,
    NOTRANDOM,
};

ghost_enum convert(const std::string& str)
{
    if(str == "random") return RANDOM;
    else if(str == "not_random") return NOTRANDOM;
    else return RANDOM; // space holder
}
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
            int i, j, n;
            myfile >> type;
            ghost_enum ghost_type = convert(type);
            switch (ghost_type) {
                case RANDOM :
                    myfile >> i >> j;
                    break;
                case NOTRANDOM :
                    myfile >> n >> i >> j;
                    break;
            }
            ghosts[k].setPosition(j * TILE_SIZE, i * TILE_SIZE);
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
    }
}

void LevelManager::loadNewPlayers() {
    std::ifstream myfile;
    myfile.open("../assets/maps/players/players1.txt");

    if (myfile.is_open()) {
        int size;
        myfile >> size;

        for (int k = 0; k < size; k++) {
            int i, j;
            myfile >> i >> j;
            _players_positions.emplace_back(sf::Vector2(i, j));
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
    }
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


