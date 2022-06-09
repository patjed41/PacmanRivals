#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"

class SettingsScreen : Screen {

    sf::View _view;

public:

    SettingsScreen() = default;

    SettingsScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
