#include "../../src/screens/lobby/buttons/ButtonAD.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../include/err.h"

#include <SFML/Graphics.hpp>

int main() {
    TextureHolder textureHolder;

    sf::Vector2f position(200, 300);

    ButtonAD buttonA(position, true);
    ButtonAD buttonD(position, true);

    err::check(!buttonA.isClicked(), 1);
    err::check(!buttonD.isClicked(), 2);

    buttonA.click();
    buttonD.click();

    err::check(buttonA.isClicked(), 3);
    err::check(buttonD.isClicked(), 4);

    sf::Clock clock;
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

