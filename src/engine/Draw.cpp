#include "GameEngine.h"

void GameEngine::draw() {
  _window.clear(sf::Color::Black);
  _window.setView(_main_view);

  // draw

  _window.display();
}
