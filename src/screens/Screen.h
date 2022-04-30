#pragma once

#include <SFML/Graphics.hpp>

#include "ScreenName.h"

class Screen {

protected:

    sf::RenderWindow* _window;

    ScreenName* _current_screen;

public:

    Screen() = default;

    Screen(sf::RenderWindow* window, ScreenName* current_screen) :
        _window(window), _current_screen(current_screen) {}

    virtual void initialise() = 0;

    virtual void input() = 0;

    virtual void update(float dt_as_seconds) = 0;

    virtual void draw() = 0;

    virtual ~Screen() = default;

};
