#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed) {
        _level_manager.loadNewLevel();
        _new_map_needed = false;
        _ghosts = _level_manager.getGhosts();
        std::vector<sf::Vector2i> players_positions = _level_manager.getPlayersPositions();
        // create player
    }

    for (int i = 0; i < _ghosts.size(); i++) {
        _ghosts[i].get()->update(dt_as_seconds);
    }
}
