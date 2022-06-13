#include "../../src/screens/game-over/GameOverScreen.h"
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

    ScreenName current_screen = GAME_OVER;
    GameOverScreen game_over(&window, &current_screen);

    game_over.input();
    game_over.update(clock.restart().asSeconds());
    err::checkEqual(GAME_OVER, current_screen);
}
