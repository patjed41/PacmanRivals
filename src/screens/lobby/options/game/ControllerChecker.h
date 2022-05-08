#pragma once

#include <SFML/Graphics.hpp>

class ControllerChecker {

private:

    sf::RenderWindow* _window;

    sf::Font _font;

    sf::Text _info;

    std::vector<std::string> _controller_name;
    std::vector<sf::Text> _controller_info;
    static const unsigned int CONTROLLERS_NUM;

    std::vector<float> _seconds_since_last_click;
    static const float _SECONDS_OF_CLICK_ANIMATION;

public:

    ControllerChecker() = default;

    ControllerChecker(sf::RenderWindow* window);

    void input();

    void update(float dt_as_seconds);

    void draw();

};
