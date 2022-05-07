#include "../../src/screens/lobby/options/game/PlayersSelector.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    TextureHolder textureHolder;

    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    PlayersSelector player_selector(&window);

    // Check default value.
    err::checkEqual((int)player_selector.getCurrentPlayers(), 2, 1);

    // Check D click
    player_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(3, (int)player_selector.getCurrentPlayers(), 2);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)player_selector.getCurrentPlayers(), 3);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)player_selector.getCurrentPlayers(), 4);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    err::checkEqual(4, (int)player_selector.getCurrentPlayers(), 5);

    // Check A click
    player_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(3, (int)player_selector.getCurrentPlayers(), 6);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)player_selector.getCurrentPlayers(), 7);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)player_selector.getCurrentPlayers(), 8);
    player_selector.input(simulateKeypress(sf::Keyboard::Key::A));
    err::checkEqual(2, (int)player_selector.getCurrentPlayers(), 9);
}
