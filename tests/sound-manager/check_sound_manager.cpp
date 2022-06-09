#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

int main() {
    SoundManager sound_manager;

    err::checkEqual(5, SoundManager::getSoundsVolume(), "base sounds volume");
    err::checkEqual(5, SoundManager::getMusicVolume(), "base music volume");

    for (int i = 6; i < 15; i++) {
        SoundManager::increaseSoundsVolume();
        SoundManager::increaseMusicVolume();
        err::checkEqual(std::min(i, 10), SoundManager::getSoundsVolume(), "sounds increase");
        err::checkEqual(std::min(i, 10), SoundManager::getMusicVolume(), "music increase");
    }

    for (int i = 9; i > -5; i--) {
        SoundManager::decreaseSoundsVolume();
        SoundManager::decreaseMusicVolume();
        err::checkEqual(std::max(i, 0), SoundManager::getSoundsVolume(), "sounds decrease");
        err::checkEqual(std::max(i, 0), SoundManager::getMusicVolume(), "music decrease");
    }
}
