#pragma once

#include <SFML/Graphics.hpp>

class GameEngine {
private:

  sf::RenderWindow _window;

  void input();

  void update(float dt_as_seconds);

  void draw();

public:

  GameEngine();

  void run();

};
