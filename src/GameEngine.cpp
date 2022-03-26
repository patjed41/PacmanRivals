#include "../include/GameEngine.h"

GameEngine::GameEngine() {
  sf::Vector2<unsigned int> resolution;
  resolution.x = sf::VideoMode::getDesktopMode().width;
  resolution.y = sf::VideoMode::getDesktopMode().height;

  _window.create(sf::VideoMode(resolution.x, resolution.y), "Pacman Rivals", sf::Style::Fullscreen);
}

void GameEngine::run() {
  sf::Clock clock;

  while (_window.isOpen()) {
    sf::Time dt = clock.restart();
    float dt_as_seconds = dt.asSeconds();

    input();
    update(dt_as_seconds);
    draw();
  }
}
