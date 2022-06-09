#pragma once

#include <SFML/Audio.hpp>
#include <map>

// Singleton class that stores and plays sounds.
class SoundManager {

private:

    static SoundManager* _instance;

    sf::SoundBuffer _shoot_buffer;
    sf::Sound _shoot_sound;

    int _sounds_volume;
    int _music_volume;

    static void checkIfSingleton();

public:

    SoundManager();

    static int getSoundsVolume();
    static void increaseSoundsVolume();
    static void decreaseSoundsVolume();

    static int getMusicVolume();
    static void increaseMusicVolume();
    static void decreaseMusicVolume();

    static void playShoot();

};
