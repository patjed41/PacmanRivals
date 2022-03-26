#pragma once

#include <SFML/Graphics.hpp>

class GameEngine {

private:

  sf::RenderWindow _window;

  sf::View _main_view; // view used for drawing game (map and characters)

  void input();

  void update(float dt_as_seconds);

  void draw();

public:

  GameEngine();

  void run();

};
