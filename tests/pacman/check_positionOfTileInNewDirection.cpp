#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman1 = TestPacman(shared_map, 5, 5);
    pacman1.turnL();
    sf::Vector2i position1 = pacman1.test_positionOfTileInNewDirection(sf::Vector2i {5, 5});
    sf::Vector2i expected_position1 = {4, 5};

    TestPacman pacman2 = TestPacman(shared_map, 5, 5);
    pacman2.turnR();
    sf::Vector2i position2 = pacman2.test_positionOfTileInNewDirection(sf::Vector2i {5, 5});
    sf::Vector2i expected_position2 = {6, 5};

    TestPacman pacman3 = TestPacman(shared_map, 5, 5);
    pacman3.turnU();
    sf::Vector2i position3 = pacman3.test_positionOfTileInNewDirection(sf::Vector2i {5, 5});
    sf::Vector2i expected_position3 = {5, 4};

    TestPacman pacman4 = TestPacman(shared_map, 5, 5);
    pacman4.turnD();
    sf::Vector2i position4 = pacman4.test_positionOfTileInNewDirection(sf::Vector2i {5, 5});
    sf::Vector2i expected_position4 = {5, 6};

    err::checkEqual(position1.x, expected_position1.x);
    err::checkEqual(position1.y, expected_position1.y);
    err::checkEqual(position2.x, expected_position2.x);
    err::checkEqual(position2.y, expected_position2.y);
    err::checkEqual(position3.x, expected_position3.x);
    err::checkEqual(position3.y, expected_position3.y);
    err::checkEqual(position4.x, expected_position4.x);
    err::checkEqual(position4.y, expected_position4.y);

    return 0;
}