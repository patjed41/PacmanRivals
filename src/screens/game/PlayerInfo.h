#pragma once

#include <string>
#include <utility>

#include "../../power-ups/PowerUpName.h"

class PlayerInfo {

private:

    std::string _nickname;
    std::string _color; // 'yellow', 'red', ...
    std::string _control; // 'WASD', 'Arrows', 'C1', 'C2, 'C3', 'C4'

    unsigned int _rounds_won;
    unsigned int _round_points;

    PowerUpName _power_up;
    float _power_up_time_left;

public:

    PlayerInfo() = default;

    PlayerInfo(std::string nickname, std::string color, std::string control);

    std::string getNickname() const;

    std::string getColor() const;

    std::string getControl() const;

    void newWin();

    unsigned int getRoundsWon() const;

    unsigned int getRoundPoints() const;

    void setPowerUpTimeLeft(float power_up_time_left);

    float getPowerUpTimeLeft() const;

    void setPowerUp(PowerUpName power_up);

    PowerUpName getPowerUp() const;

};
