#include "LevelManager.h"

#include "../texture-holder/TextureHolder.h"
#include "../characters/player/Pacman.h"

std::shared_ptr<Map> LevelManager::getGrid() {
    return _grid;
}

std::vector<std::shared_ptr<int>> &LevelManager::getGhosts() {
    return _ghosts;
}

std::vector<std::shared_ptr<Pacman>> &LevelManager::getPlayers() {
    return _pacmans;
}

void LevelManager::loadNewGrid() {
    std::ifstream myfile;
    myfile.open("../assets/maps/grids/grid1.txt");

    if (myfile.is_open()) {
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                int tmp;
                myfile >> tmp;
                _grid->setTile(i, j, tmp);
            }
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }
}

// wersja tmp
enum GhostEnum {
    RANDOM,
    NOTRANDOM,
};

GhostEnum convert(const std::string& str) {
    if (str == "random") return RANDOM;
    else if (str == "not_random") return NOTRANDOM;
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
            GhostEnum ghost_type = convert(type);
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
        exit(1);
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
            _pacmans.emplace_back(std::make_shared<Pacman>(_grid, float(i) * TILE_SIZE, float(j) * TILE_SIZE));
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }
}

void LevelManager::loadNewLevel() {
    // todo: inteligentne wybieranie numeru planszy
    loadNewGrid();
    loadNewGhosts();
    loadNewPlayers();
}

LevelManager::LevelManager() {
    _grid = std::make_shared<Map>();
}


