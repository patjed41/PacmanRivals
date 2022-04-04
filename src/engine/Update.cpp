#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed) {
        _level_manager.loadNewLevel();

        _grid = _level_manager.getGrid();
        _pacmans = _level_manager.getPlayers();
        _ghosts = _level_manager.getGhosts();

        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (!_grid->getTiles()[i][j].isWall())
                    _coins[i * MAP_WIDTH + j] = Coin(float(j) * TILE_SIZE, float(i) * TILE_SIZE);
            }
        }

        _new_map_needed = false;
    }

    for (auto & pacman : _pacmans) {
        pacman->update(dt_as_seconds);
    }

    for (auto & ghost : _ghosts) {
        ghost->update(dt_as_seconds);
    }

    for (auto & pacman : _pacmans) {
        sf::Vector2i pacman_tile;
        pacman_tile.x = int(pacman->getPosition().left / TILE_SIZE);
        pacman_tile.y = int(pacman->getPosition().top / TILE_SIZE);

        for (int x = pacman_tile.x - 1; x <= pacman_tile.x + 1; x++) {
            for (int y = pacman_tile.y - 1; y <= pacman_tile.y + 1; y++) {
                if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
                    if (!_grid->getTiles()[y][x].isWall() && !_coins[y * MAP_WIDTH + x].isTaken()
                        && pacman->getPosition().intersects(_coins[y * MAP_WIDTH + x].getPosition())) {
                        _coins[y * MAP_WIDTH + x].Take();
                    }
                }
            }
        }
    }
}
