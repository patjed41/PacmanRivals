#include "GameScreen.h"

GameScreen::GameScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _main_view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));
    _main_view.setCenter(MAP_WIDTH * TILE_SIZE / 2.f, MAP_HEIGHT * TILE_SIZE / 2.f);

    _level_manager = LevelManager();
}

void GameScreen::initialise(std::vector<PlayerInfo> player_infos, unsigned int rounds) {
    _new_map_needed = true;
    _players_num = player_infos.size();
    _rounds_left = rounds;
}

void GameScreen::input() {
    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // pause
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                _pacmans[0].get()->turnLeft();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                _pacmans[0].get()->turnRight();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                _pacmans[0].get()->turnUp();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                _pacmans[0].get()->turnDown();
            }
        }
    }
}

void GameScreen::update(float dt_as_seconds) {
    if (_new_map_needed) {
        _level_manager.loadNewLevel();

        _grid = _level_manager.getGrid();
        _pacmans = _level_manager.getPlayers();
        _pacmans.resize(_players_num); // delete excess of Pacmans
        _ghosts = _level_manager.getGhosts();

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (!_grid->getTiles()[y][x].isWall())
                    _coins[y * MAP_WIDTH + x] = Coin(float(x) * TILE_SIZE, float(y) * TILE_SIZE);
            }
        }

        _new_map_needed = false;
    }

    for (auto & pacman : _pacmans) {
        pacman->update(dt_as_seconds);
    }

    for (auto & ghost : _ghosts) {
        ghost->update(dt_as_seconds);
    }

    // collisions between Pacmans and Coins
    for (auto & pacman : _pacmans) {
        if (pacman->isDead()) {
            continue;
        }

        sf::Vector2i pacman_tile;
        pacman_tile.x = int(pacman->getPosition().left / TILE_SIZE);
        pacman_tile.y = int(pacman->getPosition().top / TILE_SIZE);

        for (int x = pacman_tile.x - 1; x <= pacman_tile.x + 1; x++) {
            for (int y = pacman_tile.y - 1; y <= pacman_tile.y + 1; y++) {
                if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
                    if (!_grid->getTiles()[y][x].isWall() && !_coins[y * MAP_WIDTH + x].isTaken()
                        && pacman->getPosition().intersects(_coins[y * MAP_WIDTH + x].getPosition())) {
                        _coins[y * MAP_WIDTH + x].Take();
                    }
                }
            }
        }
    }

    // collisions between Pacmans and Ghosts
    for (auto & pacman : _pacmans) {
        for (auto & ghost : _ghosts) {
            if (!pacman->isDead() && pacman->getPosition().intersects(ghost->getPosition())) {
                pacman->die();
            }
        }
    }
}

void GameScreen::draw() {
    _window->clear(sf::Color::Black);
    _window->setView(_main_view);

    std::vector<std::vector<Tile>> map = _level_manager.getGrid()->getTiles();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            _window->draw(map[i][j].getSprite());
            int position = i * MAP_WIDTH + j;
            if (_coins.find(position) != _coins.end()) {
                if (!_coins[position].isTaken())
                    _window->draw(_coins[position].getSprite());
            }
        }
    }

    for (auto & ghost : _ghosts) {
        _window->draw(ghost->getSprite());
    }

    for (auto & pacman : _pacmans) {
        if (!pacman->isDead()) {
            _window->draw(pacman->getSprite());
        }
    }

    _window->display();
}
