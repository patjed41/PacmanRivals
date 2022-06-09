#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/shield/Shield.h"
#include "TestShield.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    std::vector<std::shared_ptr<TestPacman>> pacmans = {std::make_shared<TestPacman>(pacman),
            std::make_shared<TestPacman>(pacman)};

    TestShield shield;
    shield.testUse(pacmans, 0);

    err::checkEqualFloat(pacmans[0].get()->getShield(), true);
    err::checkEqual(SHIELD, pacmans[0]->getCurrentPowerUp());
    err::checkEqual(NONE, pacmans[1]->getCurrentPowerUp());
    return 0;
}
