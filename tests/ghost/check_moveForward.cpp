#include "TestGhosts.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr map = std::make_shared<Map>();

    TestLinearGhost lin_ghost = TestLinearGhost(map, 1, 1, 1);
    TestCycleGhost cyc_ghost = TestCycleGhost(map, 2, 2, {1, 3, 0, 2});
    TestRandomGhost ran_ghost = TestRandomGhost(map, 3, 3, 3);

    lin_ghost.test_moveForward(1.f);
    cyc_ghost.test_moveForward(1.f);
    ran_ghost.test_moveForward(1.f);

    err::checkEqualFloat(lin_ghost.getPosition().left, 60.f);
    err::checkEqualFloat(cyc_ghost.getPosition().left, 110.f);
    err::checkEqualFloat(ran_ghost.getPosition().top, 160.f);

    return 0;
}
