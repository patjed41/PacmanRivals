#pragma once

#include <string>

#include "../Selector.h"

class ControlSelector : Selector {

private:

    std::string _current_control;

public:

    ControlSelector() = default;

    ControlSelector(sf::RenderWindow* window);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentControl() const;

};
