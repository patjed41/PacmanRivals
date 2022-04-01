#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed){
        _level_manager.loadNewLevel();
        _pacmans = _level_manager.getPlayers();

        _new_map_needed = false;
    }

    for (int i = 0; i < _pacmans.size(); ++i) {
        (*_pacmans[i].get()).update(dt_as_seconds);
    }
}