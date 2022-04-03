#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed){
        _level_manager.loadNewLevel();
        _pacmans = _level_manager.getPlayers();
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if(!_level_manager.getGrid().get()->getTiles()[i][j].isWall())
                    _coins[i * MAP_WIDTH + j] = Coin(float(j) * TILE_SIZE, float(i) * TILE_SIZE);
            }
        }

        _new_map_needed = false;
    }

    for (int i = 0; i < _pacmans.size(); ++i) {
        _pacmans[i].get()->update(dt_as_seconds);
    }
}