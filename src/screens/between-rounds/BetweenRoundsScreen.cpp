#include "BetweenRoundsScreen.h"
#include "../../sound-manager/SoundManager.h"

#include <iostream>

BetweenRoundsScreen::BetweenRoundsScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));
}

void BetweenRoundsScreen::initialise(const std::vector<PlayerInfo> & player_infos) {
    size_t players_num = player_infos.size();
    std::vector<int> positions(players_num, -1);
    for (size_t place = 0; place < players_num; place++) {
        unsigned int best_score = 0;
        unsigned int best_player = 0;
        for (size_t i = 0; i < players_num; i++) {
            if (positions[i] == -1 && player_infos[i].getRoundsWon() >= best_score) {
                best_score = player_infos[i].getRoundsWon();
                best_player = i;
            }
        }
        positions[best_player] = place;
    }

    _score_printers.clear();
    for (size_t i = 0; i < players_num; i++) {
        _score_printers.emplace_back(player_infos[i], positions[i], &_view);
    }

    SoundManager::stopChomp();
}

void BetweenRoundsScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                *_current_screen = MENU;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = GAME;
            }
        }
    }
}

void BetweenRoundsScreen::update(float dt_as_seconds) {}

void BetweenRoundsScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    for (ScorePrinter & printer : _score_printers) {
        printer.draw(_window);
    }

    _window->display();
}
