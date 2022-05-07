#include "../../src/screens/lobby/options/game/RoundsSelector.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"
#include "../../include/game_constants.h"

#include <SFML/Graphics.hpp>
#include <algorithm>

int main() {
    TextureHolder textureHolder;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    RoundsSelector rounds_selector(&window);

    // Check default value.
    err::checkEqual(5, (int)rounds_selector.getCurrentRounds(), 1);

    // Check D click
    for (int i = 1; i <= MAX_ROUNDS; i++) {
        rounds_selector.input(simulateKeypress(sf::Keyboard::Key::D));
        err::checkEqual(std::min(MAX_ROUNDS, i + 5), (int)rounds_selector.getCurrentRounds(), i + 1);
    }

    // Check A click
    for (int i = 1; i <= 2 * MAX_ROUNDS; i++) {
        rounds_selector.input(simulateKeypress(sf::Keyboard::Key::A));
        err::checkEqual(std::max(MIN_ROUNDS, MAX_ROUNDS - i), (int)rounds_selector.getCurrentRounds(), i + MAX_ROUNDS + 1);
    }
}
