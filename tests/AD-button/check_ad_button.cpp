#include "../../src/screens/lobby/buttons/ButtonAD.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;

    sf::Vector2f positionA(100, 100);
    sf::Vector2f positionD(100, 500);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);

    sf::Clock clock;

    /*sf::RenderWindow window(
        sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                      sf::VideoMode::getDesktopMode().height),
        "Pacman Rivals", sf::Style::Fullscreen
    );

    sf::Event event;

    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    buttonA.click();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    buttonD.click();
                }
            }
        }

        float dt_as_seconds = clock.restart().asSeconds();
        buttonA.update(dt_as_seconds);
        buttonD.update(dt_as_seconds);

        window.clear(sf::Color::Black);
        buttonA.draw(&window);
        buttonD.draw(&window);
        window.display();
    }*/

    err::check(!buttonA.isClicked(), 1);
    err::check(!buttonD.isClicked(), 2);

    buttonA.click();
    buttonD.click();

    err::check(buttonA.isClicked(), 3);
    err::check(buttonD.isClicked(), 4);

    clock.restart();
    float last_time = 0;

    while (clock.getElapsedTime().asSeconds() < 0.15f) {
        float current_time = clock.getElapsedTime().asSeconds();
        buttonA.update(current_time - last_time);
        buttonD.update(current_time - last_time);
        last_time = current_time;
        err::check(buttonA.isClicked(), 5);
        err::check(buttonD.isClicked(), 6);
    }

    while (clock.getElapsedTime().asSeconds() < 0.25f) {
        float current_time = clock.getElapsedTime().asSeconds();
        buttonA.update(current_time - last_time);
        buttonD.update(current_time - last_time);
        last_time = current_time;
    }

    err::check(!buttonA.isClicked(), 5);
    err::check(!buttonD.isClicked(), 6);
}

