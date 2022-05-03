#pragma once

#include <SFML/Graphics.hpp>

class Selector {

protected:

    static unsigned int _next_available_selector_id;
    static unsigned int _current_selector_id;
    unsigned int _my_id;

public:

    Selector();

    virtual void input() = 0;

    virtual void update(float dt_as_seconds) = 0;

    virtual void draw(sf::RenderWindow* window) = 0;

    virtual ~Selector() = default;

};
