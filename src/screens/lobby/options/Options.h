#pragma once

#include <SFML/Graphics.hpp>

class Options {

protected:

    static unsigned int _current_selector;

public:

    virtual void input() = 0;

    virtual void update(float dt_as_seconds) = 0;

    virtual void draw(sf::RenderWindow* window) = 0;

    virtual bool allDone() const = 0;

    virtual ~Options() = default;

};
