#include "GameEngine.h"

void GameEngine::draw() {
    switch (_current_screen) {
        case MENU:
            _menu.draw();
            return;
        case LOBBY:
            _lobby.draw();
            return;
        case GAME:
            _game.draw();
            return;
        default:
            return;
    }
}
