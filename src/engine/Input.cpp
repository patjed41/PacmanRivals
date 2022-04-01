#include "GameEngine.h"

void GameEngine::input() {
    sf::Event event;

    std::vector<std::shared_ptr<Player>> players = _level_manager.getPlayers();
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // pause
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                (*players[0].get()).turnLeft();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                (*players[0].get()).turnRight();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                (*players[0].get()).turnUp();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                (*players[0].get()).turnDown();
            }
        }
    }

    // handle player input

//    while (_window.pollEvent(event)) {
//        if(event.type == sf::Event::KeyPressed) {
//
//        }
//    }
}
