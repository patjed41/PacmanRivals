#include "../../src/coins/Coin.h"
#include "../../include/err.h"
#include "../../src/texture-holder/TextureHolder.h"

int main() {
    TextureHolder textureHolder;

    Coin coin = Coin(0.f, 0.f);

    err::checkEqual(coin.isTaken(), false);

    coin.Take();

    err::checkEqual(coin.isTaken(), true);

    err::checkEqual(coin.getSprite().getPosition().x, 0.f);
    err::checkEqual(coin.getSprite().getPosition().y, 0.f);

    return 0;
}