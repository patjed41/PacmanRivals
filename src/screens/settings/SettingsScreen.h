#pragma once

#include <SFML/Graphics.hpp>

#include "../Screen.h"

class SettingsScreen : Screen {

    sf::View _view;

    sf::Font _font;

    sf::Text _settings_text;
    sf::Text _sounds_text;
    sf::Text _music_text;

    sf::Sprite _sounds_slider;
    sf::Sprite _music_slider;

    sf::Sprite _sounds_slider_handle;
    sf::Sprite _music_slider_handle;

    unsigned int _option;

public:

    SettingsScreen() = default;

    SettingsScreen(sf::RenderWindow* window, ScreenName* current_screen);

    void initialise();

    void input() override;

    void update(float dt_as_seconds) override;

    void draw() override;

};
