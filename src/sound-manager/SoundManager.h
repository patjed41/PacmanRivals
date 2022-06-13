#pragma once

#include <SFML/Audio.hpp>
#include <map>

// Singleton class that stores and plays sounds.
class SoundManager {

private:

    static SoundManager* _instance;

    sf::Music _menu_music;

    sf::SoundBuffer _death_buffer;
    sf::Sound _death_sound;

    sf::SoundBuffer _winner_buffer;
    sf::Sound _winner_sound;

    sf::SoundBuffer _pickup_buffer;
    sf::Sound _pickup_sound;

    sf::SoundBuffer _shoot_buffer;
    sf::Sound _shoot_sound;

    sf::SoundBuffer _bomb_buffer;
    sf::Sound _bomb_sound;

    sf::SoundBuffer _spikes_buffer;
    sf::Sound _spikes_sound;

    sf::SoundBuffer _chomp_buffer;
    sf::Sound _chomp_sound;

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

    static void playMusic();
    static void stopMusic();
    static void playDeath();
    static void playWinner();
    static void playPickup();
    static void playShoot();
    static void playBomb();
    static void playSpikes();
    static void playChomp();
    static void stopChomp();
};
