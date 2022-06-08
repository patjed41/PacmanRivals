#pragma once

#include <SFML/Graphics.hpp>

#include "../../../include/game_constants.h"
#include "../Character.h"
#include "../../power-ups/PowerUpName.h"
#include "../../power-ups/types/firing-bullet/Bullet.h"
#include "../../power-ups/types/spikes-placement/Spike.h"
#include "../../power-ups/types/bomb-placement/Bomb.h"


class Pacman : public Character {

private:

    bool _is_dead;
    static const float _POWER_UP_DURATION; // in seconds

    float _power_up_seconds_left = -1.f;
    float _slow_down_seconds_left = -1.f;
    static const float _SLOW_SPEED;
    static const float _FAST_SPEED;
    int _spikes_to_place = 0;
    float _timeout;

    std::string _color;
    
    std::string _current_direction;

    void handleMovement(float dt_as_seconds);

    void handlePowerUpExpiry();

    void fixPositionAfterWallPassing();

protected:

    bool _pass_wall;

    PowerUpName _current_power_up = NONE;

    Direction _new_direction;

    bool turningBack() const;

    bool _is_shielded;


public:

    Pacman(std::shared_ptr<Map> map, float start_tile_x, float start_tile_y);

    void changeColor(const std::string & color);

    void animate(float dt_as_seconds) override;

    void update(float dt_as_seconds) override;

    void turnLeft();

    void turnRight();

    void turnUp();

    void turnDown();

    void takeDamage();

    bool isDead() const;

    bool hasTimeout() const;

    float getPartOfPowerUpTimeLeft() const;

    PowerUpName getCurrentPowerUp() const;

    bool hasUsablePowerUp() const;

    void speedUp();

    void slowDown();

    void pickUpBullet();

    void setShield();

    std::shared_ptr<Bullet> fireBullet(unsigned int shooter);

    void passWalls();

    void startEating();

    void coinMultiply();

    void pickUpBomb();

    std::shared_ptr<Bomb> placeBomb(unsigned int bomberman);

    void setPosition(float tile_x, float tile_y);

    void pickUpSpikes();

    std::shared_ptr<Spike> placeSpike(unsigned int user);

};

