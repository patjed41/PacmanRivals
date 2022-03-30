#include "../../src/characters/Character.h"

class TestCharacter : public Character {

public:

    TestCharacter(sf::Sprite sprite, std::shared_ptr<Map> map) : Character(sprite, map) {

    }

    void update(float dt_as_seconds) override {
    }

    void correctL() {
        correctLeft();
    }

    void correctR() {
        correctRight();
    }

    void correctU() {
        correctUp();
    }

    void correctD() {
        correctDown();
    }

    void turnL() {
        _direction = LEFT;
    }

    void turnR() {
        _direction = RIGHT;
    }

    void turnU() {
        _direction = UP;
    }

    void turnD() {
        _direction = DOWN;
    }

    bool checkReachedNewTile(float dt_as_seconds) {
        return reachedNewTile(dt_as_seconds);
    }

};

