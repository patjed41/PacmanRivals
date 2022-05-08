#include "LobbyScreen.h"

#include <iostream>
unsigned int LobbyScreen::OPTIONS_NUM = 3; // number of players + 1
const float LobbyScreen::SPACE_BETWEEN = 180.f;

LobbyScreen::LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in LobbyScreen constructor.\n";
        exit(1);
    }

    _nicknames_info.setFont(_font);
    _nicknames_info.setString("nicknames");
    _nicknames_info.setFillColor(sf::Color::Yellow);
    _nicknames_info.setCharacterSize(50);
    _nicknames_info.setPosition(205, 290);

    _colors_info.setFont(_font);
    _colors_info.setString("colors");
    _colors_info.setFillColor(sf::Color::Yellow);
    _colors_info.setCharacterSize(50);
    _colors_info.setPosition(875, 290);

    _controls_info.setFont(_font);
    _controls_info.setString("controls");
    _controls_info.setFillColor(sf::Color::Yellow);
    _controls_info.setCharacterSize(50);
    _controls_info.setPosition(1425, 290);

    _current_options = 0;

    _player_numbers = std::vector<sf::Text>(4);
    _player_numbers[0].setString("P1");
    _player_numbers[1].setString("P2");
    _player_numbers[2].setString("P3");
    _player_numbers[3].setString("P4");

    float option_offset = 230 + SPACE_BETWEEN;
    for (int i = 0; i < 4; i++) {
        _player_numbers[i].setFont(_font);
        _player_numbers[i].setCharacterSize(40);
        _player_numbers[i].setFillColor(sf::Color::Yellow);

        _player_numbers[i].setPosition(20, option_offset);
        option_offset += SPACE_BETWEEN;
    }
}

void LobbyScreen::initialise() {
    ControlSelector::clearState();
    ColorSelector::clearState();
    _current_options = 0;
    _player_options.clear();
    _game_options = GameOptions(_window);
    // 2 players are default
    _player_options.emplace_back(1, _window);
    _player_options.emplace_back(2, _window);
}

void LobbyScreen::input() {
    sf::Event event{};

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            OPTIONS_NUM = _game_options.getNumberOfPlayers() + 1;
            for (int i = 0; i < OPTIONS_NUM - 1; i++) {
                _player_numbers[i].setFillColor(sf::Color::Yellow);
                _player_numbers[i].setFont(_font);
                _window->draw(_player_numbers[i]);
            }
            if (event.key.code == sf::Keyboard::Key::Escape) {
                *_current_screen = MENU;
            }

            if (event.key.code == sf::Keyboard::Key::Return) {
                *_current_screen = GAME;
            }

            if (event.key.code == sf::Keyboard::Key::Down) {
                _current_options = (_current_options + OPTIONS_NUM + 1) % OPTIONS_NUM;
            }

            if (event.key.code == sf::Keyboard::Key::Up) {
                _current_options = (_current_options + OPTIONS_NUM - 1) % OPTIONS_NUM;
            }
        }
        if (_current_options == 0) {
            _game_options.input(event);

            if (_game_options.getNumberOfPlayers() > _player_options.size()) {
                _player_options.emplace_back(_game_options.getNumberOfPlayers(), _window);
            }
            else if (_game_options.getNumberOfPlayers() < _player_options.size()) {
                _player_options.back().freeOptions();
                _player_options.pop_back();
            }
        }
        for (int i = 1; i <= _game_options.getNumberOfPlayers(); i++) {
            if (_current_options == i) {
                _player_options[i - 1].input(event);
            }
        }
    }
}

void LobbyScreen::update(float dt_as_seconds) {
    _game_options.update(dt_as_seconds);

    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++){
        _player_options[i].update(dt_as_seconds);
    }
}

void LobbyScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    if (_current_options > 0) {
        _player_numbers[_current_options - 1].setFillColor(sf::Color::Red);
    }

    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++) {
        _player_numbers[i].setFont(_font);
        _window->draw(_player_numbers[i]);
    }

    _nicknames_info.setFont(_font);
    _window->draw(_nicknames_info);
    _colors_info.setFont(_font);
    _window->draw(_colors_info);
    _controls_info.setFont(_font);
    _window->draw(_controls_info);

    _game_options.draw();
    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++){
        _player_options[i].draw();
    }
    _window->display();
}

std::vector<PlayerInfo> LobbyScreen::getPlayerInfos() {
    std::vector<PlayerInfo> PlayersInfo = std::vector<PlayerInfo>(_game_options.getNumberOfPlayers());

    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++){
        PlayersInfo[i] = _player_options[i].getPlayerInfo();
    }

    return PlayersInfo;
}

unsigned int LobbyScreen::getRounds() {
    return _game_options.getNumberOfRounds();
}
