#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_indeed){
        _level_manager.loadNewLevel();
        
        std::vector<sf::Vector2i> players_positions = _level_manager.getPlayersPositions();
        // create player
    }
}