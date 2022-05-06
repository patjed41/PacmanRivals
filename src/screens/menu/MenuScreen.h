#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"

class MenuScreen : Screen {

private:

    sf::View _view;

    sf::Font _font;

    static const unsigned int OPTIONS_NUM;
    static const float SPACE_BETWEEN; // vertical distance between 2 options
    std::vector<sf::Text> _options;
    unsigned int _current_option;

public:

    MenuScreen() = default;

    MenuScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
