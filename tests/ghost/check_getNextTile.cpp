#include "TestGhosts.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr map = std::make_shared<Map>();

    TestLinearGhost lin_ghost = TestLinearGhost(map, 1, 1, 2);
    sf::Vector2i lin_next_tile = lin_ghost.test_getNextTile(sf::Vector2i{1, 1});
    sf::Vector2i lin_expected = {1, 0};

    TestCycleGhost cyc_ghost = TestCycleGhost(map, 3, 3, {1, 3, 0, 2});
    sf::Vector2i cyc_next_tile = cyc_ghost.test_getNextTile(sf::Vector2i{3, 3});
    sf::Vector2i cyc_expected = {4, 3};

    TestRandomGhost ran_ghost = TestRandomGhost(map, 5, 5, 3);
    sf::Vector2i ran_next_tile = ran_ghost.test_getNextTile(sf::Vector2i{5, 5});
    sf::Vector2i ran_expected = {5, 6};

    err::checkEqual(lin_next_tile.x, lin_expected.x);
    err::checkEqual(lin_next_tile.y, lin_expected.y);
    err::checkEqual(cyc_next_tile.x, cyc_expected.x);
    err::checkEqual(cyc_next_tile.y, cyc_expected.y);
    err::checkEqual(ran_next_tile.x, ran_expected.x);
    err::checkEqual(ran_next_tile.y, ran_expected.y);

    return 0;
}
