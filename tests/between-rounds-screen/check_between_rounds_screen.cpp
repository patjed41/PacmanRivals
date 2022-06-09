#include "../../src/screens/between-rounds/BetweenRoundsScreen.h"
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

    ScreenName current_screen = BETWEEN_ROUNDS;
    BetweenRoundsScreen between_rounds(&window, &current_screen);

    std::vector<PlayerInfo> player_infos = {PlayerInfo("player", "red", "C1")};
    between_rounds.initialise(player_infos);
    between_rounds.input();
    between_rounds.update(clock.restart().asSeconds());
    err::checkEqual(BETWEEN_ROUNDS, current_screen);
}
