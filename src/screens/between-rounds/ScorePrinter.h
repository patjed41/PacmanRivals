#pragma once

#include <SFML/Graphics.hpp>

#include "../game/PlayerInfo.h"

class ScorePrinter {

private:

    sf::Font _font;

    sf::Text _text;

    sf::Sprite _pacman;

    static const float FIRST_PLACE_POSITION_Y;
    static const float ONE_POSITION_OFFSET;

public:

    ScorePrinter() = default;

    ScorePrinter(const PlayerInfo & player_info, unsigned int place, const sf::View* view);

    void draw(sf::RenderWindow* window);

};
