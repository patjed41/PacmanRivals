#include "SoundManager.h"

#include <iostream>

SoundManager* SoundManager::_instance = nullptr;

SoundManager::SoundManager() {
    if (_instance != nullptr) {
        std::cerr << "Object of SoundManager already created but it is a singleton class\n";
        exit(1);
    }
    _instance = this;

    _sounds_volume = 50;
    _music_volume = 50;

    if (!_menu_music.openFromFile("../assets/sounds/menu-music.ogg")) {
        std::cerr << "Failed to load menu-music.ogg\n";
    }

    if (!_death_buffer.loadFromFile("../assets/sounds/death.ogg")) {
        std::cerr << "Failed to load death.ogg\n";
    }
    _death_sound.setBuffer(_death_buffer);

    if (!_winner_buffer.loadFromFile("../assets/sounds/winner.ogg")) {
        std::cerr << "Failed to load winner.ogg\n";
    }
    _winner_sound.setBuffer(_winner_buffer);

    if (!_pickup_buffer.loadFromFile("../assets/sounds/pick.ogg")) {
        std::cerr << "Failed to load pick.ogg\n";
    }
    _pickup_sound.setBuffer(_pickup_buffer);

    if (!_shoot_buffer.loadFromFile("../assets/sounds/shoot.ogg")) {
        std::cerr << "Failed to load shoot.ogg\n";
    }
    _shoot_sound.setBuffer(_shoot_buffer);

    if (!_bomb_buffer.loadFromFile("../assets/sounds/bomb.ogg")) {
        std::cerr << "Failed to load bomb.ogg\n";
    }
    _bomb_sound.setBuffer(_bomb_buffer);

    if (!_spikes_buffer.loadFromFile("../assets/sounds/spikes.ogg")) {
        std::cerr << "Failed to load spikes.ogg\n";
    }
    _spikes_sound.setBuffer(_spikes_buffer);

    if (!_chomp_buffer.loadFromFile("../assets/sounds/chomp.ogg")) {
        std::cerr << "Failed to load chomp.ogg\n";
    }
    _chomp_sound.setBuffer(_chomp_buffer);
    _chomp_sound.setLoop(true);
}

void SoundManager::checkIfSingleton() {
    if (_instance == nullptr) {
        std::cerr << "SoundManager instance not created\n";
        exit(1);
    }
}

int SoundManager::getSoundsVolume() {
    checkIfSingleton();
    return _instance->_sounds_volume / 10;
}

void SoundManager::increaseSoundsVolume() {
    checkIfSingleton();
    if (_instance->_sounds_volume < 100) {
        _instance->_sounds_volume += 10;
    }
}

void SoundManager::decreaseSoundsVolume() {
    checkIfSingleton();
    if (_instance->_sounds_volume > 0) {
        _instance->_sounds_volume -= 10;
    }
}

int SoundManager::getMusicVolume() {
    checkIfSingleton();
    return _instance->_music_volume / 10;
}

void SoundManager::increaseMusicVolume() {
    checkIfSingleton();
    if (_instance->_music_volume < 100) {
        _instance->_music_volume += 10;
    }
    _instance->_menu_music.setVolume((float)_instance->_music_volume);
}

void SoundManager::decreaseMusicVolume() {
    checkIfSingleton();
    if (_instance->_music_volume > 0) {
        _instance->_music_volume -= 10;
    }
    _instance->_menu_music.setVolume((float)_instance->_music_volume);
}

void SoundManager::playMusic() {
    checkIfSingleton();
    _instance->_menu_music.setLoop(true);
    _instance->_menu_music.play();
}

void SoundManager::stopMusic() {
    checkIfSingleton();
    _instance->_menu_music.stop();
}

void SoundManager::playDeath() {
    checkIfSingleton();
    _instance->_death_sound.setVolume(_instance->_sounds_volume - 8);
    _instance->_death_sound.play();
}

void SoundManager::playWinner() {
    checkIfSingleton();
    _instance->_winner_sound.setVolume(_instance->_sounds_volume);
    _instance->_winner_sound.play();
}

void SoundManager::playPickup() {
    checkIfSingleton();
    _instance->_pickup_sound.setVolume(_instance->_sounds_volume);
    _instance->_pickup_sound.play();
}

void SoundManager::playShoot() {
    checkIfSingleton();
    _instance->_shoot_sound.setVolume(_instance->_sounds_volume);
    _instance->_shoot_sound.play();
}

void SoundManager::playBomb() {
    checkIfSingleton();
    _instance->_bomb_sound.setVolume(_instance->_sounds_volume);
    _instance->_bomb_sound.play();
}

void SoundManager::playSpikes() {
    checkIfSingleton();
    _instance->_spikes_sound.setVolume(_instance->_sounds_volume);
    _instance->_spikes_sound.play();
}

void SoundManager::playChomp() {
    checkIfSingleton();
    _instance->_chomp_sound.setVolume(_instance->_sounds_volume / 4);
    _instance->_chomp_sound.play();
}

void SoundManager::stopChomp() {
    checkIfSingleton();
    _instance->_chomp_sound.stop();
}
