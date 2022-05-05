#include "PlayerInfo.h"

PlayerInfo::PlayerInfo(std::string nickname, std::string color, std::string control) :
    _nickname(std::move(nickname)), _color(std::move(color)), _control(std::move(control)) {
    _rounds_won = 0;
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
