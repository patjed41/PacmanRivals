#pragma once

#include <string>
#include <utility>

class PlayerInfo {

private:

    std::string _nickname;
    std::string _color; // 'yellow', 'red', ...
    std::string _control; // 'WASD', 'Arrows', 'C1', 'C2, 'C3', 'C4'

public:

    PlayerInfo() = default;

    PlayerInfo(std::string nickname, std::string color, std::string control) :
        _nickname(std::move(nickname)), _color(std::move(color)), _control(std::move(control)) {}

    std::string getNickname() const;

    std::string getColor() const;

    std::string getControl() const;

};
