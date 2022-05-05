#include "../../src/screens/lobby/options/game/PlayersSelector.h"
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

    PlayersSelector playerSelector(&window);

//    sf::Event event;
//
//    while (true) {
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::KeyPressed) {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//                    window.close();
//                    exit(0);
//                }
//
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//                    playerSelector._A.click();
//                }
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//                    playerSelector._D.click();
//                }
//            }
//        }
//
//        float dt_as_seconds = clock.restart().asSeconds();
//        playerSelector.update(dt_as_seconds);
//
//        window.clear(sf::Color::Black);
//        playerSelector.draw();
//        window.display();
//    }

}

