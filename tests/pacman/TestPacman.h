#pragma once

#include <SFML/Graphics.hpp>

#include "../../src/characters/player/Pacman.h"
#include "../../src/power-ups/PowerUp.h"

class TestPacman : public Pacman {

public:

    Direction test_new_direction() {
        return _new_direction;
    }

    bool test_turningBack() {
        return turningBack();
    }

    void test_move(float dt_as_seconds) {
        move(dt_as_seconds);
    }

    sf::Vector2i test_positionOfTileInNewDirection(sf::Vector2i new_tile) {
        return positionOfTileInNewDirection(new_tile, _new_direction);
    }

    sf::Vector2i test_positionOfNewTile(sf::Vector2i tile) {
        return positionOfNewTile(tile);
    }

    TestPacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y) : Pacman(map, start_tile_x, start_tile_y) {
        _speed = 10;
    }

    void test_update(float dt_as_seconds) {
        update(dt_as_seconds);
    }

    void turnL() {
        turnLeft();
    }

    void turnR() {
        turnRight();
    }

    void turnU() {
        turnUp();
    }

    void turnD() {
        turnDown();
    }

    void dirL() {
        _direction = LEFT;
    }

    void dirR() {
        _direction = RIGHT;
    }

    void dirU() {
        _direction = UP;
    }

    void dirD() {
        _direction = DOWN;
    }

    float getSpeed() {
        return _speed;
    }

};

