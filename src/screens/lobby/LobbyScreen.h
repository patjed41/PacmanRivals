#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"

class LobbyScreen : Screen {

private:

    sf::View _view;

    sf::Font _font;

public:

    LobbyScreen() = default;

    LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
