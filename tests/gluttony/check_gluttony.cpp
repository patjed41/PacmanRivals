#include "../../src/characters/player/Pacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../src/power-ups/types/gluttony/Gluttony.h"
#include "../../include/err.h"

#include <memory>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr<Map> map;

    std::vector<std::shared_ptr<Pacman>> pacmans;
    for (int i = 0; i < 3; i++) {
        pacmans.emplace_back(std::make_shared<Pacman>(map, 0, 0));
    }

    Gluttony gluttony;
    gluttony.use(pacmans, 1);
    err::checkEqual(NONE, pacmans[0]->getCurrentPowerUp(), 1);
    err::checkEqual(GLUTTONY, pacmans[1]->getCurrentPowerUp(), 2);
    err::checkEqual(NONE, pacmans[2]->getCurrentPowerUp(), 3);
}
