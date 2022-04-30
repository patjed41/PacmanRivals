#include "GameEngine.h"

void GameEngine::input() {
    switch (_current_screen) {
        case MENU:
            _menu.input();
            return;
        case LOBBY:
            _lobby.input();
            return;
        case GAME:
            _game.input();
            return;
        default:
            return;
    }
}

