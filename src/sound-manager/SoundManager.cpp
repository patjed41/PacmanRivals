#include "SoundManager.h"

#include <iostream>

SoundManager* SoundManager::_instance = nullptr;

SoundManager::SoundManager() {
    if (_instance != nullptr) {
        std::cerr << "Object of SoundManager already created but it is a singleton class\n";
        exit(1);
    }
    _instance = this;

    _sounds_volume = 100;
    _music_volume = 100;

    if (!_shoot_buffer.loadFromFile("../assets/sounds/shoot.ogg")) {
        std::cerr << "Failed to load shoot.ogg\n";
    }
    _shoot_sound.setBuffer(_shoot_buffer);
}

void SoundManager::increaseSoundsVolume() {
    if (_instance->_sounds_volume < 100) {
        _instance->_sounds_volume += 10;
    }
}

void SoundManager::decreaseSoundsVolume() {
    if (_instance->_sounds_volume > 0) {
        _instance->_sounds_volume -= 10;
    }
}

void SoundManager::increaseMusicVolume() {
    if (_instance->_music_volume < 100) {
        _instance->_music_volume += 10;
    }
}

void SoundManager::decreaseMusicVolume() {
    if (_instance->_music_volume > 0) {
        _instance->_music_volume -= 10;
    }
}

void SoundManager::playShoot() {
    _instance->_shoot_sound.setVolume(_instance->_sounds_volume);
    _instance->_shoot_sound.play();
}
