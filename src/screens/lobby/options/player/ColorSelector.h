#pragma once

#include <string>

#include "../Selector.h"

class ColorSelector : Selector {

private:

    std::string _current_color;

public:

    ColorSelector() = default;

    ColorSelector(sf::RenderWindow* window);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

    std::string getCurrentColor() const;

};
