#include "../../src/characters/Character.h"

class TestCharacter : public Character {
public:

    TestCharacter(sf::Sprite sprite, std::shared_ptr<Map> map) : Character(sprite, map) {

    }

    void update(float dt_as_seconds) {
    }

    void correctL(){
        correctLeft();
    }

    void correctR(){
        correctRight();
    }

    void correctU(){
        correctUp();
    }

    void correctD(){
        correctDown();
    }
};

