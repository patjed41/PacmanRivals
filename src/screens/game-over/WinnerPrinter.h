#pragma once

#include <SFML/Graphics.hpp>

#include "../game/PlayerInfo.h"

class WinnerPrinter {

private:

    sf::Font _font;

    sf::Text _nickname;

    sf::Sprite _pacman;

    sf::Sprite _crown;

    static const float FIRST_PLACE_POSITION_Y;
    static const float ONE_POSITION_OFFSET;

public:

    WinnerPrinter() = default;

    WinnerPrinter(const PlayerInfo & player_info, unsigned int id, const sf::View* view);

    void draw(sf::RenderWindow* window);

};
