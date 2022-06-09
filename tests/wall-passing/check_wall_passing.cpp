#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../pacman/TestPacman.h"
#include "TestPassWall.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    std::vector<std::shared_ptr<TestPacman>> pacmans = {std::make_shared<TestPacman>(pacman)};

    TestPassWall passWall;
    passWall.testUse(pacmans, 0);

    err::checkEqualFloat(true, pacmans[0].get()->getPassWall());

    return 0;
}
