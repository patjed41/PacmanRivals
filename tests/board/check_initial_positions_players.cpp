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

    std::vector<float> x = {2, 28, 28, 2};
    std::vector<float> y = {1, 16, 1, 18};

    for (int i = 0; i < 4; i++) {
        err::checkEqualFloat(x[i] * TILE_SIZE, players[i]->getPosition().left);
        err::checkEqualFloat(y[i] * TILE_SIZE, players[i]->getPosition().top);
    }

    return 0;
}