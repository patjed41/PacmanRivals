#include "../../src/characters/player/Pacman.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    // Check user.
    unsigned int user = 10;
    Spike spike(sf::Vector2f(0, 0), user);
    err::checkEqual(user, spike.getUser(), "check user");
}

