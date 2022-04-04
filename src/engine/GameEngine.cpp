#include <ctime>

#include "GameEngine.h"

GameEngine::GameEngine() {
    sf::Vector2<unsigned int> resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    _window.create(sf::VideoMode(resolution.x, resolution.y), "Pacman Rivals", sf::Style::Fullscreen);
    _main_view.reset(sf::FloatRect(0, 0, (float)resolution.x, (float)resolution.y));
    _main_view.setCenter(MAP_WIDTH * TILE_SIZE / 2.f, MAP_HEIGHT * TILE_SIZE / 2.f);
}

void GameEngine::run() {
    srand(time(nullptr));
    sf::Clock clock;

    _level_manager = LevelManager();

    _new_map_needed = true;

    while (_window.isOpen()) {
        sf::Time dt = clock.restart();
        float dt_as_seconds = dt.asSeconds();

        input();
        update(dt_as_seconds);
        draw();
    }
}