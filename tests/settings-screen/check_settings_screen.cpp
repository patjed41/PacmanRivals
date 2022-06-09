#include "../../src/screens/settings/SettingsScreen.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    ScreenName current_screen = SETTINGS;
    SettingsScreen settings(&window, &current_screen);

    settings.initialise();
    settings.input();
    settings.update(clock.restart().asSeconds());
    err::checkEqual(SETTINGS, current_screen);
}
