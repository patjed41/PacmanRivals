#include "TestGhosts.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr map = std::make_shared<Map>();

    TestLinearGhost lin_ghost = TestLinearGhost(map, 1, 1, 2);
    int lin_direction = lin_ghost.test_getOppositeDirection();

    TestCycleGhost cyc_ghost = TestCycleGhost(map, 3, 3, {1, 3, 0, 2});
    int cyc_direction = cyc_ghost.test_getOppositeDirection();

    TestRandomGhost ran_ghost = TestRandomGhost(map, 5, 5, 3);
    int ran_direction = ran_ghost.test_getOppositeDirection();

    err::checkEqual(lin_direction, 3);
    err::checkEqual(cyc_direction, 0);
    err::checkEqual(ran_direction, 2);

    return 0;
}
