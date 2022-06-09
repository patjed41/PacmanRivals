#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    // direction at the beginning - STOP, we want to turn RIGHT
    TestPacman pacman1 = TestPacman(shared_map, 5, 5);
    pacman1.turnR();
    pacman1.test_update(1.f);
    sf::Vector2f expected_position1 = {5 + 10 , 5};

    err::checkEqualFloat(expected_position1.x, pacman1.getPosition().left);
    err::checkEqualFloat(expected_position1.y, pacman1.getPosition().top);

    // turing back
    TestPacman pacman2 = TestPacman(shared_map, 5, 5);
    pacman2.dirR();
    pacman2.turnL();
    pacman2.update(1.f);
    sf::Vector2f expected_position2 = {5, 5};

    err::checkEqual(expected_position2.x, pacman2.getPosition().left);
    err::checkEqual(expected_position2.y, pacman2.getPosition().top);

    // new tile reached and we want to turn 90 degrees
    TestPacman pacman3 = TestPacman(shared_map, 50, 50);
    pacman3.dirL();
    pacman3.turnD();
    pacman3.update(1.f);
    sf::Vector2f expected_position3 = {50, 60};

    err::checkEqualFloat(expected_position3.x, pacman3.getPosition().left);
    err::checkEqualFloat(expected_position3.y, pacman3.getPosition().top);

    // new tile reached, we want to move in the same direction
    TestPacman pacman4 = TestPacman(shared_map, 50, 90);
    pacman4.dirD();
    pacman4.turnD();
    pacman4.update(1.f);
    sf::Vector2f expected_position4 = {50, 100};

    err::checkEqualFloat(expected_position4.x, pacman4.getPosition().left);
    err::checkEqualFloat(expected_position4.y, pacman4.getPosition().top);

    return 0;
}