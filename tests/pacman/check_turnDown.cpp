#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman = TestPacman(shared_map, 0, 0);
    pacman.turnD();

    int direction = pacman.test_new_direction();

    err::checkEqual(direction, 3);

    return 0;
}