#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    pacman.turnU();

    int direction = pacman.test_new_direction();

    err::checkEqual(direction, 2);

    return 0;
}