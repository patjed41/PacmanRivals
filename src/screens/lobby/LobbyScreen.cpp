#include "LobbyScreen.h"

#include <iostream>
unsigned int LobbyScreen::OPTIONS_NUM = 3; //docelowo liczba graczy + 1
const float LobbyScreen::SPACE_BETWEEN =220.f;

LobbyScreen::LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in LobbyScreen constructor.\n";
        exit(1);
    }
    _current_options = 0;

    // wersja tmp
    _options = std::vector<sf::Text>(5);
    _options[0].setString("G");
    _options[1].setString("1");
    _options[2].setString("2");
    _options[3].setString("3");
    _options[4].setString("4");

    float option_offset = 130;
    for (int i = 0; i < 5; i++) {
        _options[i].setFont(_font);
        _options[i].setCharacterSize(60);
        _options[i].setFillColor(sf::Color::White);

        _options[i].setPosition(20, option_offset);
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
            for (int i = 0; i < OPTIONS_NUM; i++) {
                _options[i].setFillColor(sf::Color::White);
                _options[i].setFont(_font); // why is it needed? 100 points question
                _window->draw(_options[i]);
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

    _options[_current_options].setFillColor(sf::Color::Red);

    for (int i = 0; i < _game_options.getNumberOfPlayers() + 1; i++) {
        _options[i].setFont(_font);
        _window->draw(_options[i]);
    }

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
