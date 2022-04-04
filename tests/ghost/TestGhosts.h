#pragma once

#include <utility>

#include "../../src/characters/ghosts/Ghost.h"
#include "../../src/characters/ghosts/LinearGhost.h"
#include "../../src/characters/ghosts/CycleGhost.h"
#include "../../src/characters/ghosts/RandomGhost.h"

class TestLinearGhost : public LinearGhost {

public:

    TestLinearGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) : LinearGhost(std::move(map), start_tile_x, start_tile_y, direction) {
        _speed = 10;
    }

    void test_moveForward(float dt_as_seconds) {
        moveForward(dt_as_seconds);
    }

    sf::Vector2i test_getNextTile(sf::Vector2i tile) {
        return getNextTile(tile);
    }

    Character::Direction test_getOppositeDirection() {
        return getOppositeDirection();
    }

    sf::Vector2i test_getUpTile() {
        return getUpTile();
    }

    sf::Vector2i test_getDownTile() {
        return getDownTile();
    }

    sf::Vector2i test_getLeftTile() {
        return getLeftTile();
    }

    sf::Vector2i test_getRightTile() {
        return getRightTile();
    }
};

class TestCycleGhost : public CycleGhost {

public:

    TestCycleGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, std::vector<int> directions) : CycleGhost(std::move(map), start_tile_x, start_tile_y, std::move(directions)) {
        _speed = 10;
    }

    void test_moveForward(float dt_as_seconds) {
        moveForward(dt_as_seconds);
    }

    sf::Vector2i test_getNextTile(sf::Vector2i tile) {
        return getNextTile(tile);
    }

    Character::Direction test_getOppositeDirection() {
        return getOppositeDirection();
    }

    sf::Vector2i test_getUpTile() {
        return getUpTile();
    }

    sf::Vector2i test_getDownTile() {
        return getDownTile();
    }

    sf::Vector2i test_getLeftTile() {
        return getLeftTile();
    }

    sf::Vector2i test_getRightTile() {
        return getRightTile();
    }
};

class TestRandomGhost : public RandomGhost {

public:

    TestRandomGhost(std::shared_ptr<Map> map, int start_tile_x, int start_tile_y, int direction) : RandomGhost(std::move(map), start_tile_x, start_tile_y, direction) {
        _speed = 10;
    }

    void test_moveForward(float dt_as_seconds) {
        moveForward(dt_as_seconds);
    }

    sf::Vector2i test_getNextTile(sf::Vector2i tile) {
        return getNextTile(tile);
    }

    Character::Direction test_getOppositeDirection() {
        return getOppositeDirection();
    }

    sf::Vector2i test_getUpTile() {
        return getUpTile();
    }

    sf::Vector2i test_getDownTile() {
        return getDownTile();
    }

    sf::Vector2i test_getLeftTile() {
        return getLeftTile();
    }

    sf::Vector2i test_getRightTile() {
        return getRightTile();
    }
};
