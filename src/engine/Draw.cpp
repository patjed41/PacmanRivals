#include "GameEngine.h"
#include "../characters/ghosts/Ghost.h"

void GameEngine::draw() {
    _window.clear(sf::Color::Black);
    _window.setView(_main_view);
    // draw
    std::vector<std::vector<Tile>> map = _level_manager.getGrid()->getTiles();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            _window.draw(map[i][j].getSprite());
        }
    }

    std::vector<std::shared_ptr<Ghost>> ghosts = _level_manager.getGhosts();

    for (int i = 0; i < ghosts.size(); i++) {
        _window.draw((ghosts[i].get())->getSprite());
    }

    _window.display();
}
