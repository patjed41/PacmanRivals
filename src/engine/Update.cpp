#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed) {
        _level_manager.loadNewLevel();

        _pacmans = _level_manager.getPlayers();
        _ghosts = _level_manager.getGhosts();

        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (!_level_manager.getGrid()->getTiles()[i][j].isWall())
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
}
