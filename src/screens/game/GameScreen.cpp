#include "GameScreen.h"
#include "../../../include/math.h"

#include <utility>
#include <cmath>

GameScreen::GameScreen(sf::RenderWindow* window, ScreenName* current_screen) : Screen(window, current_screen) {
    _main_view.reset(sf::FloatRect(0, 0, (float)sf::VideoMode::getDesktopMode().width,
                              (float)sf::VideoMode::getDesktopMode().height));
    _main_view.setCenter(MAP_WIDTH * TILE_SIZE / 2.f, MAP_HEIGHT * TILE_SIZE / 2.f);

    _level_manager = LevelManager();
    _power_up_spawner = PowerUpSpawner();
}

void GameScreen::initialise(std::vector<PlayerInfo> player_infos, unsigned int rounds) {
    _new_map_needed = true;
    _player_infos = std::move(player_infos);
    _players_num = _player_infos.size();
    _rounds_left = rounds;
    _level_manager.initialise();
    _player_stats.clear();
    for (int i = 0; i < _players_num; i++) {
        _player_stats.emplace_back(&_player_infos[i], i);
    }
}

unsigned int GameScreen::alivePlayers() const {
    unsigned int result = 0;

    for (auto & pacman : _pacmans) {
        if (!pacman->isDead()) {
             result++;
        }
    }

    return result;
}

bool GameScreen::someoneWinsByPoints() {
    for (size_t i = 0; i < _players_num; i++) {
        if ((_players_num == 4 && _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_4) ||
            (_players_num == 3 && _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_3) ||
            _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_2) {
            return true;
        }
    }

    return false;
}

void GameScreen::rewardWinner() {
    if (someoneWinsByPoints()) {
        for (size_t i = 0; i < _players_num; i++) {
            if ((_players_num == 4 && _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_4) ||
                (_players_num == 3 && _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_3) ||
                _player_infos[i].getRoundPoints() >= POINTS_TO_WIN_2) {
                _player_infos[i].newWin();
            }
        }
    }
    else {
        for (size_t i = 0; i < _players_num; i++) {
            if (!_pacmans[i]->isDead()) {
                _player_infos[i].newWin();
            }
        }
    }
}

void GameScreen::input() {
    if (_new_map_needed) {
        return;
    }

    sf::Event event;

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                // pause
            }
        }
    }

    for (size_t i = 0; i < _players_num; i++) {
        _player_input_handlers[i].input();
        if (_player_input_handlers[i].getPowerUpToUse() == FIRING_BULLET) {
            _bullets.insert(_pacmans[i]->fireBullet(i));
        }
        else if (_player_input_handlers[i].getPowerUpToUse() == BOMB_PLACEMENT) {
            _bombs.insert(_pacmans[i]->placeBomb(i));
        }
        else if (_player_input_handlers[i].getPowerUpToUse() == SPIKES_PLACEMENT) {
            _spikes.insert(_pacmans[i]->placeSpike(i));
        }
    }
}

void GameScreen::loadNewMap() {
    _level_manager.loadNewLevel();

    _grid = _level_manager.getGrid();
    _pacmans = _level_manager.getPlayers();
    _pacmans.resize(_players_num); // delete excess of Pacmans
    _player_input_handlers.clear();
    for (size_t i = 0; i < _players_num; i++) {
        _player_input_handlers.emplace_back(_pacmans[i], _player_infos[i].getControl());
        _pacmans[i]->changeColor(_player_infos[i].getColor());
    }
    _ghosts = _level_manager.getGhosts();

    for (auto & info : _player_infos) {
        info.nextRound();
    }

    _power_up_spawner.initialise(_grid);
    _power_ups.clear();
    _bullets.clear();
    _bombs.clear();
    _spikes.clear();

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (!_grid->getTiles()[y][x].isWall())
                _coins[y * MAP_WIDTH + x] = Coin(float(x) * TILE_SIZE, float(y) * TILE_SIZE);
        }
    }

    _rounds_left--;
}

void GameScreen::handleCollisionsPP() {
    if (alivePlayers() == 1) {
        _new_map_needed = true;
        return;
    }

    for (size_t i = 0; i < _players_num; i++) {
        for (size_t j = 0; j < _players_num; j++) {
            if (i != j && !_pacmans[i]->isDead() && !_pacmans[j]->isDead()
                && _pacmans[i]->getCurrentPowerUp() == GLUTTONY
                && _pacmans[j]->getCurrentPowerUp() != GLUTTONY
                && _pacmans[i]->getPosition().intersects(_pacmans[j]->getPosition())) {
                _pacmans[j]->takeDamage();
                if (_pacmans[j]->isDead()) {
                    _player_infos[i].addRoundPoints(PACMAN_KILL_POINTS);
                    if (alivePlayers() == 1 || someoneWinsByPoints()) {
                        _new_map_needed = true;
                        return;
                    }
                }
            }
        }
    }
}

