#include "../../src/characters/player/Pacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

#include <memory>

int main() {
    TextureHolder textureHolder;

    // Check user.
    unsigned int user = 10;
    Spike spike(sf::Vector2f(0, 0), user);
    err::checkEqual(user, spike.getUser(), "check user");
}

