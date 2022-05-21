#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Bomb {

private:

    sf::Sprite _sprite;

    unsigned int _bomberman;

    bool _exploded;

    static const float _SECONDS_TO_EXPLOSION;
    float _seconds_left;

    sf::Text _time_info;

    sf::Font _font;

    std::vector<sf::Sprite> _explosion_sprites;

public:

    Bomb() = default;

    Bomb(sf::Vector2f position, unsigned int bomberman);

    sf::FloatRect getPosition() const;

    unsigned int getBomberman() const;

    bool timeToExplode() const;

    void explode();

    void update(float dt_as_seconds);

    void draw(sf::RenderWindow *window);

    bool explosionReaches(const sf::FloatRect &rect) const;

};

