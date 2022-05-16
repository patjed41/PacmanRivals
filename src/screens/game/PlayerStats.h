#pragma once

#include <SFML/Graphics.hpp>

#include "../game/PlayerInfo.h"

class PlayerStats {

private:

    PlayerInfo* _player_info;

    sf::Font _font;

    sf::Text _nickname;
    sf::Text _points;
    sf::Text _status_alive;
    sf::Text _status_dead;

    sf::Sprite _pacman;
    sf::Sprite _power_up;

    sf::RectangleShape _power_up_time;

    float _position_x;
    float _position_y;

    static const float POSITION_OFFSET;

    static const float TIME_BAR_WIDTH;
    static const float TIME_BAR_HEIGHT;

public:

    PlayerStats() = default;

    PlayerStats(PlayerInfo* player_info, unsigned int player_no, const sf::View* view);

    void update();

    void drawAlive(sf::RenderWindow* window);

    void drawDead(sf::RenderWindow* window);

};
