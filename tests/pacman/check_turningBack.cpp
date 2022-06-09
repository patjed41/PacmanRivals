#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "TestPacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr shared_map = std::make_shared<Map>();

    TestPacman pacman1 = TestPacman(shared_map, 0, 0);
    pacman1.dirD();
    pacman1.turnU();

    TestPacman pacman2 = TestPacman(shared_map, 0, 0);
    pacman2.dirL();
    pacman2.turnR();

    TestPacman pacman3 = TestPacman(shared_map, 0, 0);
    pacman3.dirL();
    pacman3.turnU();

    TestPacman pacman4 = TestPacman(shared_map, 0, 0);
    pacman4.dirU();
    pacman4.turnU();

    err::checkEqual(pacman1.test_turningBack(), true);
    err::checkEqual(pacman2.test_turningBack(), true);
    err::checkEqual(pacman3.test_turningBack(), false);
    err::checkEqual(pacman4.test_turningBack(), false);

    return 0;
}