#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    LevelManager manager = LevelManager();

    manager.loadNewLevel();
    std::vector<std::shared_ptr<Pacman>> players;
    while (manager.getLoadedLevel() != 1) {
        manager.loadNewLevel();
        players = manager.getPlayers();
    }

    std::ifstream file;
    file.open("../assets/maps/players/players1.txt");

    if (file.is_open()) {
        for (int i = 0; i < 4; i++) {
            int x, y;
            file >> x >> y;

            err::checkEqualFloat(x * TILE_SIZE, players[i]->getPosition().left);
            err::checkEqualFloat(y * TILE_SIZE, players[i]->getPosition().top);
        }

        file.close();
    } else {
        std::cerr << "Can't find input file" << std::endl;
        exit(1);
    }

    return 0;
}