void GameScreen::handleCollisionsPC() {
    if (_new_map_needed) {
        return;
    }

    for (size_t i = 0; i < _players_num; i++) {
        if (_pacmans[i]->isDead()) {
            continue;
        }

        sf::Vector2i pacman_tile;
        pacman_tile.x = int(_pacmans[i]->getPosition().left / TILE_SIZE);
        pacman_tile.y = int(_pacmans[i]->getPosition().top / TILE_SIZE);

        for (int x = pacman_tile.x - 1; x <= pacman_tile.x + 1; x++) {
            for (int y = pacman_tile.y - 1; y <= pacman_tile.y + 1; y++) {
                if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
                    if (!_grid->getTiles()[y][x].isWall() && !_coins[y * MAP_WIDTH + x].isTaken()
                        && _pacmans[i]->getPosition().intersects(_coins[y * MAP_WIDTH + x].getPosition())) {
                        _coins[y * MAP_WIDTH + x].Take();
                        if (_pacmans[i]->getCurrentPowerUp() == COIN_MULTIPLIER){
                            _player_infos[i].addRoundPoints(2);
                        }
                        else {
                            _player_infos[i].addRoundPoints(1);
                        }
                        if (someoneWinsByPoints()) {
                            _new_map_needed = true;
                        }
                    }
                }
            }
        }
    }
}

void GameScreen::handleCollisionsPG() {
    if (_new_map_needed) {
        return;
    }

    for (size_t i = 0; i < _players_num; i++) {
        for (size_t j = 0; j < _ghosts.size(); j++) {
            if (!_pacmans[i]->isDead() && manhattanDistance(_pacmans[i]->getCenter(), _ghosts[j]->getCenter()) < TILE_SIZE) {
                if (_pacmans[i]->getCurrentPowerUp() == GLUTTONY) {
                    std::swap(_ghosts[j], _ghosts.back());
                    _ghosts.pop_back();
                    j--;
                    _player_infos[i].addRoundPoints(GHOST_KILL_POINTS);
                }
                else {
                    _pacmans[i]->takeDamage();
                }

                if (alivePlayers() == 1 || someoneWinsByPoints()) {
                    _new_map_needed = true;
                    return;
                }
            }
        }
    }
}

void GameScreen::handleCollisionsPPU() {
    if (_new_map_needed) {
        return;
    }

    for (auto it = _power_ups.begin(); it != _power_ups.end(); it++) {
        for (unsigned int i = 0; i < _pacmans.size(); i++) {
            if (!_pacmans[i]->isDead() && _pacmans[i]->getPosition().intersects((*it)->getPosition())) {
                (*it)->use(_pacmans, i);
                _power_ups.erase(*it);
                handleCollisionsPPU();
                return;
            }
        }
    }
}

void GameScreen::handleCollisionsBullets() {
    if (_new_map_needed) {
        return;
    }

    // Bullet hits pacman.
    for (size_t i = 0; i < _players_num; i++) {
        for (auto & bullet : _bullets) {
            if (!_pacmans[i]->isDead() && !bullet->disappeared()
                && _pacmans[i]->getPosition().intersects(bullet->getPosition())) {
                _pacmans[i]->takeDamage();
                bullet->disappear();
                if (_pacmans[i]->isDead()) {
                    _player_infos[bullet->getShooter()].addRoundPoints(PACMAN_KILL_POINTS);
                    if (alivePlayers() == 1 || someoneWinsByPoints()) {
                        _new_map_needed = true;
                        return;
                    }
                }
            }
        }
    }

    // Bullet hits ghost.
    for (size_t i = 0; i < _ghosts.size(); i++) {
        for (auto & bullet : _bullets) {
            if (!bullet->disappeared() && _ghosts[i]->getPosition().intersects(bullet->getPosition())) {
                // delete ghost
                std::swap(_ghosts[i], _ghosts.back());
                _ghosts.pop_back();
                bullet->disappear();
                _player_infos[bullet->getShooter()].addRoundPoints(GHOST_KILL_POINTS);
                if (someoneWinsByPoints()) {
                    _new_map_needed = true;
                    return;
                }
                break;
            }
        }
    }

    // Bullet hits another bullet.
    for (auto it1 = _bullets.begin(); it1 != _bullets.end(); it1++) {
        for (auto it2 = _bullets.begin(); it2 != _bullets.end(); it2++) {
            if (it1 != it2 && !(*it1)->disappeared() && !(*it2)->disappeared()
                && (*it1)->getPosition().intersects((*it2)->getPosition())) {
                (*it1)->disappear();
                (*it2)->disappear();
            }
        }
    }
}

void GameScreen::handleCollisionsBombs() {
    if (_new_map_needed) {
        return;
    }

    for (auto & bomb : _bombs) {
        if (bomb->timeToExplode()) {
            bomb->explode();

            // explosion reaches ghost
            for (size_t i = 0; i < _ghosts.size(); i++) {
                if (bomb->explosionReaches(_ghosts[i]->getPosition())) {
                    std::swap(_ghosts[i], _ghosts.back());
                    _ghosts.pop_back();
                    i--;
                    _player_infos[bomb->getBomberman()].addRoundPoints(GHOST_KILL_POINTS);
                    if (someoneWinsByPoints()) {
                        _new_map_needed = true;
                        return;
                    }
                }
            }

            // explosion reaches pacman
            for (size_t i = 0; i < _players_num; i++) {
                if (!_pacmans[i]->isDead() && bomb->explosionReaches(_pacmans[i]->getPosition())) {
                    _pacmans[i]->takeDamage();
                    if (_pacmans[i]->isDead() && i != bomb->getBomberman()) {
                        _player_infos[bomb->getBomberman()].addRoundPoints(PACMAN_KILL_POINTS);
                    }
                    if (alivePlayers() == 1 || someoneWinsByPoints()) {
                        _new_map_needed = true;
                        return;
                    }
                }
            }
        }
    }
}

