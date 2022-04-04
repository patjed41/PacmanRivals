#pragma once

#include <SFML/Graphics.hpp>

class Coin {

    sf::Sprite _sprite;

    bool _is_taken = false;

public:

    Coin() = default;

    Coin(float tile_x, float tile_y);

    ~Coin() = default;

    void Take();

    bool isTaken();

    sf::Sprite &getSprite();

    sf::FloatRect getPosition();

};
