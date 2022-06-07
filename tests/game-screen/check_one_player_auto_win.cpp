#include "../../src/screens/game/GameScreen.h"
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
    ScreenName current_screen = GAME;
    GameScreen game(&window, &current_screen);

    std::vector<PlayerInfo> players_info = {PlayerInfo("Player", "red", "WASD")};
    game.initialise(players_info, 1);

    game.update(clock.restart().asSeconds());

    err::check(current_screen == GAME_OVER, 1);
    err::check(game.getPlayerInfos().size() == 1, 2);
    err::check(game.getPlayerInfos()[0].getRoundsWon() == 1, 3);
}
