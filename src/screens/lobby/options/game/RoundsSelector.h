#pragma once

#include "../Selector.h"

class RoundsSelector : Selector {

private:

    unsigned int _current_rounds = 5;

public:

    RoundsSelector() = default;

    RoundsSelector(sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    unsigned int getCurrentRounds() const;

};
