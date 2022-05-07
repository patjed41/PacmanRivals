#pragma once

#include <SFML/Graphics.hpp>

inline const sf::Event simulateKeypress(sf::Keyboard::Key key)
{
    sf::Event::KeyEvent data;
    data.code = key;

    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key = data;
    return event;
}
