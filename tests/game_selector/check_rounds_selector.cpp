#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"
#include "../../src/screens/lobby/options/game/RoundsSelector.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;

    sf::Clock clock;

    sf::RenderWindow window(
            sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                          sf::VideoMode::getDesktopMode().height),
            "Pacman Rivals", sf::Style::Fullscreen
    );

    RoundsSelector roundsSelector(&window);

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
//                    roundsSelector._A.click();
//                }
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//                    roundsSelector._D.click();
//                }
//            }
//        }
//
//        float dt_as_seconds = clock.restart().asSeconds();
//        roundsSelector.input();
//        roundsSelector.update(dt_as_seconds);
//
//        window.clear(sf::Color::Black);
//        roundsSelector.draw();
//        window.display();
//    }



}

