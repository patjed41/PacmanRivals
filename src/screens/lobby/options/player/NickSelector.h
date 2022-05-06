#pragma once

#include <string>

#include "../Selector.h"

class NickSelector : Selector {

private:

    unsigned int _player;

    std::string _current_nick;

public:

    NickSelector() = default;

    NickSelector(sf::RenderWindow* window, unsigned int _player);

    void input(const sf::Event &event) override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentNick() const;

};