void GameScreen::handleCollisionsSpikes() {
    if (_new_map_needed) {
        return;
    }

    // Spike hits pacman.
    for (int i = 0; i < _players_num; ++i) {
        auto pacman = _pacmans[i];
        for (auto & spike : _spikes) {
            if ((i != spike->getUser() || !pacman->hasTimeout()) && !pacman->isDead() && !spike->disappeared()
                && pacman->getPosition().intersects(spike->getPosition())) {
                pacman->takeDamage();
                spike->disappear();
                if (pacman->isDead() && i != spike->getUser()) {
                    _player_infos[spike->getUser()].addRoundPoints(PACMAN_KILL_POINTS);
                }
                if (alivePlayers() == 1 || someoneWinsByPoints()) {
                    _new_map_needed = true;
                    return;
                }
            }
        }
    }

    // Spike hits ghost.
    for (size_t i = 0; i < _ghosts.size(); i++) {
        for (auto & spike : _spikes) {
            if (!spike->disappeared() && _ghosts[i]->getPosition().intersects(spike->getPosition())) {
                // delete ghost
                std::swap(_ghosts[i], _ghosts.back());
                _ghosts.pop_back();
                spike->disappear();
                _player_infos[spike->getUser()].addRoundPoints(GHOST_KILL_POINTS);
                if (someoneWinsByPoints()) {
                    _new_map_needed = true;
                    return;
                }
                break;
            }
        }
    }
}

void GameScreen::update(float dt_as_seconds) {
    if (_new_map_needed) {
        loadNewMap();
        _new_map_needed = false;
    }

    for (auto & pacman : _pacmans) {
        pacman->update(dt_as_seconds);
    }

    for (auto & ghost : _ghosts) {
        ghost->update(dt_as_seconds);
    }

    for (auto & bullet : _bullets) {
        bullet->update(dt_as_seconds);
    }

    for (auto & bomb : _bombs) {
        bomb->update(dt_as_seconds);
    }

    for (auto & spike : _spikes) {
        spike->update(dt_as_seconds);
    }

    _power_up_spawner.update(dt_as_seconds);
    if (_power_up_spawner.timeToSpawn()) {
        std::shared_ptr<PowerUp> new_power_up = _power_up_spawner.spawn(_pacmans, _power_ups);
        if (new_power_up != nullptr) {
            _power_ups.insert(new_power_up);
        }
    }

    handleCollisionsPP();
    handleCollisionsPC();
    handleCollisionsPG();
    handleCollisionsPPU();
    handleCollisionsBullets();
    handleCollisionsBombs();
    handleCollisionsSpikes();

    for (int i = 0; i < _players_num; i++) {
        _player_infos[i].setPowerUpTimeLeft(_pacmans[i]->getPartOfPowerUpTimeLeft());
        _player_infos[i].setPowerUp(_pacmans[i]->getCurrentPowerUp());
    }

    for (auto & stat : _player_stats) {
        stat.update();
    }

    if (_new_map_needed) {
        rewardWinner();
        if (_rounds_left == 0) {
            *_current_screen = GAME_OVER;
        }
        else {
            *_current_screen = BETWEEN_ROUNDS;
        }
    }
}

void GameScreen::draw() {
    if (_new_map_needed) {
        return;
    }

    _window->clear(sf::Color::Black);
    _window->setView(_main_view);

    std::vector<std::vector<Tile>> map = _grid->getTiles();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if(!map[i][j].isWall())
                _window->draw(map[i][j].getSprite());
            int position = i * MAP_WIDTH + j;
            if (_coins.find(position) != _coins.end()) {
                if (!_coins[position].isTaken())
                    _window->draw(_coins[position].getSprite());
            }
        }
    }

    for (int i = 0; i < _players_num; i++) {
        if (_pacmans[i]->isDead()) {
            _player_stats[i].drawDead(_window);
        }
        else {
            _player_stats[i].drawAlive(_window);
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

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j].isWall())
                _window->draw(map[i][j].getSprite());
        }
    }

    for (auto & power_up : _power_ups) {
        _window->draw(power_up->getSprite());
    }

    for (auto & bullet : _bullets) {
        if (!bullet->disappeared()) {
            _window->draw(bullet->getSprite());
        }
    }

    for (auto & bomb : _bombs) {
        bomb->draw(_window);
    }

    for (auto & spike : _spikes) {
        if (!spike->disappeared()) {
            _window->draw(spike->getSprite());
        }
    }

    _window->display();
}

const std::vector<PlayerInfo> & GameScreen::getPlayerInfos() {
    return _player_infos;
}
