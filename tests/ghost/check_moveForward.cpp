#include "TestGhosts.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr map = std::make_shared<Map>();

    TestLinearGhost lin_ghost = TestLinearGhost(map, 1, 1, 1);
    TestCycleGhost cyc_ghost = TestCycleGhost(map, 2, 2, {1, 3, 0, 2});
    TestRandomGhost ran_ghost = TestRandomGhost(map, 3, 3, 3);

    lin_ghost.test_moveForward(1.f);
    cyc_ghost.test_moveForward(1.f);
    ran_ghost.test_moveForward(1.f);

    err::checkEqual(lin_ghost.getPosition().left, 11.f);
    err::checkEqual(lin_ghost.getPosition().left, 12.f);
    err::checkEqual(lin_ghost.getPosition().top, 13.f);

    return 0;
}
