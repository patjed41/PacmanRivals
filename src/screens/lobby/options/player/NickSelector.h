#pragma once

#include <string>

#include "../Selector.h"
#include "../../buttons/ButtonAD.h"

class NickSelector : Selector {

private:

    unsigned int _player;

    std::string _current_nick;

    sf::Text _nickname;

    sf::Font _font;

    sf::Sprite _border;

public:

    NickSelector() = default;

    NickSelector(sf::RenderWindow* window, unsigned int player);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentNick() const;

};
