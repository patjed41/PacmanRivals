#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../pacman/TestPacman.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    pacman.testPowerUp(SPEED_UP);

    err::checkEqualFloat(pacman.getSpeed(), 200.f);

    return 0;
}