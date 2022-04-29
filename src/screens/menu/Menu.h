#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"

class Menu {

private:

    sf::View _view;

    sf::RenderWindow* _window;

    Screen* _current_screen;

    static const unsigned int OPTIONS_NUM;
    static const float SPACE_BETWEEN; // vertical distance between 2 options
    std::vector<sf::Text> _options;

    sf::Font _font;

public:

    Menu() = default;

    Menu(sf::RenderWindow* window, Screen* current_screen);

    void input();

    void update(float dt_as_seconds);

    void draw();

};
