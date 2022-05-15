#pragma once

#include <SFML/Graphics.hpp>

#include "../../../include/game_constants.h"
#include "../Character.h"
#include "../../power-ups/PowerUpName.h"
#include "../../power-ups/types/firing-bullet/Bullet.h"

class Pacman : public Character {

private:

    bool _is_dead;

    static const float _POWER_UP_DURATION; // in seconds
    float _power_up_seconds_left = -1.f;
    float _slow_down_seconds_left = -1.f;
    PowerUpName _current_power_up = NONE;

    void handleMovement(float dt_as_seconds);

    void handlePowerUpExpiry();

protected:

    Direction _new_direction;

    bool turningBack() const;

public:

    Pacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y);

    void changeColor(const std::string & color);

    void update(float dt_as_seconds) override;

    void turnLeft();

    void turnRight();

    void turnUp();

    void turnDown();

    void takeDamage();

    bool isDead() const;

    float getPartOfPowerUpTimeLeft() const;

    PowerUpName getCurrentPowerUp() const;

    bool hasUsablePowerUp() const;

    void pickUpBullet();

    std::shared_ptr<Bullet> fireBullet(unsigned int shooter);

};

