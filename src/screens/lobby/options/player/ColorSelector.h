#pragma once

#include <string>

#include "../Selector.h"

class ColorSelector : Selector {

private:

    std::string _current_color;

public:

    void input() override;

    void update(float dt_as_seconds) override;

    void draw(sf::RenderWindow* window) override;

    std::string getCurrentColor() const;

};
