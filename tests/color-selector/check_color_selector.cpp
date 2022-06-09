#include "../../src/screens/lobby/options/player/ColorSelector.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <set>

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    std::set<std::string> possibilities = {"lightblue", "darkblue", "lightgreen",
                                           "darkgreen", "orange", "pink",
                                           "purple", "red", "yellow", "black"};

    // Check if players get different controls.
    size_t players = 10;
    ColorSelector color_selectors[players];
    std::set<std::string> received;
    for (int i = 0; i < players; i++) {
        color_selectors[i] = ColorSelector(&window, i);
        received.insert(color_selectors[i].getCurrentColor());
        err::check(possibilities.find(color_selectors[i].getCurrentColor()) != possibilities.end(), "wrong color option");
    }
    err::check(received.size() == players, "some players got same color options");

    ColorSelector::clearState();

    // Check D key.
    ColorSelector color_selector(&window, 0);
    std::vector<std::string> option(10);
    for (int i = 0; i < 10 * 3; i++) {
        if (option[i % 10].empty()) {
            option[i % 10] = color_selector.getCurrentColor();
        }
        else {
            err::checkEqual(option[i % 10], color_selector.getCurrentColor(), "D");
        }
        color_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    }

    // Check A key.
    for (int i = 0; i < 10 * 3; i++) {
        color_selector.input(simulateKeypress(sf::Keyboard::Key::A));
        err::checkEqual(option[9 - (i % 10)], color_selector.getCurrentColor(), "A");
    }
}
