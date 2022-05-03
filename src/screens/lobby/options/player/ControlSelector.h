#pragma once

#include <string>

#include "../Selector.h"

class ControlSelector : Selector {

private:

    std::string _current_control;

public:

    void input() override;

    void update(float dt_as_seconds) override;

    void draw(sf::RenderWindow* window) override;

    std::string getCurrentControl() const;

};
