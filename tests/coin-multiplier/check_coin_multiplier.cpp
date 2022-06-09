#include "../../src/map/Map.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../pacman/TestPacman.h"
#include "../../src/power-ups/types/coin-multiplier/CoinMultiplier.h"


int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    std::shared_ptr<Map> map;

    std::vector<std::shared_ptr<Pacman>> pacmans;
    for (int i = 0; i < 3; i++) {
        pacmans.emplace_back(std::make_shared<Pacman>(map, i, i));
    }

    CoinMultiplier coinMultiplier;
    coinMultiplier.use(pacmans, 0);

    err::checkEqual(COIN_MULTIPLIER, pacmans[0]->getCurrentPowerUp(), 1);
    err::checkEqual(NONE, pacmans[1]->getCurrentPowerUp(),2);
    err::checkEqual(NONE, pacmans[2]->getCurrentPowerUp(), 3);
    return 0;
}
