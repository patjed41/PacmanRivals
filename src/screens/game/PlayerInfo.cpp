#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(std::string nickname, std::string color, std::string control) :
    _nickname(std::move(nickname)), _color(std::move(color)), _control(std::move(control)) {
    _rounds_won = 0;
    _round_points = 0;
}

std::string PlayerInfo::getNickname() const {
    return _nickname;
}

std::string PlayerInfo::getColor() const {
    return _color;
}

std::string PlayerInfo::getControl() const {
    return _control;
}

void PlayerInfo::newWin() {
    _rounds_won++;
}

unsigned int PlayerInfo::getRoundsWon() const {
    return _rounds_won;
}

unsigned int PlayerInfo::getRoundPoints() const {
    return _round_points;
}

void PlayerInfo::setPowerUpTimeLeft(float power_up_time_left) {
    _power_up_time_left = power_up_time_left;
}

float PlayerInfo::getPowerUpTimeLeft() const {
    return _power_up_time_left;
}

void PlayerInfo::setPowerUp(PowerUpName power_up) {
    _power_up = power_up;
}

PowerUpName PlayerInfo::getPowerUp() const {
    return _power_up;
}
