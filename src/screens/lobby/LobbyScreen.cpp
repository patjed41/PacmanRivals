#include "LobbyScreen.h"

#include <iostream>

const unsigned int LobbyScreen::OPTIONS_NUM = 3; //docelowo liczba graczy + 1
const float LobbyScreen::SPACE_BETWEEN =100.f;

LobbyScreen::LobbyScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                                    (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in LobbyScreen constructor.\n";
        exit(1);
    }
    _current_options = 0;
}

void LobbyScreen::initialise() {
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                *_current_screen = MENU;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // TODO: check if everything is done and correct
                if (_game_options.allDone()) {
                    *_current_screen = GAME;
                }
                else {
                    _window->close();
                    // TODO: currently closes the window in case of an error,
                    // maybe we should go back to the MENU window or reset the LOBBY
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                _current_options = (_current_options + OPTIONS_NUM + 1) % OPTIONS_NUM;
                std::cerr << _current_options << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                _current_options = (_current_options + OPTIONS_NUM - 1) % OPTIONS_NUM;
                std::cerr << _current_options << std::endl;
            }
        }
    }
    if (_current_options == 0){
//        std::cerr << "_game_options" << std::endl;
        _game_options.input(event);
    }
    // 2 players are default
    if (_current_options == 1){
//        std::cerr << "_player_options[0]" << std::endl;
        _player_options[0].input(event);
    }
    if (_current_options == 2){
//        std::cerr << "_player_options[1]" << std::endl;
        _player_options[1].input(event);
    }
    // TODO: input() on current option
}

void LobbyScreen::update(float dt_as_seconds) {
    _game_options.update(dt_as_seconds);
    for (auto & _player_option : _player_options){
        _player_option.update(dt_as_seconds);
    }
    // TODO: update() on all options
}

void LobbyScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    // TODO: draw() on all options
    _game_options.draw();
    for (auto & _player_option : _player_options){
        _player_option.draw();
    }
    _window->display();
}

std::vector<PlayerInfo> LobbyScreen::getPlayerInfos() const {
    // TODO: build and return vector containing information about players
    // temporary
    return std::vector<PlayerInfo>(1) = {PlayerInfo("CoolNick1", "lightblue", "WASD"),
                                         PlayerInfo("CoolNick2", "black", "Arrows"),
                                         PlayerInfo("CoolNick3", "pink", "C1"),
                                         PlayerInfo("CoolNick4", "purple", "C2")};
}

unsigned int LobbyScreen::getRounds() {
    // TODO: get information about number of rounds from _game_options and return
//    return _game_options.getNumberOfRounds();
    return 3;
}
