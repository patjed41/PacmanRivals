#pragma once

#include "SFML/Graphics.hpp"

#include "../Screen.h"

class ControlsScreen : Screen {

private:

    sf::View _view;

    sf::Font _font;

    sf::Text _header;
    std::vector<std::vector<sf::Text>> _table;

    static const unsigned int COLUMNS;
    static const unsigned int ROWS;
    static const float HEADER_Y;
    static const float SPACE_BETWEEN;
    static const float POSITION_OFFSET;

public:

    ControlsScreen() = default;

    ControlsScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;
};
