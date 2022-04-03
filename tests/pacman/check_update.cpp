#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    std::shared_ptr shared_map = std::make_shared<Map>();

//    początkowy kierunek STOP i chcemy w lewo
    TestPacman pacman1 = TestPacman(shared_map, 5, 5);
    pacman1.turnR();
    pacman1.test_update(1.f);
    sf::Vector2f expected_position1 = {5 + 10 , 5};

    err::checkEqual(expected_position1.x, pacman1.getPosition().left);
    err::checkEqual(expected_position1.y, pacman1.getPosition().top);

//  zawracanie
    TestPacman pacman2 = TestPacman(shared_map, 5, 5);
    pacman2.dirR();
    pacman2.turnL();
    pacman2.update(1.f);
    sf::Vector2f expected_position2 = {5, 5};

    err::checkEqual(expected_position2.x, pacman2.getPosition().left);
    err::checkEqual(expected_position2.y, pacman2.getPosition().top);

//    osiągnięto nowe pole i skręcamy
    TestPacman pacman3 = TestPacman(shared_map, 50, 50);
    pacman3.dirL();
    pacman3.turnD();
    pacman3.update(1.f);
    sf::Vector2f expected_position3 = {50, 60};

    err::checkEqual(expected_position3.x, pacman3.getPosition().left);
    err::checkEqual(expected_position3.y, pacman3.getPosition().top);

//    osiągnięto nowe pole i idziemy nadal w tym samym kierunku
    TestPacman pacman4 = TestPacman(shared_map, 50, 90);
    pacman4.dirD();
    pacman4.turnD();
    pacman4.update(1.f);
    sf::Vector2f expected_position4 = {50, 100};

    err::checkEqual(expected_position4.x, pacman4.getPosition().left);
    err::checkEqual(expected_position4.y, pacman4.getPosition().top);

    return 0;
}