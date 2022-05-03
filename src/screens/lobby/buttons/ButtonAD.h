#pragma once

#include <SFML/Graphics.hpp>

class ButtonAD {

private:

    sf::Text _letter;

    sf::Font _font;

    sf::Sprite _border;

    float _seconds_since_last_click;
    static float _seconds_of_click_animation;

public:

    ButtonAD() = default;

    ButtonAD(sf::Vector2f position, bool isA);

    void click();

    // This method is probably required only for testing.
    bool isClicked();

    void update(float dt_as_seconds);

    void draw(sf::RenderWindow* window);

};
