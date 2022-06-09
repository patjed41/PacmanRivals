#include "TestGhosts.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr map = std::make_shared<Map>();

    TestLinearGhost lin_ghost = TestLinearGhost(map, 1, 1, 1);
    sf::Vector2i lin_position = lin_ghost.test_getUpTile();
    sf::Vector2i lin_expected = {1, 0};

    TestCycleGhost cyc_ghost = TestCycleGhost(map, 3, 3, {1, 3, 0, 2});
    sf::Vector2i cyc_position = cyc_ghost.test_getUpTile();
    sf::Vector2i cyc_expected = {3, 2};

    TestRandomGhost ran_ghost = TestRandomGhost(map, 5, 5, 3);
    sf::Vector2i ran_position = ran_ghost.test_getUpTile();
    sf::Vector2i ran_expected = {5, 4};

    err::checkEqual(lin_position.x, lin_expected.x);
    err::checkEqual(lin_position.y, lin_expected.y);
    err::checkEqual(cyc_position.x, cyc_expected.x);
    err::checkEqual(cyc_position.y, cyc_expected.y);
    err::checkEqual(ran_position.x, ran_expected.x);
    err::checkEqual(ran_position.y, ran_expected.y);

    return 0;
}
