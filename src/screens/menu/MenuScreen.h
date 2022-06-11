#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"
#include "../../characters/menu-character/MenuCharacter.h"

class MenuScreen : Screen {

private:

    sf::View _view;

    sf::Font _font;

    static const unsigned int OPTIONS_NUM;
    static const float SPACE_BETWEEN; // vertical distance between 2 options
    std::vector<sf::Text> _options;
    unsigned int _current_option;
    std::vector<std::shared_ptr<MenuCharacter>> _menu_characters;
    int _number_of_characters = 10;

public:

    MenuScreen() = default;

    MenuScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
