#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/slow_down/SlowDown.h"
#include "TestSlowDown.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman1 = TestPacman(shared_map, 0, 0);
    TestPacman pacman2 = TestPacman(shared_map, 0, 0);
    std::vector<std::shared_ptr<TestPacman>> pacmans = {std::make_shared<TestPacman>(pacman1), std::make_shared<TestPacman>(pacman2)};

    TestSlowDown slow;
    slow.testUse(pacmans, 0);

    err::checkEqualFloat(50.f, pacmans[1].get()->getSpeed());

    return 0;
}
