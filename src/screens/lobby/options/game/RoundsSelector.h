#pragma once

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"
#include "../../../../../include/game_constants.h"

class RoundsSelector : Selector {

private:

    unsigned int _current_rounds = 5;

    sf::Text _number;

    sf::Text _info;

    sf::Font _font;

    sf::Sprite _border;

public:

    ButtonAD _A;

    ButtonAD _D;

    RoundsSelector() = default;

    RoundsSelector(sf::RenderWindow* window);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    unsigned int getCurrentRounds() const;

};
