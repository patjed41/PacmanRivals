#pragma once

#include <string>
#include <utility>

class PlayerInfo {

private:

    // Types of these attributes may change.
    std::string _nickname;
    std::string _color;
    std::string _control;

public:

    PlayerInfo() = default;

    PlayerInfo(std::string nickname, std::string color, std::string control) :
        _nickname(std::move(nickname)), _color(std::move(color)), _control(std::move(control)) {}

    std::string getNickname();

    std::string getColor();

    std::string getControl();

};
