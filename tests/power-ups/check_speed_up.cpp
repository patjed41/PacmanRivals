#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/speed_up/SpeedUp.h"
#include "TestSpeedUp.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    std::vector<std::shared_ptr<TestPacman>> pacmans = {std::make_shared<TestPacman>(pacman)};

    TestSpeedUp speed;
    speed.testUse(pacmans, 0);

    err::checkEqualFloat(pacmans[0].get()->getSpeed(), 200.f);

    return 0;
}