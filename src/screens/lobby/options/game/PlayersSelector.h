#pragma once

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"
#include "../../../../../include/game_constants.h"

class PlayersSelector : Selector {

private:

    unsigned int _current_players = 2;

    sf::Text _number;

    sf::Text _info;

    sf::Font _font;

    sf::Sprite _border;

    ButtonAD _A;

    ButtonAD _D;

public:

    PlayersSelector() = default;

    PlayersSelector(sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    unsigned int getCurrentPlayers() const;

};
