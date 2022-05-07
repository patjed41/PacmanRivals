#include "../../src/screens/lobby/options/player/ControlSelector.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"
#include "../../include/game_constants.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <set>

int main() {
    TextureHolder textureHolder;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    std::set<std::string> possibilities = {"WASD", "Arrows", "C1", "C2", "C3", "C4"};

    // Check if players get different controls.
    size_t players = 6;
    ControlSelector control_selectors[players];
    std::set<std::string> received;
    for (int i = 0; i < players; i++) {
        control_selectors[i] = ControlSelector(&window, i);
        received.insert(control_selectors[i].getCurrentControl());
        err::check(possibilities.find(control_selectors[i].getCurrentControl()) != possibilities.end(), "wrong control option");
    }
    err::check(received.size() == players, "some players got same control options");

    ControlSelector::clearState();

    // Check D key.
    ControlSelector control_selector(&window, 0);
    std::vector<std::string> option(6);
    for (int i = 0; i < 6 * 3; i++) {
        if (option[i % 6] == "") {
            option[i % 6] = control_selector.getCurrentControl();
        }
        else {
            err::checkEqual(option[i % 6], control_selector.getCurrentControl(), "D");
        }
        control_selector.input(simulateKeypress(sf::Keyboard::Key::D));
    }

    // Check A key.
    for (int i = 0; i < 6 * 3; i++) {
        control_selector.input(simulateKeypress(sf::Keyboard::Key::A));
        err::checkEqual(option[5 - (i % 6)], control_selector.getCurrentControl(), "A");
    }
}
