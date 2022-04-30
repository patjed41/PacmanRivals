#include "GameEngine.h"

void GameEngine::update(float dt_as_seconds) {
    switch (_current_screen) {
        case MENU:
            _menu.update(dt_as_seconds);
            return;
        case LOBBY:
            _lobby.update(dt_as_seconds);
            return;
        case GAME:
            _game.update(dt_as_seconds);
            return;
        default:
            return;
    }
}
