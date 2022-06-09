#include "../../src/level-manager/LevelManager.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

#include <set>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    LevelManager manager = LevelManager();

    std::set<int> loaded_levels;
    for (int i = 0; i < 10; i++) {
        manager.loadNewLevel();
        loaded_levels.emplace(manager.getLoadedLevel());
    }

    err::checkEqual(10, (int) loaded_levels.size());
}
