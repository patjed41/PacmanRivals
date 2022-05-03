#pragma once

#include "../Selector.h"

class PlayersSelector : Selector {

private:

    unsigned int _current_players = 2;

public:

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

    unsigned int getCurrentPlayers() const;

};
