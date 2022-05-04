#pragma once

#include <SFML/Graphics.hpp>

class Options {

protected:

    sf::RenderWindow* _window;

    static unsigned int _current_selector;

public:

    Options() = default;

    Options(sf::RenderWindow* window) : _window(window) {}

    virtual void input() = 0;

    virtual void update(float dt_as_seconds) = 0;

    virtual void draw() = 0;

    virtual bool allDone() const = 0;

    virtual ~Options() = default;

};
