#include "../../src/screens/lobby/LobbyScreen.h"
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

    ScreenName current_screen = LOBBY;
    LobbyScreen lobby(&window, &current_screen);
    lobby.initialise();
    lobby.input();
    lobby.update(clock.restart().asSeconds());
    err::checkEqual(LOBBY, current_screen);

    // Check default values.
    err::checkEqual(5, (int)lobby.getRounds(), "rounds");
    std::vector<PlayerInfo> player_infos = lobby.getPlayerInfos();
    err::checkEqual(2, (int)player_infos.size(), "players");
    err::checkEqual(std::string("player1"), player_infos[0].getNickname(), "nickname 1");
    err::checkEqual(std::string("player2"), player_infos[1].getNickname(), "nickname 2");
    err::check(player_infos[0].getColor() != player_infos[1].getColor(), "colors");
    err::check(player_infos[0].getControl() != player_infos[1].getControl(), "controls");
}
