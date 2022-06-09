#include "../../src/screens/lobby/options/game/GameOptions.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    sf::Clock clock;

    GameOptions game_options(&window);

    // Check default values.
    err::checkEqual(2, (int)game_options.getNumberOfPlayers(), "default players");
    err::checkEqual(5, (int)game_options.getNumberOfRounds(), "default rounds");

    // Check right arrow click.
    game_options.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(3, (int)game_options.getNumberOfPlayers(), "right arrow 1");
    game_options.update(clock.restart().asSeconds());
    game_options.input(simulateKeypress(sf::Keyboard::Key::Right));
    game_options.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(6, (int)game_options.getNumberOfRounds(), "right arrow 2");
    game_options.update(clock.restart().asSeconds());
    game_options.input(simulateKeypress(sf::Keyboard::Key::Right));
    game_options.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)game_options.getNumberOfPlayers(), "right arrow 3");

    // Check left arrow click.
    game_options.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(3, (int)game_options.getNumberOfPlayers(), "left arrow 1");
    game_options.update(clock.restart().asSeconds());
    game_options.input(simulateKeypress(sf::Keyboard::Key::Left));
    game_options.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(5, (int)game_options.getNumberOfRounds(), "left arrow 2");
    game_options.update(clock.restart().asSeconds());
    game_options.input(simulateKeypress(sf::Keyboard::Key::Left));
    game_options.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)game_options.getNumberOfPlayers(), "left arrow 3");
}
