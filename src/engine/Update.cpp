#include "GameEngine.h"

void GameEngine::updateGame(float dt_as_seconds) {
    if (_new_map_needed) {
        _level_manager.loadNewLevel();

        _grid = _level_manager.getGrid();
        _pacmans = _level_manager.getPlayers();
        _pacmans.resize(_players_num); // delete excess of Pacmans
        _ghosts = _level_manager.getGhosts();

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (!_grid->getTiles()[y][x].isWall())
                    _coins[y * MAP_WIDTH + x] = Coin(float(x) * TILE_SIZE, float(y) * TILE_SIZE);
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

    // collisions between Pacmans and Coins
    for (auto & pacman : _pacmans) {
        if (pacman->isDead()) {
            continue;
        }

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

    // collisions between Pacmans and Ghosts
    for (auto & pacman : _pacmans) {
        for (auto & ghost : _ghosts) {
            if (!pacman->isDead() && pacman->getPosition().intersects(ghost->getPosition())) {
                pacman->die();
            }
        }
    }
}

void GameEngine::update(float dt_as_seconds) {
    switch (_current_screen) {
        case MENU:
            _menu.update(dt_as_seconds);
        case GAME:
            updateGame(dt_as_seconds);
            return;
        default:
            return;
    }
}
