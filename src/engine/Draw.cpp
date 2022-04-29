#include "GameEngine.h"

void GameEngine::drawGame() {
    _window.clear(sf::Color::Black);
    _window.setView(_main_view);

    std::vector<std::vector<Tile>> map = _level_manager.getGrid()->getTiles();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            _window.draw(map[i][j].getSprite());
            int position = i * MAP_WIDTH + j;
            if (_coins.find(position) != _coins.end()) {
                if (!_coins[position].isTaken())
                    _window.draw(_coins[position].getSprite());
            }
        }
    }

    for (auto & ghost : _ghosts) {
        _window.draw(ghost->getSprite());
    }

    for (auto & pacman : _pacmans) {
        if (!pacman->isDead()) {
            _window.draw(pacman->getSprite());
        }
    }

    _window.display();
}

void GameEngine::draw() {
    switch (_current_screen) {
        case MENU:
            _menu.draw();
            return;
        case GAME:
            drawGame();
            return;
        default:
            return;
    }
}
