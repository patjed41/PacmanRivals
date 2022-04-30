#pragma once

#include <SFML/Graphics.hpp>

class Options {

public:

    virtual void input() = 0;

    virtual void draw(sf::RenderWindow& window) = 0;

    virtual bool allDone() const = 0;

    virtual ~Options() = default;

};
