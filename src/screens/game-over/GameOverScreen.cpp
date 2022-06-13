#include "GameOverScreen.h"
#include "../../sound-manager/SoundManager.h"

#include <iostream>
#include <algorithm>

GameOverScreen::GameOverScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));

    if (!_font.loadFromFile("../assets/fonts/Emulogic-zrEw.ttf")) {
        std::cerr << "Failed to load _font in GameOverScreen constructor.\n";
        exit(1);
    }

    _game_over_text.setString("Game over");
    _game_over_text.setFont(_font);
    _game_over_text.setFillColor(sf::Color::Red);
    _game_over_text.setCharacterSize(100);
    sf::FloatRect game_over_text_bounds = _game_over_text.getGlobalBounds();
    _game_over_text.setOrigin(game_over_text_bounds.width / 2, game_over_text_bounds.height / 2);
    _game_over_text.setPosition(_view.getCenter().x, _game_over_text.getCharacterSize());
}

void GameOverScreen::initialise(const std::vector<PlayerInfo> & player_infos) {
    size_t players_num = player_infos.size();
    unsigned int best_score = 0;
    for (size_t i = 0; i < players_num; i++) {
        best_score = std::max(best_score, player_infos[i].getRoundsWon());
    }

    _winner_printers.clear();
    for (size_t i = 0; i < players_num; i++) {
        if (player_infos[i].getRoundsWon() == best_score) {
            _winner_printers.emplace_back(player_infos[i], _winner_printers.size(), &_view);
        }
    }

    SoundManager::stopChomp();
}

void GameOverScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                *_current_screen = MENU;
            }
        }
    }
}

void GameOverScreen::update(float dt_as_seconds) {}

void GameOverScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_view);

    _game_over_text.setFont(_font);
    _window->draw(_game_over_text);

    for (WinnerPrinter & printer : _winner_printers) {
        printer.draw(_window);
    }

    _window->display();
}
