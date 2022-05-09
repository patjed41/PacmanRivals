#include "../../src/screens/lobby/options/player/PlayerOptions.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../include/simulate_keypress.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;

    sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    sf::Clock clock;

    PlayerOptions player_options(1, &window);

    // Check default nickname.
    err::checkEqual(std::string("player1"), player_options.getPlayerInfo().getNickname(), "default nickname");

    // Check right arrow click.
    player_options.input(simulateKeypress(sf::Keyboard::Key::X));
    err::checkEqual(std::string("X"), player_options.getPlayerInfo().getNickname(), "right arrow 1");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Right));
    std::string color_before = player_options.getPlayerInfo().getColor();
    player_options.input(simulateKeypress(sf::Keyboard::Key::D));
    std::string color_after = player_options.getPlayerInfo().getColor();
    err::check(color_before != color_after, "right arrow 2");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Right));
    std::string control_before = player_options.getPlayerInfo().getControl();
    player_options.input(simulateKeypress(sf::Keyboard::Key::D));
    std::string control_after = player_options.getPlayerInfo().getControl();
    err::check(control_before != control_after, "right arrow 3");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Right));
    player_options.input(simulateKeypress(sf::Keyboard::Key::X));
    err::checkEqual(std::string("XX"), player_options.getPlayerInfo().getNickname(), "right arrow 4");

    // Check left arrow click.
    player_options.input(simulateKeypress(sf::Keyboard::Key::X));
    err::checkEqual(std::string("XXX"), player_options.getPlayerInfo().getNickname(), "left arrow 1");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Left));
    control_before = player_options.getPlayerInfo().getControl();
    player_options.input(simulateKeypress(sf::Keyboard::Key::D));
    control_after = player_options.getPlayerInfo().getControl();
    err::check(control_before != control_after, "left arrow 2");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Left));
    color_before = player_options.getPlayerInfo().getColor();
    player_options.input(simulateKeypress(sf::Keyboard::Key::D));
    color_after = player_options.getPlayerInfo().getColor();
    err::check(color_before != color_after, "left arrow 3");
    player_options.update(clock.restart().asSeconds());
    player_options.input(simulateKeypress(sf::Keyboard::Key::Left));
    player_options.input(simulateKeypress(sf::Keyboard::Key::X));
    err::checkEqual(std::string("XXXX"), player_options.getPlayerInfo().getNickname(), "left arrow 4");
}
