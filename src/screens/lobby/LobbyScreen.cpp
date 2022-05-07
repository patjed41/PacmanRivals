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
    _current_options = 0;
    _player_options.clear();
    _game_options = GameOptions(_window);
    // 2 players are default
    _player_options.emplace_back(1, _window);
    _player_options.emplace_back(2, _window);
    _player_options.emplace_back(3, _window);
    _player_options.emplace_back(4, _window);
}

void LobbyScreen::input() {
    sf::Event event{};

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            OPTIONS_NUM = _game_options.getNumberOfPlayers()+1;
            for (int i = 0; i < OPTIONS_NUM; i++) {
                _options[i].setFillColor(sf::Color::White);
                _options[i].setFont(_font); // why is it needed? 100 points question
                _window->draw(_options[i]);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                *_current_screen = MENU;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // TODO: check if everything is done and correct
                bool allDone = false;
                if (_game_options.allDone()) {
                    allDone = true;
                    for (auto & _player_option : _player_options){
                        if (!_player_option.allDone()){
                            allDone = false;
                            break;
                        }
                    }
                }
                if (allDone){
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
                std::cerr << "line: " << _current_options << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                _current_options = (_current_options + OPTIONS_NUM - 1) % OPTIONS_NUM;
                std::cerr << "line: " << _current_options << std::endl;
            }
        }
        if (_current_options == 0){
            _game_options.input(event);
        }
        // 2 players are default
        for (int i = 1; i <= _game_options.getNumberOfPlayers(); i++){
            if (_current_options == i){
                _player_options[i-1].input(event);
            }
        }
    }

    // TODO: input() on current option
}

void LobbyScreen::update(float dt_as_seconds) {
    _game_options.update(dt_as_seconds);

    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++){
            _player_options[i].update(dt_as_seconds);
    }
    // TODO: update() on all options
}

void LobbyScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    _options[_current_options].setFillColor(sf::Color::Red);

    for (int i = 0; i < _game_options.getNumberOfPlayers()+1; i++) {
        _options[i].setFont(_font); // why is it needed? 100 points question
        _window->draw(_options[i]);
    }

    // TODO: draw() on all options
    _game_options.draw();
    for (int i = 0; i < _game_options.getNumberOfPlayers(); i++){
        _player_options[i].draw();
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
