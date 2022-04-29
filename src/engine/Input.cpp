#include "GameEngine.h"

void GameEngine::inputMenu() {
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                _current_screen = GAME;
            }
        }
    }
}

void GameEngine::inputGame() {
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // pause
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                _pacmans[0].get()->turnLeft();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                _pacmans[0].get()->turnRight();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                _pacmans[0].get()->turnUp();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                _pacmans[0].get()->turnDown();
            }
        }
    }

}

void GameEngine::input() {
    switch (_current_screen) {
        case MENU:
            inputMenu();
            return;
        case GAME:
            inputGame();
            return;
        default:
            return;
    }
}

