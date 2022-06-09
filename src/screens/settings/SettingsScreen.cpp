#include "SettingsScreen.h"
#include "../../sound-manager/SoundManager.h"
#include "../../texture-holder/TextureHolder.h"

#include <iostream>

SettingsScreen::SettingsScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in SettingsScreen constructor.\n";
        exit(1);
    }

    _settings_text.setFont(_font);
    _settings_text.setFillColor(sf::Color::White);
    _settings_text.setString("settings");
    _settings_text.setCharacterSize(100);
    _settings_text.setOrigin(_settings_text.getGlobalBounds().width / 2, 0);
    _settings_text.setPosition(_view.getCenter().x, 100);

    _sounds_text.setFont(_font);
    _sounds_text.setFillColor(sf::Color::Yellow);
    _sounds_text.setString("sounds");
    _sounds_text.setCharacterSize(60);
    _sounds_text.setPosition(200, 400);

    _music_text.setFont(_font);
    _music_text.setFillColor(sf::Color::Yellow);
    _music_text.setString("music");
    _music_text.setCharacterSize(60);
    _music_text.setPosition(200, 700);

    _sounds_slider.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider.png"));
    _sounds_slider.setPosition(700, 415);
    _music_slider.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider.png"));
    _music_slider.setPosition(700, 715);

    _sounds_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-yellow.png"));
    _music_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-yellow.png"));

    _option = 0;
}

void SettingsScreen::initialise() {
    _option = 0;
}

void SettingsScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Key::Escape ||
                event.key.code == sf::Keyboard::Key::Return) {
                *_current_screen = MENU;
            }
            else if (event.key.code == sf::Keyboard::Key::Up ||
                     event.key.code == sf::Keyboard::Key::W ||
                     event.key.code == sf::Keyboard::Key::Down ||
                     event.key.code == sf::Keyboard::Key::S) {
                _option = 1 - _option;
            }
            else if (event.key.code == sf::Keyboard::Key::Right ||
                     event.key.code == sf::Keyboard::Key::D) {
                if (_option == 0) {
                    SoundManager::increaseSoundsVolume();
                }
                else {
                    SoundManager::increaseMusicVolume();
                }
            }
            else if (event.key.code == sf::Keyboard::Key::Left ||
                     event.key.code == sf::Keyboard::Key::A) {
                if (_option == 0) {
                    SoundManager::decreaseSoundsVolume();
                }
                else {
                    SoundManager::decreaseMusicVolume();
                }
            }
        }
    }
}

void SettingsScreen::update(float dt_as_seconds) {}

void SettingsScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    _settings_text.setFont(_font);
    _sounds_text.setFont(_font);
    _music_text.setFont(_font);

    _window->draw(_settings_text);
    _window->draw(_sounds_text);
    _window->draw(_music_text);

    if (_option == 0) {
        _sounds_text.setFillColor(sf::Color::Red);
        _music_text.setFillColor(sf::Color::Yellow);
        _sounds_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-red.png"));
        _music_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-yellow.png"));
    }
    else {
        _sounds_text.setFillColor(sf::Color::Yellow);
        _music_text.setFillColor(sf::Color::Red);
        _sounds_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-yellow.png"));
        _music_slider_handle.setTexture(TextureHolder::GetTexture("../assets/graphics/sliders/slider-handle-red.png"));
    }

    _window->draw(_sounds_slider);
    _window->draw(_music_slider);

    _sounds_slider_handle.setPosition(680 + 100 * SoundManager::getSoundsVolume(), 385);
    _music_slider_handle.setPosition(680 + 100 * SoundManager::getMusicVolume(), 685);

    _window->draw(_sounds_slider_handle);
    _window->draw(_music_slider_handle);

    _window->display();
}
