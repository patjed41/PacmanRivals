#pragma once

#include "../Selector.h"


class PlayersSelector : Selector {

private:

    unsigned int _current_players = 2;

public:

    PlayersSelector() = default;

    PlayersSelector(sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    unsigned int getCurrentPlayers() const;

};
