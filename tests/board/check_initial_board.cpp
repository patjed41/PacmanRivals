#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    LevelManager manager = LevelManager();

    manager.loadNewLevel();
    auto grid = manager.getGrid();

    std::ifstream myfile;
    myfile.open("../assets/maps/grids/grid1.txt");

    if (myfile.is_open()) {
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                int tmp;
                myfile >> tmp;

                bool expected = false;
                if (tmp == 1)
                    expected = true;

                err::checkEqual(grid->getTiles()[i][j].isWall(), expected);

            }
        }
        myfile.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }

    return 0;
}