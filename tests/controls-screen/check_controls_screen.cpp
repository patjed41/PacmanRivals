#include "../../src/screens/controls/ControlsScreen.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;

    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    ScreenName current_screen = CONTROLS;
    ControlsScreen controls_screen(&window, &current_screen);
    controls_screen.initialise();
    controls_screen.input();
    controls_screen.update(clock.restart().asSeconds());
    err::checkEqual(CONTROLS, current_screen);
}
