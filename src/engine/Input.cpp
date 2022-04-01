#include "GameEngine.h"

void GameEngine::input() {
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // pause
            }
        }
    }

    // handle player input

    while (_window.pollEvent(event)) {
        if(event.type == sf::Event::KeyPressed) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

            }
        }
    }
}
