#include "../../src/screens/lobby/options/game/PlayersSelector.h"
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

    PlayersSelector players_selector(&window);

    // Check default value.
    err::checkEqual((int)players_selector.getCurrentPlayers(), 2, 1);

    // Check D click
    players_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(3, (int)players_selector.getCurrentPlayers(), 2);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)players_selector.getCurrentPlayers(), 3);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)players_selector.getCurrentPlayers(), 4);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)players_selector.getCurrentPlayers(), 5);

    // Check A click
    players_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(3, (int)players_selector.getCurrentPlayers(), 6);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)players_selector.getCurrentPlayers(), 7);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)players_selector.getCurrentPlayers(), 8);
    players_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)players_selector.getCurrentPlayers(), 9);
}
