#include "LevelManager.h"

#include "../characters/ghosts/LinearGhost.h"
#include "../characters/ghosts/CycleGhost.h"
#include "../characters/ghosts/RandomGhost.h"
#include "../texture-holder/TextureHolder.h"

LevelManager::LevelManager() {
    _grid = std::make_shared<Map>();
}

std::shared_ptr<Map> LevelManager::getGrid() {
    return _grid;
}

std::vector<std::shared_ptr<Ghost>> &LevelManager::getGhosts() {
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
    LINEAR,
    CYCLE,
    RANDOM,
};

GhostEnum convert(const std::string& str) {
    if (str == "linear") return LINEAR;
    else if (str == "cycle") return CYCLE;
    else if (str == "random") return RANDOM;
    else return RANDOM; // space holder
}

void LevelManager::loadNewGhosts() {
    std::ifstream myfile;
    myfile.open("../assets/maps/ghosts/ghosts1.txt");

    if (myfile.is_open()) {
        int size;
        myfile >> size;

        for (int k = 0; k < size; k++) {
            std::string type;
            int i, j, n;
            myfile >> type;
            GhostEnum ghost_type = convert(type);
            switch (ghost_type) {
                case LINEAR : {
                    myfile >> i >> j >> n;
                    _ghosts.emplace_back(std::static_pointer_cast<Ghost>(std::make_shared<LinearGhost>(_grid, i, j, n)));
                    break;
                }
                case CYCLE : {
                    myfile >> i >> j >> n;
                    std::vector<int> directions(n);
                    for (int l = 0; l < n; l++) {
                        myfile >> directions[l];
                    }
                    _ghosts.emplace_back(std::static_pointer_cast<Ghost>(std::make_shared<CycleGhost>(_grid, i, j, directions)));
                    break;
                }
                case RANDOM : {
                    myfile >> i >> j >> n;
                    _ghosts.emplace_back(std::static_pointer_cast<Ghost>(std::make_shared<RandomGhost>(_grid, i, j, n)));
                    break;
                }
            }
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
    loadNewPlayers();
    loadNewGhosts();
}

void LevelManager::initialise() {
    // TODO
}
