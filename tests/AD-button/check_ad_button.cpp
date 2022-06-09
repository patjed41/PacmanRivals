#include "../../src/screens/lobby/buttons/ButtonAD.h"
#include "../../src/texture-holder/TextureHolder.h"
#include "../../src/sound-manager/SoundManager.h"
#include "../../include/err.h"

int main() {
    TextureHolder textureHolder;
    SoundManager soundManager;

    sf::Vector2f positionA(100, 100);
    sf::Vector2f positionD(100, 500);

    ButtonAD buttonA(positionA, true);
    ButtonAD buttonD(positionD, false);

    sf::Clock clock;

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

