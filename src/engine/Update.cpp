#include "GameEngine.h"
#include "../characters/player/Player.h"

void GameEngine::update(float dt_as_seconds) {
    if (_new_map_needed){
        _level_manager.loadNewLevel();
        _new_map_needed = false;
        
//        std::vector<sf::Vector2i> players_positions = _level_manager.getPlayersPositions();

        // create player
    }
    std::vector<std::shared_ptr<Player>> players = _level_manager.getPlayers();
    for (int i = 0; i < players.size(); ++i) {
        (*players[i].get()).update(dt_as_seconds);
    }
}